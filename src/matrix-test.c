#include "vectors.h"
#include "matrix.h"
#include "camera-matrices.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#define row_col(r,c) col_major[(c)*4+(r)]

extern int whole_test_result;
int dummy;

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
	dummy = getline(&read, &size, oo);
	dummy = getline(&read, &size, oo);
	// read matrix
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
			dummy = fscanf(oo, "%f", &output->row_col(r, c));
	// consume rest of input to avoid warning.
	while (!feof(oo)) dummy = getline(&read, &size, oo);
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
	dummy = getline(&read, &size, oo);
	dummy = getline(&read, &size, oo);
	// read matrix
	for (int i = 0; i < 3; ++i) {
		float v;
		dummy = fscanf(oo, "%f", &v);
		set_vec3f_component_val(output, i, v);
	}
	// consume rest of input to avoid warning.
	while (!feof(oo)) dummy = getline(&read, &size, oo);
	pclose(oo);
	free(read);
}

void eval_octave_vector4(char *command, vec4f *output) {
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
	dummy = getline(&read, &size, oo);
	dummy = getline(&read, &size, oo);
	// read matrix
	for (int i = 0; i < 4; ++i) {
		float v;
		dummy = fscanf(oo, "%f", &v);
		set_vec4f_component_val(output, i, v);
	}
	// consume rest of input to avoid warning.
	while (!feof(oo)) dummy = getline(&read, &size, oo);
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
	dummy = fscanf(oo, "%s = %f", cmdline, output);
	// consume rest of input to avoid warning.
	size_t size = 1024;
	char *read = malloc(size);
	while (!feof(oo)) dummy = getline(&read, &size, oo);
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
void print_vec4f(const vec4f *v) {
	printf("(%f %f %f %f)\n", v->x, v->y, v->z, v->w);
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

char* octave_string_of_vec4f(const vec4f *output) {
	char *buffer = 0;
	size_t bs = 0;
	FILE *stream = open_memstream(&buffer, &bs);
	fprintf(stream, "[ %f ; %f ; %f ; %f ]", output->x, output->y, output->z, output->w);
	fclose(stream);
	return buffer;
}

bool silent_matrix_result = false;
bool matrix_test_result(const char *test, const matrix4x4f *we, const matrix4x4f *octave, float epsilon) {
	bool ok = equal_matrices_under_eps4x4f(we, octave, epsilon);
	if (ok) {
		if (!silent_matrix_result) printf("%s: OK.\n", test);
		return true;
	}
	printf("\n%s: FAILED!\n", test);
	printf("we:\n");
	print_matrix(we);
	printf("octave:\n");
	print_matrix(octave);
	printf("\n");
	whole_test_result = -1;
}

void vector_test_result(const char *test, const vec3f *we, const vec3f *octave, float epsilon) {
	bool ok = equal_under_eps_vec3f(we, octave, epsilon);
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
	whole_test_result = -1;
}

void vector4_test_result(const char *test, const vec4f *we, const vec4f *octave, float epsilon) {
	bool ok = equal_under_eps_vec4f(we, octave, epsilon);
	if (ok) {
		printf("%s: OK.\n", test);
		return;
	}
	printf("\n%s: FAILED!\n", test);
	printf("we:\n");
	print_vec4f(we);
	printf("octave:\n");
	print_vec4f(octave);
	printf("\n");
	whole_test_result = -1;
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
	whole_test_result = -1;
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
#define finalize_vector4_test(VEC, EPS) \
		fclose(octave_stream); \
		eval_octave_vector4(octave_buffer, &octave_result); \
		free(octave_buffer); \
		vector4_test_result(test_name, &VEC, &octave_result, EPS);
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
		for (int i = 0; i < 16; ++i) {
			lhs.col_major[i] = rhs.col_major[i] = i+1;
			rhs.col_major[i] += 7;
		}
		multiply_matrices4x4f(&result, &lhs, &rhs);

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

void mv_tests()
{
	char *octave_buffer;
	size_t buffer_size = 0;
	FILE *octave_stream;
	char *test_name;
	vec4f octave_result;

	setup_test("transform1"); {
		vec4f v, res;
		vec3f axis;
		matrix4x4f m;
		make_vec4f(&v, 2, 3, 5, 7);
		for (int i = 0; i < 16; ++i) m.col_major[i] = i+1;
		multiply_matrix4x4f_vec4f(&res, &m, &v);
		fprintf(octave_stream, "v = %s;\n"
		                       "m = %s;\n"
							   "o = m * v\n", octave_string_of_vec4f(&v), octave_string_of_matrix4x4f(&m));
		finalize_vector4_test(res, 0);
	}
	setup_test("transform2"); {
		vec4f v, res;
		vec3f axis;
		matrix4x4f m;
		make_vec4f(&v, 2, 3, 5, 7);
		make_vec3f(&axis, 3, 5, 7);
		div_vec3f_by_scalar(&axis, &axis, length_of_vec3f(&axis));
		make_rotation_matrix4x4f(&m, &axis, 78);
		multiply_matrix4x4f_vec4f(&res, &m, &v);
		fprintf(octave_stream, "v = %s;\n"
		                       "m = %s;\n"
							   "o = m * v\n", octave_string_of_vec4f(&v), octave_string_of_matrix4x4f(&m));
		finalize_vector4_test(res, 0.0001);
	}
}

void cam_test()
{
	char *octave_buffer;
	size_t buffer_size = 0;
	FILE *octave_stream;
	char *test_name;
	matrix4x4f octave_result;

	{
		float fovs[] = { 20, 45, 60 };
		float asps[] = { 3.0/4.0, 1, 1.2 };
		float near[] = { 0.01, 0.1, 1 };
		float fars[] = { 10, 1000, 100000 };
		matrix4x4f m;
		FILE *in = fopen("proj-res", "r");
		matrix4x4f ref;
		silent_matrix_result = true;
		bool all_ok = true;
		int fails = 0;
		for (int fo = 0; fo < 3; ++fo)
			for (int as = 0; as < 3; ++as)
				for (int ne = 0; ne < 3; ++ne)
					for (int fa = 0; fa < 3; ++fa) {
						// read reference matrix
						for (int r = 0; r < 4; ++r)
							for (int c = 0; c < 4; ++c)
								dummy = fscanf(in, "%f", &ref.row_col(r, c));
						// compute our version
						make_projection_matrixf(&m, fovs[fo], asps[as], near[ne], fars[fa]);
						if (!matrix_test_result("", &m, &ref, 0.0001)) {
							fprintf(stderr, "failed for fovy=%f aspect=%f near=%f far=%f\n", fovs[fo], asps[as], near[ne], fars[fa]);
							all_ok = false;
							++fails;
						}
					}
		printf("make-proj-matrix, %d samples: ", 3*3*3*3);
		if (all_ok) printf("OK.\n");
		else printf("FAILED (%d times).\n", fails);
	}
	{
		float rl[] = { 0.1, 1, 2};
		float tb[] = { 0.2, 0.9, 1.9 };
		float nf[] = { 0.1, 1, 2 };
		matrix4x4f m;
		FILE *in = fopen("ortho-res", "r");
		matrix4x4f ref;
		silent_matrix_result = true;
		bool all_ok = true;
		int fails = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				for (int ne = 0; ne < 3; ++ne) {
					// read reference matrix
					for (int r = 0; r < 4; ++r)
						for (int c = 0; c < 4; ++c)
							dummy = fscanf(in, "%f", &ref.row_col(r, c));
					// compute our version
					make_ortographic_matirxf(&m, rl[i], rl[i]/2.0, tb[j], tb[j]/2.0, nf[ne], nf[ne]*100);
					if (!matrix_test_result("", &m, &ref, 0.0001)) {
						fprintf(stderr, "failed for right=%f left=%f top=%f bottom=%f near=%f far=%f\n", 
								rl[i], rl[i]/2.0, tb[j], tb[j]/2.0, nf[ne], nf[ne]*100);
						all_ok = false;
						++fails;
					}
				}
		printf("make-ortho-matrix, %d samples: ", 3*3*3);
		if (all_ok) printf("OK.\n");
		else printf("FAILED (%d times).\n", fails);
	}
	{
		float posx[] = { -3, -1, 0.01, 1, 2};
		float posy[] = { -2.9, -1, 0.1, 1.5};
		float posz[] = { 10, 0, -10};
		float dirx[] = { -1, -0.6, 0, 0.9 };
		float diry[] = { -1, -5, 0.1, 1};
		float dirz[] = { -0.6, -0.1, 5};
		matrix4x4f m;
		matrix4x4f m2;
		FILE *in = fopen("view-res", "r");
		matrix4x4f ref;
		silent_matrix_result = true;
		bool all_ok = true;
		int fails = 0;
		vec3f pos, dir, up;
		for (int px = 0; px < 5; ++px) 
			for (int py = 0; py < 4; ++py)
				for (int pz = 0; pz < 3; ++pz)
					for (int dx = 0; dx < 4; ++dx)
						for (int dy = 0; dy < 4; ++dy)
							for (int dz = 0; dz < 3; ++dz) {
								// read reference matrix
								for (int r = 0; r < 4; ++r)
									for (int c = 0; c < 4; ++c)
										dummy = fscanf(in, "%f", &ref.row_col(r, c));
								
								// compute our lookat-matrix version
								make_vec3f(&pos, posx[px], posy[py], posz[pz]);
								make_vec3f(&dir, dirx[dx], diry[dy], dirz[dz]);
								make_vec3f(&up,  dirz[dz], dirx[dx], diry[dy]);
								make_lookat_matrixf(&m, &pos, &dir, &up);

								if (!matrix_test_result("", &m, &ref, 0.0001)) {
									fprintf(stderr, "failed at lookat somewhere...\n");
									all_ok = false;
									++fails;
									continue;
								}
								
								// read reference matrix
								for (int r = 0; r < 4; ++r)
									for (int c = 0; c < 4; ++c)
										dummy = fscanf(in, "%f", &ref.row_col(r, c));
								
								make_gl_viewing_matrixf(&m2, &m);
								if (!matrix_test_result("", &m2, &ref, 0.0001)) {
									fprintf(stderr, "failed at gl somewhere...\n");
									all_ok = false;
									++fails;
								}
							}
		printf("make-view... & make-gl-view-matrix, %d samples: ", 5*4*3*4*4*3);
		if (all_ok) printf("OK.\n");
		else printf("FAILED (%d times).\n", fails);
	}


}

/*
int main()
{
	vector_tests();
	matrix_tests();
	mv_tests();
	cam_test();
	return 0;
}
*/
