#include "vectors.h"
#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

void eval_octave(char *command, matrix4x4f *output) {
	static char cmdline[1024];
	snprintf(cmdline, 1024, "octave -q --eval \"%s\"", command);
	errno = 0;
	FILE *oo = popen(cmdline, "r");
	if (errno != 0) {
		perror("fucked.");
		return;
	}
	size_t size = 1024;
	char *read = malloc(size);
	// consume first two lines, they are not relevant here
	getline(&read, &size, oo);
	getline(&read, &size, oo);
	// read matrix
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
			fscanf(oo, "%f", &output->row_col(r, c));
	// consume rest of input to avoid warning.
	while (!feof(oo)) getline(&read, &size, oo);
	pclose(oo);
	free(read);
}

void eval_octave_vector(char *command, vec3f *output) {
	static char cmdline[1024];
	snprintf(cmdline, 1024, "octave -q --eval \"%s\"", command);
	errno = 0;
	FILE *oo = popen(cmdline, "r");
	if (errno != 0) {
		perror("fucked.");
		return;
	}
	size_t size = 1024;
	char *read = malloc(size);
	// consume first two lines, they are not relevant here
	getline(&read, &size, oo);
	getline(&read, &size, oo);
	// read matrix
	for (int i = 0; i < 3; ++i) {
		float v;
		fscanf(oo, "%f", &v);
		float *p = component(output, i);
		*p = v;
	}
	// consume rest of input to avoid warning.
	while (!feof(oo)) getline(&read, &size, oo);
	pclose(oo);
	free(read);
}

void eval_octave_float(char *command, float *output) {
	static char cmdline[1024];
	snprintf(cmdline, 1024, "octave -q --eval \"%s\"", command);
	errno = 0;
	FILE *oo = popen(cmdline, "r");
	if (errno != 0) {
		perror("fucked.");
		return;
	}
	fscanf(oo, "%s = %f", cmdline, output);
	// consume rest of input to avoid warning.
	size_t size = 1024;
	char *read = malloc(size);
	while (!feof(oo)) getline(&read, &size, oo);
	pclose(oo);
	free(read);
}

void print_matrix(const matrix4x4f *output) {
	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c)
			printf("%f\t", output->row_col(r, c));
		printf("\n");
	}
}
void print_vec3f(const vec3f *v) {
	printf("(%f %f %f)\n", v->x, v->y, v->z);
}

char* octave_string_of_matrix4x4f(const matrix4x4f *output) {
	char *buf = 0;
	int required = 0;
	for (int i = 0; i < 2; ++i) {
		required = snprintf(buf, required, "[ %f %f %f %f ; %f %f %f %f ; %f %f %f %f ; %f %f %f %f ]", 
		                    output->row_col(0,0), output->row_col(0,1), output->row_col(0,2), output->row_col(0,3), 
		                    output->row_col(1,0), output->row_col(1,1), output->row_col(1,2), output->row_col(1,3), 
		                    output->row_col(2,0), output->row_col(2,1), output->row_col(2,2), output->row_col(2,3), 
		                    output->row_col(3,0), output->row_col(3,1), output->row_col(3,2), output->row_col(3,3)) + 1;
		if (buf == 0) buf = malloc(required);
	}
	return buf;
}

char* octave_string_of_vec3f(const vec3f *output) {
	char *buffer = 0;
	size_t bs = 0;
	FILE *stream = open_memstream(&buffer, &bs);
	fprintf(stream, "[ %f ; %f ; %f ]", output->x, output->y, output->z);
	fclose(stream);
	return buffer;
}

void matrix_test_result(const char *test, const matrix4x4f *we, const matrix4x4f *octave, float epsilon) {
	bool ok = equal_matrices4x4f_under_eps(we, octave, epsilon);
	if (ok) {
		printf("%s: OK.\n", test);
		return;
	}
	printf("\n%s: FAILED!\n", test);
	printf("we:\n");
	print_matrix(we);
	printf("octave:\n");
	print_matrix(octave);
	printf("\n");
}

void vector_test_result(const char *test, const vec3f *we, const vec3f *octave, float epsilon) {
	bool ok = equal_vec3fs_under_eps(we, octave, epsilon);
	if (ok) {
		printf("%s: OK.\n", test);
		return;
	}
	printf("\n%s: FAILED!\n", test);
	printf("we:\n");
	print_vec3f(we);
	printf("octave:\n");
	print_vec3f(octave);
	printf("\n");
}

