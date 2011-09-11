#include "matrix.h"

#include <math.h>
#include <stdio.h>

#define at_rc(r,c) mat->row_col(r,c)

void make_unit_matrix4x4f(matrix4x4f *mat) {
	mat->row_col(0,0) = 1;   mat->row_col(0,1) = 0;   mat->row_col(0,2) = 0;   mat->row_col(0,3) = 0;
	mat->row_col(1,0) = 0;   mat->row_col(1,1) = 1;   mat->row_col(1,2) = 0;   mat->row_col(1,3) = 0;
	mat->row_col(2,0) = 0;   mat->row_col(2,1) = 0;   mat->row_col(2,2) = 1;   mat->row_col(2,3) = 0;
	mat->row_col(3,0) = 0;   mat->row_col(3,1) = 0;   mat->row_col(3,2) = 0;   mat->row_col(3,3) = 1;
}

void make_rotation_matrix4x4f(matrix4x4f *mat, const vec3f *axis, float angle_in_rad) {
	float cos_a = cos(angle_in_rad);
	float sin_a = sin(angle_in_rad);
	float v1 = axis->x, v2 = axis->y, v3 = axis->z;
	float v1v2 = v1*v2;
	float v1v3 = v1*v3;
	float v2v3 = v2*v3;

	mat->row_col(0,0) = cos_a + v1*v1 * (1-cos_a);    mat->row_col(0,1) = v1v2 * (1-cos_a) - v3 * sin_a;  mat->row_col(0,2) = v1v3 * (1-cos_a) + v2 * sin_a;
	mat->row_col(1,0) = v1v2 * (1-cos_a) + v3*sin_a;  mat->row_col(1,1) = cos_a + v2*v2 * (1-cos_a);      mat->row_col(1,2) = v2v3 * (1-cos_a) - v1 * sin_a;
	mat->row_col(2,0) = v1v3 * (1-cos_a) - v2*sin_a;  mat->row_col(2,1) = v2v3 * (1-cos_a) + v1*sin_a;    mat->row_col(2,2) = cos_a + v3*v3*(1-cos_a);

	mat->row_col(0,3) = mat->row_col(1,3) = mat->row_col(2,3) = 0;
	mat->row_col(3,0) = mat->row_col(3,1) = mat->row_col(3,2) = 0;
	mat->row_col(3,3) = 1;
}

void make_scale_matrix4x4f(matrix4x4f *mat, const vec3f *scale) {
	mat->row_col(0,0) = scale->x;
	mat->row_col(1,1) = scale->y;
	mat->row_col(2,2) = scale->z;
	mat->row_col(3,3) = 1;
	mat->row_col(0,1) = mat->row_col(0,2) = mat->row_col(0,3) = 0;
	mat->row_col(1,0) = mat->row_col(1,2) = mat->row_col(1,3) = 0;
	mat->row_col(2,0) = mat->row_col(2,1) = mat->row_col(2,3) = 0;
	mat->row_col(3,0) = mat->row_col(3,1) = mat->row_col(3,3) = 0;
}

void copy_matrix4x4f(matrix4x4f *out, const matrix4x4f *in) {
	for (int i = 0; i < 16; ++i)
		out->col_major[i] = in->col_major[i];
}

float determinant_of_upper3x3_of_matrix4x4f(const matrix4x4f *mat) {
	//float pos = mat->row_col(0,0)*mat->row_col(1,1)*mat->row_col(2,2) + 
	float pos = at_rc(0,0)*at_rc(1,1)*at_rc(2,2)  +  at_rc(0,1)*at_rc(1,2)*at_rc(2,0)  +  at_rc(0,2)*at_rc(1,0)*at_rc(2,1);
	float neg = at_rc(0,2)*at_rc(1,1)*at_rc(2,0)  +  at_rc(0,1)*at_rc(1,0)*at_rc(2,2)  +  at_rc(0,0)*at_rc(1,2)*at_rc(2,1);
	return pos - neg;
}

void transpose_matrix4x4f(matrix4x4f *out, const matrix4x4f *in) {
	for (int y = 0; y < 4; ++y)
		for (int x = 0; x < 4; ++x)
			out->row_col(x,y) = in->row_col(y,x);
}

