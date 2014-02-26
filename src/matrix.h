/* 
 * Autogenerated by rtgen. Licenced under the terms of the GPL.
 */

#ifndef __CGEN_matrix_H__
#define __CGEN_matrix_H__

#include "vectors.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	float col_major[16];
} matrix4x4f;


typedef struct {
	double col_major[16];
} matrix4x4d;


void transpose_matrix4x4f(matrix4x4f *out, const matrix4x4f *in);
void transpose_matrix4x4d(matrix4x4d *out, const matrix4x4d *in);
void multiply_matrix4x4f_vec4f(vec4f *out, const matrix4x4f *lhs, const vec4f *rhs);
void multiply_matrix4x4d_vec4d(vec4d *out, const matrix4x4d *lhs, const vec4d *rhs);
void multiply_matrices4x4f(matrix4x4f *out, const matrix4x4f *lhs, const matrix4x4f *rhs);
void multiply_matrices4x4d(matrix4x4d *out, const matrix4x4d *lhs, const matrix4x4d *rhs);
void make_unit_matrix4x4f(matrix4x4f *mat);
void make_unit_matrix4x4d(matrix4x4d *mat);
void make_scale_matrix4x4f(matrix4x4f *mat, const vec3f *scale);
void make_scale_matrix4x4d(matrix4x4d *mat, const vec3d *scale);
void make_rotation_matrix4x4f(matrix4x4f *mat, const vec3f *axis, float angle_in_rad);
void make_rotation_matrix4x4d(matrix4x4d *mat, const vec3d *axis, double angle_in_rad);
void invert_matrix4x4f(matrix4x4f *out, const matrix4x4f *in);
void invert_matrix4x4d(matrix4x4d *out, const matrix4x4d *in);
bool equal_matrices_under_eps4x4f(const matrix4x4f *lhs, const matrix4x4f *rhs, float eps);
bool equal_matrices_under_eps4x4d(const matrix4x4d *lhs, const matrix4x4d *rhs, double eps);
float determinant_of_upper3x3_of_matrix4x4f(const matrix4x4f *mat);
double determinant_of_upper3x3_of_matrix4x4d(const matrix4x4d *mat);
void copy_matrix4x4f(matrix4x4f *out, const matrix4x4f *in);
void copy_matrix4x4d(matrix4x4d *out, const matrix4x4d *in);


#ifdef __cplusplus
}


/********************************* OPERATORS FOR MAT4F *********************************/
inline vec4f operator*(const matrix4x4f &lhs, const vec4f &rhs) {
	vec4f out;
	multiply_matrix4x4f_vec4f(&out, &lhs, &rhs);
	
	return out;
}

inline matrix4x4f operator*(const matrix4x4f &lhs, const matrix4x4f &rhs) {
	matrix4x4f out;
	multiply_matrices4x4f(&out, &lhs, &rhs);
	
	return out;
}

inline bool operator==(const matrix4x4f &lhs, const matrix4x4f &rhs) {
	return equal_matrices_under_eps4x4f(&lhs, &rhs, LIBMCM_EPS_FLOAT);
}

inline std::ostream& operator<<(std::ostream &out, const matrix4x4f &mat) {
	const unsigned int dim = 4;
	
	for (unsigned int i = 0; i < dim; ++i) {
		out << "[";
		for (unsigned int j = 0; j < dim; ++j) {
			out << mat.col_major[j * 4 + i];
			if (j < 3) out << "\t";
		}
		out << "]";
		
		if (i < 3) out << std::endl;
	}
	
    return out;
}


/********************************* OPERATORS FOR MAT4D *********************************/
inline vec4d operator*(const matrix4x4d &lhs, const vec4d &rhs) {
	vec4d out;
	multiply_matrix4x4d_vec4d(&out, &lhs, &rhs);
	
	return out;
}

inline matrix4x4d operator*(const matrix4x4d &lhs, const matrix4x4d &rhs) {
	matrix4x4d out;
	multiply_matrices4x4d(&out, &lhs, &rhs);
	
	return out;
}

inline bool operator==(const matrix4x4d &lhs, const matrix4x4d &rhs) {
	return equal_matrices_under_eps4x4d(&lhs, &rhs, LIBMCM_EPS_DOUBLE);
}

inline std::ostream& operator<<(std::ostream &out, const matrix4x4d &mat) {
	const unsigned int dim = 4;
	
	for (unsigned int i = 0; i < dim; ++i) {
		out << "[";
		for (unsigned int j = 0; j < dim; ++j) {
			out << mat.col_major[j * 4 + i] << "\t";
		}
		out << "]" << std::endl;
	}
	
    return out;
}

#endif

#endif