void float_test_result(const char *test, float we, float octave, float epsilon) {
	bool ok = (fabs(we - octave) <= epsilon);
	if (ok) {
		printf("%s: OK.\n", test);
		return;
	}
	printf("\n%s: FAILED!\n", test);
	printf("we: %f\n", we);
	printf("octave: %f\n", octave);
	printf("\n");
}


#define setup_test(N) \
		test_name = N; \
		octave_buffer = 0; \
		buffer_size = 0; \
		octave_stream = open_memstream(&octave_buffer, &buffer_size);
#define finalize_matrix_test(MAT, EPS) \
		fclose(octave_stream); \
		eval_octave(octave_buffer, &octave_result); \
		free(octave_buffer); \
		matrix_test_result(test_name, &MAT, &octave_result, EPS);
#define finalize_vector_test(VEC, EPS) \
		fclose(octave_stream); \
		eval_octave_vector(octave_buffer, &octave_result); \
		free(octave_buffer); \
		vector_test_result(test_name, &VEC, &octave_result, EPS);
#define finalize_float_test(FLT, FLT_RES, EPS) \
		fclose(octave_stream); \
		eval_octave_float(octave_buffer, &FLT_RES); \
		free(octave_buffer); \
		float_test_result(test_name, FLT, FLT_RES, EPS);

void matrix_tests() {
	char *octave_buffer;
	size_t buffer_size = 0;
	FILE *octave_stream;
	char *test_name;
	matrix4x4f octave_result;

	// transpose
	setup_test("transpose"); {

		matrix4x4f to_transpose;
		for (int i = 0; i < 16; ++i)
			to_transpose.col_major[i] = i;
		matrix4x4f transposed;
		transpose_matrix4x4f(&transposed, &to_transpose);
	
		fprintf(octave_stream, "to_transpose = %s;\n"
		                       "transposed = transpose(to_transpose)", octave_string_of_matrix4x4f(&to_transpose));
	
		finalize_matrix_test(transposed, 0);
	}

	for (int i = 0; i < 10; ++i) {
		char tn[9];
		snprintf(tn, 9, "inverse%d", i);
		setup_test(tn); {
			matrix4x4f to_invert;
			vec3f axis[4];
			make_vec3f(&axis[0], 1, 0, 0);
			make_vec3f(&axis[1], 0, 1, 0);
			make_vec3f(&axis[2], 0, 0, 1);
			make_vec3f(&axis[3], 1, 0, 0.5);
			make_rotation_matrix4x4f(&to_invert, axis + i%4, i*2*M_PI/10);
			matrix4x4f inverse;
			invert_matrix4x4f(&inverse, &to_invert);
			fprintf(octave_stream, "to_invert = %s;\n"
			                       "inverted = inverse(to_invert)", octave_string_of_matrix4x4f(&to_invert));
			finalize_matrix_test(inverse, 0.0001);
		}
	}

	setup_test("m-mult0"); {
		matrix4x4f lhs, rhs, result;
		for (int i = 0; i < 16; ++i)
			lhs.col_major[i] = rhs.col_major[i] = i;
		multiply_matrix4x4f(&result, &lhs, &rhs);

		fprintf(octave_stream, "lhs = %s;\n"
		                       "rhs = %s;\n"
							   "multi = lhs * rhs", octave_string_of_matrix4x4f(&lhs), octave_string_of_matrix4x4f(&rhs));
		finalize_matrix_test(result, 0);
	}
}

void vector_tests() {
	char *octave_buffer;
	size_t buffer_size = 0;
	FILE *octave_stream;
	char *test_name;
	vec3f octave_result;

	setup_test("dot"); {
		vec3f a, b;
		make_vec3f(&a, 2, 3, 5);
		make_vec3f(&b, 7, 11, 13);
		float res = dot_vec3f(&a, &b);
		fprintf(octave_stream, "a = %s;\n"
		                       "b = %s;\n"
							   "c = dot(a,b)\n", octave_string_of_vec3f(&a), octave_string_of_vec3f(&b));
		float oct = 0;
		finalize_float_test(res, oct, 0);
	}
	setup_test("cross"); {
		vec3f a, b, c;
		make_vec3f(&a, 2, 3, 5);
		make_vec3f(&b, 7, 11, 13);
		cross_vec3f(&c, &a, &b);
		fprintf(octave_stream, "a = %s;\n"
		                       "b = %s;\n"
		                       "c = cross(a,b)\n", octave_string_of_vec3f(&a), octave_string_of_vec3f(&b));
		finalize_vector_test(c, 0);
	}
}
