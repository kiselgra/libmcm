#ifndef __MATRIX_H__ 
#define __MATRIX_H__ 

#include <stdbool.h>

#include "vectors.h"

typedef struct {
	float col_major[16];
} matrix4x4f;

// is this a good macro to be in a header?
#define row_col(r, c) col_major[(c)*4+r]

// constructors
void make_scale_matrix4x4f(matrix4x4f *mat, const vec3f *scale);
void make_rotation_matrix4x4f(matrix4x4f *mat, const vec3f *axis, float angle_in_rad);
void make_unit_matrix4x4f(matrix4x4f *mat);

void copy_matrix4x4f(matrix4x4f *out, const matrix4x4f *in);

float determinant_of_upper3x3_of_matrix4x4f(const matrix4x4f *mat);
void transpose_matrix4x4f(matrix4x4f *out, const matrix4x4f *in);
void invert_matrix4x4f(matrix4x4f *out, const matrix4x4f *in);
void multiply_matrix4x4f(matrix4x4f *out, const matrix4x4f *lhs, const matrix4x4f *rhs);

bool equal_matrices4x4f_under_eps(const matrix4x4f *lhs, const matrix4x4f *rhs, float eps);


#endif