bool equal_matrices4x4f_under_eps(const matrix4x4f *lhs, const matrix4x4f *rhs, float eps) {
	bool b = true;
	for (int i = 0; i < 16; ++i)
		if (fabs(lhs->col_major[i] - rhs->col_major[i]) > eps) {
			b = false;
			break;
		}
	return b;
}

void multiply_matrix4x4f(matrix4x4f *out, const matrix4x4f *lhs, const matrix4x4f *rhs) {
	for (int x = 0; x < 4; ++x)
		for (int y = 0; y < 4; ++y) {
			float r = 0;
			for (int i = 0; i < 4; ++i)
				r += lhs->row_col(y, i) * rhs->row_col(i, x);
			out->row_col(y, x) = r;
		}
}

void invert_matrix4x4f(matrix4x4f *out, const matrix4x4f *in) { // {{{
	matrix4x4f temp, transp;
	transpose_matrix4x4f(&transp, in);

	// calculate pairs for first 8 elements (cofactors)
	temp.col_major[0] = transp.col_major[10] * transp.col_major[15];
	temp.col_major[1] = transp.col_major[11] * transp.col_major[14];
	temp.col_major[2] = transp.col_major[9]  * transp.col_major[15];
	temp.col_major[3] = transp.col_major[11] * transp.col_major[13];
	temp.col_major[4] = transp.col_major[9]  * transp.col_major[14];
	temp.col_major[5] = transp.col_major[10] * transp.col_major[13];
	temp.col_major[6] = transp.col_major[8]  * transp.col_major[15];
	temp.col_major[7] = transp.col_major[11] * transp.col_major[12];
	temp.col_major[8] = transp.col_major[8]  * transp.col_major[14];
	temp.col_major[9] = transp.col_major[10] * transp.col_major[12];
	temp.col_major[10]= transp.col_major[8]  * transp.col_major[13];
	temp.col_major[11]= transp.col_major[9]  * transp.col_major[12];

	// calculate first 8 elements (cofactors)
	out->col_major[0] = temp.col_major[0]*transp.col_major[5] + temp.col_major[3]*transp.col_major[6] + temp.col_major[4] *transp.col_major[7]
	                   -temp.col_major[1]*transp.col_major[5] - temp.col_major[2]*transp.col_major[6] - temp.col_major[5] *transp.col_major[7];
	out->col_major[1] = temp.col_major[1]*transp.col_major[4] + temp.col_major[6]*transp.col_major[6] + temp.col_major[9] *transp.col_major[7]
	                   -temp.col_major[0]*transp.col_major[4] - temp.col_major[7]*transp.col_major[6] - temp.col_major[8] *transp.col_major[7];
	out->col_major[2] = temp.col_major[2]*transp.col_major[4] + temp.col_major[7]*transp.col_major[5] + temp.col_major[10]*transp.col_major[7]
	                   -temp.col_major[3]*transp.col_major[4] - temp.col_major[6]*transp.col_major[5] - temp.col_major[11]*transp.col_major[7];
	out->col_major[3] = temp.col_major[5]*transp.col_major[4] + temp.col_major[8]*transp.col_major[5] + temp.col_major[11]*transp.col_major[6]
	                   -temp.col_major[4]*transp.col_major[4] - temp.col_major[9]*transp.col_major[5] - temp.col_major[10]*transp.col_major[6];
	out->col_major[4] = temp.col_major[1]*transp.col_major[1] + temp.col_major[2]*transp.col_major[2] + temp.col_major[5] *transp.col_major[3]
	                   -temp.col_major[0]*transp.col_major[1] - temp.col_major[3]*transp.col_major[2] - temp.col_major[4] *transp.col_major[3];
	out->col_major[5] = temp.col_major[0]*transp.col_major[0] + temp.col_major[7]*transp.col_major[2] + temp.col_major[8] *transp.col_major[3]
	                   -temp.col_major[1]*transp.col_major[0] - temp.col_major[6]*transp.col_major[2] - temp.col_major[9] *transp.col_major[3];
	out->col_major[6] = temp.col_major[3]*transp.col_major[0] + temp.col_major[6]*transp.col_major[1] + temp.col_major[11]*transp.col_major[3]
	                   -temp.col_major[2]*transp.col_major[0] - temp.col_major[7]*transp.col_major[1] - temp.col_major[10]*transp.col_major[3];
	out->col_major[7] = temp.col_major[4]*transp.col_major[0] + temp.col_major[9]*transp.col_major[1] + temp.col_major[10]*transp.col_major[2]
		               -temp.col_major[5]*transp.col_major[0] - temp.col_major[8]*transp.col_major[1] - temp.col_major[11]*transp.col_major[2];
	
	// calculate pairs for second 8 elements (cofactors)
	temp.col_major[0] = transp.col_major[2]*transp.col_major[7];
	temp.col_major[1] = transp.col_major[3]*transp.col_major[6];  
	temp.col_major[2] = transp.col_major[1]*transp.col_major[7];
	temp.col_major[3] = transp.col_major[3]*transp.col_major[5];
	temp.col_major[4] = transp.col_major[1]*transp.col_major[6];
	temp.col_major[5] = transp.col_major[2]*transp.col_major[5];
	temp.col_major[6] = transp.col_major[0]*transp.col_major[7];
	temp.col_major[7] = transp.col_major[3]*transp.col_major[4];
	temp.col_major[8] = transp.col_major[0]*transp.col_major[6];
	temp.col_major[9] = transp.col_major[2]*transp.col_major[4];
	temp.col_major[10] = transp.col_major[0]*transp.col_major[5];
	temp.col_major[11] = transp.col_major[1]*transp.col_major[4];

	// calculate second 8 elements
	out->col_major[8] =  temp.col_major[0]*transp.col_major[13] + temp.col_major[3]*transp.col_major[14] + temp.col_major[4]*transp.col_major[15]
	                    -temp.col_major[1]*transp.col_major[13] - temp.col_major[2]*transp.col_major[14] - temp.col_major[5]*transp.col_major[15];
	out->col_major[9] =  temp.col_major[1]*transp.col_major[12] + temp.col_major[6]*transp.col_major[14] + temp.col_major[9]*transp.col_major[15]
	                    -temp.col_major[0]*transp.col_major[12] - temp.col_major[7]*transp.col_major[14] - temp.col_major[8]*transp.col_major[15];
	out->col_major[10] = temp.col_major[2]*transp.col_major[12] + temp.col_major[7]*transp.col_major[13] + temp.col_major[10]*transp.col_major[15]
	                    -temp.col_major[3]*transp.col_major[12] - temp.col_major[6]*transp.col_major[13] - temp.col_major[11]*transp.col_major[15];
	out->col_major[11] = temp.col_major[5]*transp.col_major[12] + temp.col_major[8]*transp.col_major[13] + temp.col_major[11]*transp.col_major[14]
	                    -temp.col_major[4]*transp.col_major[12] - temp.col_major[9]*transp.col_major[13] - temp.col_major[10]*transp.col_major[14];
	out->col_major[12] = temp.col_major[2]*transp.col_major[10] + temp.col_major[5]*transp.col_major[11] + temp.col_major[1]*transp.col_major[9]
	                    -temp.col_major[4]*transp.col_major[11] - temp.col_major[0]*transp.col_major[9] - temp.col_major[3]*transp.col_major[10];
	out->col_major[13] = temp.col_major[8]*transp.col_major[11] + temp.col_major[0]*transp.col_major[8] + temp.col_major[7]*transp.col_major[10]
	                    -temp.col_major[6]*transp.col_major[10] - temp.col_major[9]*transp.col_major[11] - temp.col_major[1]*transp.col_major[8];
	out->col_major[14] = temp.col_major[6]*transp.col_major[9] + temp.col_major[11]*transp.col_major[11] + temp.col_major[3]*transp.col_major[8]
	                    -temp.col_major[10]*transp.col_major[11] - temp.col_major[2]*transp.col_major[8] - temp.col_major[7]*transp.col_major[9];
	out->col_major[15] = temp.col_major[10]*transp.col_major[10] + temp.col_major[4]*transp.col_major[8] + temp.col_major[9]*transp.col_major[9]
	                    -temp.col_major[8]*transp.col_major[9] - temp.col_major[11]*transp.col_major[10] - temp.col_major[5]*transp.col_major[8];

	// calculate determinant
	float det = transp.col_major[0]*out->col_major[0] + transp.col_major[1]*out->col_major[1] + 
	            transp.col_major[2]*out->col_major[2] + transp.col_major[3]*out->col_major[3];

	if(fabs(det) > 0.00001)
		det = (1.0)/det;
	for(int i=0; i<16; i++)
		out->col_major[i] *= det;
}	// }}}

// vim: foldmethod=marker :
