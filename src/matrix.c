/* 
 * Autogenerated by rtgen. Licenced under the terms of the GPL.
 */

#include "matrix.h"


void transpose_matrix4x4f(matrix4x4f *out, const matrix4x4f *in)
{
	for (int y = 0; (y < 4); ++y)
		for (int x = 0; (x < 4); ++x)
			out->col_major[((y * 4) + x)] = in->col_major[((x * 4) + y)];

}

void transpose_matrix4x4d(matrix4x4d *out, const matrix4x4d *in)
{
	for (int y = 0; (y < 4); ++y)
		for (int x = 0; (x < 4); ++x)
			out->col_major[((y * 4) + x)] = in->col_major[((x * 4) + y)];

}

void multiply_matrix4x4f_vec4f(vec4f *out, const matrix4x4f *lhs, const vec4f *rhs)
{
	out->x = ((lhs->col_major[((0 * 4) + 0)] * rhs->x) + ((lhs->col_major[((1 * 4) + 0)] * rhs->y) + ((lhs->col_major[((2 * 4) + 0)] * rhs->z) + (lhs->col_major[((3 * 4) + 0)] * rhs->w))));
	out->y = ((lhs->col_major[((0 * 4) + 1)] * rhs->x) + ((lhs->col_major[((1 * 4) + 1)] * rhs->y) + ((lhs->col_major[((2 * 4) + 1)] * rhs->z) + (lhs->col_major[((3 * 4) + 1)] * rhs->w))));
	out->z = ((lhs->col_major[((0 * 4) + 2)] * rhs->x) + ((lhs->col_major[((1 * 4) + 2)] * rhs->y) + ((lhs->col_major[((2 * 4) + 2)] * rhs->z) + (lhs->col_major[((3 * 4) + 2)] * rhs->w))));
	out->w = ((lhs->col_major[((0 * 4) + 3)] * rhs->x) + ((lhs->col_major[((1 * 4) + 3)] * rhs->y) + ((lhs->col_major[((2 * 4) + 3)] * rhs->z) + (lhs->col_major[((3 * 4) + 3)] * rhs->w))));

}

void multiply_matrix4x4d_vec4d(vec4d *out, const matrix4x4d *lhs, const vec4d *rhs)
{
	out->x = ((lhs->col_major[((0 * 4) + 0)] * rhs->x) + ((lhs->col_major[((1 * 4) + 0)] * rhs->y) + ((lhs->col_major[((2 * 4) + 0)] * rhs->z) + (lhs->col_major[((3 * 4) + 0)] * rhs->w))));
	out->y = ((lhs->col_major[((0 * 4) + 1)] * rhs->x) + ((lhs->col_major[((1 * 4) + 1)] * rhs->y) + ((lhs->col_major[((2 * 4) + 1)] * rhs->z) + (lhs->col_major[((3 * 4) + 1)] * rhs->w))));
	out->z = ((lhs->col_major[((0 * 4) + 2)] * rhs->x) + ((lhs->col_major[((1 * 4) + 2)] * rhs->y) + ((lhs->col_major[((2 * 4) + 2)] * rhs->z) + (lhs->col_major[((3 * 4) + 2)] * rhs->w))));
	out->w = ((lhs->col_major[((0 * 4) + 3)] * rhs->x) + ((lhs->col_major[((1 * 4) + 3)] * rhs->y) + ((lhs->col_major[((2 * 4) + 3)] * rhs->z) + (lhs->col_major[((3 * 4) + 3)] * rhs->w))));

}

void multiply_matrices4x4f(matrix4x4f *out, const matrix4x4f *lhs, const matrix4x4f *rhs)
{
	for (int x = 0; (x < 4); ++x)
		for (int y = 0; (y < 4); ++y) {
			float r = 0;
			for (int i = 0; (i < 4); ++i)
				r = (r + (lhs->col_major[((i * 4) + y)] * rhs->col_major[((x * 4) + i)]));
			out->col_major[((x * 4) + y)] = r;
		}

}

void multiply_matrices4x4d(matrix4x4d *out, const matrix4x4d *lhs, const matrix4x4d *rhs)
{
	for (int x = 0; (x < 4); ++x)
		for (int y = 0; (y < 4); ++y) {
			double r = 0;
			for (int i = 0; (i < 4); ++i)
				r = (r + (lhs->col_major[((i * 4) + y)] * rhs->col_major[((x * 4) + i)]));
			out->col_major[((x * 4) + y)] = r;
		}

}

void make_unit_matrix4x4f(matrix4x4f *mat)
{
	mat->col_major[0] = 1;
	mat->col_major[1] = 0;
	mat->col_major[2] = 0;
	mat->col_major[3] = 0;
	mat->col_major[4] = 0;
	mat->col_major[5] = 1;
	mat->col_major[6] = 0;
	mat->col_major[7] = 0;
	mat->col_major[8] = 0;
	mat->col_major[9] = 0;
	mat->col_major[10] = 1;
	mat->col_major[11] = 0;
	mat->col_major[12] = 0;
	mat->col_major[13] = 0;
	mat->col_major[14] = 0;
	mat->col_major[15] = 1;

}

void make_unit_matrix4x4d(matrix4x4d *mat)
{
	mat->col_major[0] = 1;
	mat->col_major[1] = 0;
	mat->col_major[2] = 0;
	mat->col_major[3] = 0;
	mat->col_major[4] = 0;
	mat->col_major[5] = 1;
	mat->col_major[6] = 0;
	mat->col_major[7] = 0;
	mat->col_major[8] = 0;
	mat->col_major[9] = 0;
	mat->col_major[10] = 1;
	mat->col_major[11] = 0;
	mat->col_major[12] = 0;
	mat->col_major[13] = 0;
	mat->col_major[14] = 0;
	mat->col_major[15] = 1;

}

void make_scale_matrix4x4f(matrix4x4f *mat, const vec3f *scale)
{
	mat->col_major[0] = scale->x;
	mat->col_major[1] = 0;
	mat->col_major[2] = 0;
	mat->col_major[3] = 0;
	mat->col_major[4] = 0;
	mat->col_major[5] = scale->y;
	mat->col_major[6] = 0;
	mat->col_major[7] = 0;
	mat->col_major[8] = 0;
	mat->col_major[9] = 0;
	mat->col_major[10] = scale->z;
	mat->col_major[11] = 0;
	mat->col_major[12] = 0;
	mat->col_major[13] = 0;
	mat->col_major[14] = 0;
	mat->col_major[15] = 1;

}

void make_scale_matrix4x4d(matrix4x4d *mat, const vec3d *scale)
{
	mat->col_major[0] = scale->x;
	mat->col_major[1] = 0;
	mat->col_major[2] = 0;
	mat->col_major[3] = 0;
	mat->col_major[4] = 0;
	mat->col_major[5] = scale->y;
	mat->col_major[6] = 0;
	mat->col_major[7] = 0;
	mat->col_major[8] = 0;
	mat->col_major[9] = 0;
	mat->col_major[10] = scale->z;
	mat->col_major[11] = 0;
	mat->col_major[12] = 0;
	mat->col_major[13] = 0;
	mat->col_major[14] = 0;
	mat->col_major[15] = 1;

}

void make_rotation_matrix4x4f(matrix4x4f *mat, const vec3f *axis, float angle_in_rad)
{
	float cos_a = cosf(angle_in_rad);
	float sin_a = sinf(angle_in_rad);
	float _1_cos_a = (1 - cos_a);
	float v1 = axis->x;
	float v2 = axis->y;
	float v3 = axis->z;
	float v1v1 = (v1 * v1);
	float v1v2 = (v1 * v2);
	float v1v3 = (v1 * v3);
	float v2v2 = (v2 * v2);
	float v2v3 = (v2 * v3);
	float v3v3 = (v3 * v3);
	mat->col_major[((0 * 4) + 0)] = (cos_a + (v1v1 * _1_cos_a));
	mat->col_major[((1 * 4) + 0)] = ((v1v2 * _1_cos_a) - (v3 * sin_a));
	mat->col_major[((2 * 4) + 0)] = ((v1v3 * _1_cos_a) + (v2 * sin_a));
	mat->col_major[((0 * 4) + 1)] = ((v1v2 * _1_cos_a) + (v3 * sin_a));
	mat->col_major[((1 * 4) + 1)] = (cos_a + (v2v2 * _1_cos_a));
	mat->col_major[((2 * 4) + 1)] = ((v2v3 * _1_cos_a) - (v1 * sin_a));
	mat->col_major[((0 * 4) + 2)] = ((v1v3 * _1_cos_a) - (v2 * sin_a));
	mat->col_major[((1 * 4) + 2)] = ((v2v3 * _1_cos_a) + (v1 * sin_a));
	mat->col_major[((2 * 4) + 2)] = (cos_a + (v3v3 * _1_cos_a));
	mat->col_major[((3 * 4) + 0)] = 0;
	mat->col_major[((3 * 4) + 1)] = 0;
	mat->col_major[((3 * 4) + 2)] = 0;
	mat->col_major[((0 * 4) + 3)] = 0;
	mat->col_major[((1 * 4) + 3)] = 0;
	mat->col_major[((2 * 4) + 3)] = 0;
	mat->col_major[((3 * 4) + 3)] = 1;

}

void make_rotation_matrix4x4d(matrix4x4d *mat, const vec3d *axis, double angle_in_rad)
{
	double cos_a = cos(angle_in_rad);
	double sin_a = sin(angle_in_rad);
	double _1_cos_a = (1 - cos_a);
	double v1 = axis->x;
	double v2 = axis->y;
	double v3 = axis->z;
	double v1v1 = (v1 * v1);
	double v1v2 = (v1 * v2);
	double v1v3 = (v1 * v3);
	double v2v2 = (v2 * v2);
	double v2v3 = (v2 * v3);
	double v3v3 = (v3 * v3);
	mat->col_major[((0 * 4) + 0)] = (cos_a + (v1v1 * _1_cos_a));
	mat->col_major[((1 * 4) + 0)] = ((v1v2 * _1_cos_a) - (v3 * sin_a));
	mat->col_major[((2 * 4) + 0)] = ((v1v3 * _1_cos_a) + (v2 * sin_a));
	mat->col_major[((0 * 4) + 1)] = ((v1v2 * _1_cos_a) + (v3 * sin_a));
	mat->col_major[((1 * 4) + 1)] = (cos_a + (v2v2 * _1_cos_a));
	mat->col_major[((2 * 4) + 1)] = ((v2v3 * _1_cos_a) - (v1 * sin_a));
	mat->col_major[((0 * 4) + 2)] = ((v1v3 * _1_cos_a) - (v2 * sin_a));
	mat->col_major[((1 * 4) + 2)] = ((v2v3 * _1_cos_a) + (v1 * sin_a));
	mat->col_major[((2 * 4) + 2)] = (cos_a + (v3v3 * _1_cos_a));
	mat->col_major[((3 * 4) + 0)] = 0;
	mat->col_major[((3 * 4) + 1)] = 0;
	mat->col_major[((3 * 4) + 2)] = 0;
	mat->col_major[((0 * 4) + 3)] = 0;
	mat->col_major[((1 * 4) + 3)] = 0;
	mat->col_major[((2 * 4) + 3)] = 0;
	mat->col_major[((3 * 4) + 3)] = 1;

}

void invert_matrix4x4f(matrix4x4f *out, const matrix4x4f *in)
{
	matrix4x4f temp;
	matrix4x4f transp;
	transpose_matrix4x4f(&transp, in);
	temp.col_major[0] = (transp.col_major[10] * transp.col_major[15]);
	temp.col_major[1] = (transp.col_major[11] * transp.col_major[14]);
	temp.col_major[2] = (transp.col_major[9] * transp.col_major[15]);
	temp.col_major[3] = (transp.col_major[11] * transp.col_major[13]);
	temp.col_major[4] = (transp.col_major[9] * transp.col_major[14]);
	temp.col_major[5] = (transp.col_major[10] * transp.col_major[13]);
	temp.col_major[6] = (transp.col_major[8] * transp.col_major[15]);
	temp.col_major[7] = (transp.col_major[11] * transp.col_major[12]);
	temp.col_major[8] = (transp.col_major[8] * transp.col_major[14]);
	temp.col_major[9] = (transp.col_major[10] * transp.col_major[12]);
	temp.col_major[10] = (transp.col_major[8] * transp.col_major[13]);
	temp.col_major[11] = (transp.col_major[9] * transp.col_major[12]);
	out->col_major[0] = (((temp.col_major[0] * transp.col_major[5]) + ((temp.col_major[3] * transp.col_major[6]) + (temp.col_major[4] * transp.col_major[7]))) - ((temp.col_major[1] * transp.col_major[5]) + ((temp.col_major[2] * transp.col_major[6]) + (temp.col_major[5] * transp.col_major[7]))));
	out->col_major[1] = (((temp.col_major[1] * transp.col_major[4]) + ((temp.col_major[6] * transp.col_major[6]) + (temp.col_major[9] * transp.col_major[7]))) - ((temp.col_major[0] * transp.col_major[4]) + ((temp.col_major[7] * transp.col_major[6]) + (temp.col_major[8] * transp.col_major[7]))));
	out->col_major[2] = (((temp.col_major[2] * transp.col_major[4]) + ((temp.col_major[7] * transp.col_major[5]) + (temp.col_major[10] * transp.col_major[7]))) - ((temp.col_major[3] * transp.col_major[4]) + ((temp.col_major[6] * transp.col_major[5]) + (temp.col_major[11] * transp.col_major[7]))));
	out->col_major[3] = (((temp.col_major[5] * transp.col_major[4]) + ((temp.col_major[8] * transp.col_major[5]) + (temp.col_major[11] * transp.col_major[6]))) - ((temp.col_major[4] * transp.col_major[4]) + ((temp.col_major[9] * transp.col_major[5]) + (temp.col_major[10] * transp.col_major[6]))));
	out->col_major[4] = (((temp.col_major[1] * transp.col_major[1]) + ((temp.col_major[2] * transp.col_major[2]) + (temp.col_major[5] * transp.col_major[3]))) - ((temp.col_major[0] * transp.col_major[1]) + ((temp.col_major[3] * transp.col_major[2]) + (temp.col_major[4] * transp.col_major[3]))));
	out->col_major[5] = (((temp.col_major[0] * transp.col_major[0]) + ((temp.col_major[7] * transp.col_major[2]) + (temp.col_major[8] * transp.col_major[3]))) - ((temp.col_major[1] * transp.col_major[0]) + ((temp.col_major[6] * transp.col_major[2]) + (temp.col_major[9] * transp.col_major[3]))));
	out->col_major[6] = (((temp.col_major[3] * transp.col_major[0]) + ((temp.col_major[6] * transp.col_major[1]) + (temp.col_major[11] * transp.col_major[3]))) - ((temp.col_major[2] * transp.col_major[0]) + ((temp.col_major[7] * transp.col_major[1]) + (temp.col_major[10] * transp.col_major[3]))));
	out->col_major[7] = (((temp.col_major[4] * transp.col_major[0]) + ((temp.col_major[9] * transp.col_major[1]) + (temp.col_major[10] * transp.col_major[2]))) - ((temp.col_major[5] * transp.col_major[0]) + ((temp.col_major[8] * transp.col_major[1]) + (temp.col_major[11] * transp.col_major[2]))));
	temp.col_major[0] = (transp.col_major[2] * transp.col_major[7]);
	temp.col_major[1] = (transp.col_major[3] * transp.col_major[6]);
	temp.col_major[2] = (transp.col_major[1] * transp.col_major[7]);
	temp.col_major[3] = (transp.col_major[3] * transp.col_major[5]);
	temp.col_major[4] = (transp.col_major[1] * transp.col_major[6]);
	temp.col_major[5] = (transp.col_major[2] * transp.col_major[5]);
	temp.col_major[6] = (transp.col_major[0] * transp.col_major[7]);
	temp.col_major[7] = (transp.col_major[3] * transp.col_major[4]);
	temp.col_major[8] = (transp.col_major[0] * transp.col_major[6]);
	temp.col_major[9] = (transp.col_major[2] * transp.col_major[4]);
	temp.col_major[10] = (transp.col_major[0] * transp.col_major[5]);
	temp.col_major[11] = (transp.col_major[1] * transp.col_major[4]);
	out->col_major[8] = (((temp.col_major[0] * transp.col_major[13]) + ((temp.col_major[3] * transp.col_major[14]) + (temp.col_major[4] * transp.col_major[15]))) - ((temp.col_major[1] * transp.col_major[13]) + ((temp.col_major[2] * transp.col_major[14]) + (temp.col_major[5] * transp.col_major[15]))));
	out->col_major[9] = (((temp.col_major[1] * transp.col_major[12]) + ((temp.col_major[6] * transp.col_major[14]) + (temp.col_major[9] * transp.col_major[15]))) - ((temp.col_major[0] * transp.col_major[12]) + ((temp.col_major[7] * transp.col_major[14]) + (temp.col_major[8] * transp.col_major[15]))));
	out->col_major[10] = (((temp.col_major[2] * transp.col_major[12]) + ((temp.col_major[7] * transp.col_major[13]) + (temp.col_major[10] * transp.col_major[15]))) - ((temp.col_major[3] * transp.col_major[12]) + ((temp.col_major[6] * transp.col_major[13]) + (temp.col_major[11] * transp.col_major[15]))));
	out->col_major[11] = (((temp.col_major[5] * transp.col_major[12]) + ((temp.col_major[8] * transp.col_major[13]) + (temp.col_major[11] * transp.col_major[14]))) - ((temp.col_major[4] * transp.col_major[12]) + ((temp.col_major[9] * transp.col_major[13]) + (temp.col_major[10] * transp.col_major[14]))));
	out->col_major[12] = (((temp.col_major[2] * transp.col_major[10]) + ((temp.col_major[5] * transp.col_major[11]) + (temp.col_major[1] * transp.col_major[9]))) - ((temp.col_major[4] * transp.col_major[11]) + ((temp.col_major[0] * transp.col_major[9]) + (temp.col_major[3] * transp.col_major[10]))));
	out->col_major[13] = (((temp.col_major[8] * transp.col_major[11]) + ((temp.col_major[0] * transp.col_major[8]) + (temp.col_major[7] * transp.col_major[10]))) - ((temp.col_major[6] * transp.col_major[10]) + ((temp.col_major[9] * transp.col_major[11]) + (temp.col_major[1] * transp.col_major[8]))));
	out->col_major[14] = (((temp.col_major[6] * transp.col_major[9]) + ((temp.col_major[11] * transp.col_major[11]) + (temp.col_major[3] * transp.col_major[8]))) - ((temp.col_major[10] * transp.col_major[11]) + ((temp.col_major[2] * transp.col_major[8]) + (temp.col_major[7] * transp.col_major[9]))));
	out->col_major[15] = (((temp.col_major[10] * transp.col_major[10]) + ((temp.col_major[4] * transp.col_major[8]) + (temp.col_major[9] * transp.col_major[9]))) - ((temp.col_major[8] * transp.col_major[9]) + ((temp.col_major[11] * transp.col_major[10]) + (temp.col_major[5] * transp.col_major[8]))));
	float det = ((transp.col_major[0] * out->col_major[0]) + ((transp.col_major[1] * out->col_major[1]) + ((transp.col_major[2] * out->col_major[2]) + (transp.col_major[3] * out->col_major[3]))));
	if (fabs(det) > 1.e-5)
		det = (1.0F / det);
	for (int i = 0; (i < 16); ++i)
		out->col_major[i] = (out->col_major[i] * det);

}

void invert_matrix4x4d(matrix4x4d *out, const matrix4x4d *in)
{
	matrix4x4d temp;
	matrix4x4d transp;
	transpose_matrix4x4d(&transp, in);
	temp.col_major[0] = (transp.col_major[10] * transp.col_major[15]);
	temp.col_major[1] = (transp.col_major[11] * transp.col_major[14]);
	temp.col_major[2] = (transp.col_major[9] * transp.col_major[15]);
	temp.col_major[3] = (transp.col_major[11] * transp.col_major[13]);
	temp.col_major[4] = (transp.col_major[9] * transp.col_major[14]);
	temp.col_major[5] = (transp.col_major[10] * transp.col_major[13]);
	temp.col_major[6] = (transp.col_major[8] * transp.col_major[15]);
	temp.col_major[7] = (transp.col_major[11] * transp.col_major[12]);
	temp.col_major[8] = (transp.col_major[8] * transp.col_major[14]);
	temp.col_major[9] = (transp.col_major[10] * transp.col_major[12]);
	temp.col_major[10] = (transp.col_major[8] * transp.col_major[13]);
	temp.col_major[11] = (transp.col_major[9] * transp.col_major[12]);
	out->col_major[0] = (((temp.col_major[0] * transp.col_major[5]) + ((temp.col_major[3] * transp.col_major[6]) + (temp.col_major[4] * transp.col_major[7]))) - ((temp.col_major[1] * transp.col_major[5]) + ((temp.col_major[2] * transp.col_major[6]) + (temp.col_major[5] * transp.col_major[7]))));
	out->col_major[1] = (((temp.col_major[1] * transp.col_major[4]) + ((temp.col_major[6] * transp.col_major[6]) + (temp.col_major[9] * transp.col_major[7]))) - ((temp.col_major[0] * transp.col_major[4]) + ((temp.col_major[7] * transp.col_major[6]) + (temp.col_major[8] * transp.col_major[7]))));
	out->col_major[2] = (((temp.col_major[2] * transp.col_major[4]) + ((temp.col_major[7] * transp.col_major[5]) + (temp.col_major[10] * transp.col_major[7]))) - ((temp.col_major[3] * transp.col_major[4]) + ((temp.col_major[6] * transp.col_major[5]) + (temp.col_major[11] * transp.col_major[7]))));
	out->col_major[3] = (((temp.col_major[5] * transp.col_major[4]) + ((temp.col_major[8] * transp.col_major[5]) + (temp.col_major[11] * transp.col_major[6]))) - ((temp.col_major[4] * transp.col_major[4]) + ((temp.col_major[9] * transp.col_major[5]) + (temp.col_major[10] * transp.col_major[6]))));
	out->col_major[4] = (((temp.col_major[1] * transp.col_major[1]) + ((temp.col_major[2] * transp.col_major[2]) + (temp.col_major[5] * transp.col_major[3]))) - ((temp.col_major[0] * transp.col_major[1]) + ((temp.col_major[3] * transp.col_major[2]) + (temp.col_major[4] * transp.col_major[3]))));
	out->col_major[5] = (((temp.col_major[0] * transp.col_major[0]) + ((temp.col_major[7] * transp.col_major[2]) + (temp.col_major[8] * transp.col_major[3]))) - ((temp.col_major[1] * transp.col_major[0]) + ((temp.col_major[6] * transp.col_major[2]) + (temp.col_major[9] * transp.col_major[3]))));
	out->col_major[6] = (((temp.col_major[3] * transp.col_major[0]) + ((temp.col_major[6] * transp.col_major[1]) + (temp.col_major[11] * transp.col_major[3]))) - ((temp.col_major[2] * transp.col_major[0]) + ((temp.col_major[7] * transp.col_major[1]) + (temp.col_major[10] * transp.col_major[3]))));
	out->col_major[7] = (((temp.col_major[4] * transp.col_major[0]) + ((temp.col_major[9] * transp.col_major[1]) + (temp.col_major[10] * transp.col_major[2]))) - ((temp.col_major[5] * transp.col_major[0]) + ((temp.col_major[8] * transp.col_major[1]) + (temp.col_major[11] * transp.col_major[2]))));
	temp.col_major[0] = (transp.col_major[2] * transp.col_major[7]);
	temp.col_major[1] = (transp.col_major[3] * transp.col_major[6]);
	temp.col_major[2] = (transp.col_major[1] * transp.col_major[7]);
	temp.col_major[3] = (transp.col_major[3] * transp.col_major[5]);
	temp.col_major[4] = (transp.col_major[1] * transp.col_major[6]);
	temp.col_major[5] = (transp.col_major[2] * transp.col_major[5]);
	temp.col_major[6] = (transp.col_major[0] * transp.col_major[7]);
	temp.col_major[7] = (transp.col_major[3] * transp.col_major[4]);
	temp.col_major[8] = (transp.col_major[0] * transp.col_major[6]);
	temp.col_major[9] = (transp.col_major[2] * transp.col_major[4]);
	temp.col_major[10] = (transp.col_major[0] * transp.col_major[5]);
	temp.col_major[11] = (transp.col_major[1] * transp.col_major[4]);
	out->col_major[8] = (((temp.col_major[0] * transp.col_major[13]) + ((temp.col_major[3] * transp.col_major[14]) + (temp.col_major[4] * transp.col_major[15]))) - ((temp.col_major[1] * transp.col_major[13]) + ((temp.col_major[2] * transp.col_major[14]) + (temp.col_major[5] * transp.col_major[15]))));
	out->col_major[9] = (((temp.col_major[1] * transp.col_major[12]) + ((temp.col_major[6] * transp.col_major[14]) + (temp.col_major[9] * transp.col_major[15]))) - ((temp.col_major[0] * transp.col_major[12]) + ((temp.col_major[7] * transp.col_major[14]) + (temp.col_major[8] * transp.col_major[15]))));
	out->col_major[10] = (((temp.col_major[2] * transp.col_major[12]) + ((temp.col_major[7] * transp.col_major[13]) + (temp.col_major[10] * transp.col_major[15]))) - ((temp.col_major[3] * transp.col_major[12]) + ((temp.col_major[6] * transp.col_major[13]) + (temp.col_major[11] * transp.col_major[15]))));
	out->col_major[11] = (((temp.col_major[5] * transp.col_major[12]) + ((temp.col_major[8] * transp.col_major[13]) + (temp.col_major[11] * transp.col_major[14]))) - ((temp.col_major[4] * transp.col_major[12]) + ((temp.col_major[9] * transp.col_major[13]) + (temp.col_major[10] * transp.col_major[14]))));
	out->col_major[12] = (((temp.col_major[2] * transp.col_major[10]) + ((temp.col_major[5] * transp.col_major[11]) + (temp.col_major[1] * transp.col_major[9]))) - ((temp.col_major[4] * transp.col_major[11]) + ((temp.col_major[0] * transp.col_major[9]) + (temp.col_major[3] * transp.col_major[10]))));
	out->col_major[13] = (((temp.col_major[8] * transp.col_major[11]) + ((temp.col_major[0] * transp.col_major[8]) + (temp.col_major[7] * transp.col_major[10]))) - ((temp.col_major[6] * transp.col_major[10]) + ((temp.col_major[9] * transp.col_major[11]) + (temp.col_major[1] * transp.col_major[8]))));
	out->col_major[14] = (((temp.col_major[6] * transp.col_major[9]) + ((temp.col_major[11] * transp.col_major[11]) + (temp.col_major[3] * transp.col_major[8]))) - ((temp.col_major[10] * transp.col_major[11]) + ((temp.col_major[2] * transp.col_major[8]) + (temp.col_major[7] * transp.col_major[9]))));
	out->col_major[15] = (((temp.col_major[10] * transp.col_major[10]) + ((temp.col_major[4] * transp.col_major[8]) + (temp.col_major[9] * transp.col_major[9]))) - ((temp.col_major[8] * transp.col_major[9]) + ((temp.col_major[11] * transp.col_major[10]) + (temp.col_major[5] * transp.col_major[8]))));
	double det = ((transp.col_major[0] * out->col_major[0]) + ((transp.col_major[1] * out->col_major[1]) + ((transp.col_major[2] * out->col_major[2]) + (transp.col_major[3] * out->col_major[3]))));
	if (fabs(det) > 1.e-5)
		det = (1.0F / det);
	for (int i = 0; (i < 16); ++i)
		out->col_major[i] = (out->col_major[i] * det);

}

bool equal_matrices_under_eps4x4f(const matrix4x4f *lhs, const matrix4x4f *rhs, float eps)
{
	for (int i = 0; (i < 16); ++i) {
		if ((fabs(lhs->col_major[i] - rhs->col_major[i])) > eps)
			return false;
	}
	return true;

}

bool equal_matrices_under_eps4x4d(const matrix4x4d *lhs, const matrix4x4d *rhs, double eps)
{
	for (int i = 0; (i < 16); ++i) {
		if ((fabs(lhs->col_major[i] - rhs->col_major[i])) > eps)
			return false;
	}
	return true;

}

float determinant_of_upper3x3_of_matrix4x4f(const matrix4x4f *mat)
{
	float p1 = (mat->col_major[((0 * 4) + 0)] * (mat->col_major[((1 * 4) + 1)] * mat->col_major[((2 * 4) + 2)]));
	float p2 = (mat->col_major[((1 * 4) + 0)] * (mat->col_major[((2 * 4) + 1)] * mat->col_major[((0 * 4) + 2)]));
	float p3 = (mat->col_major[((2 * 4) + 0)] * (mat->col_major[((0 * 4) + 1)] * mat->col_major[((1 * 4) + 2)]));
	float n1 = (mat->col_major[((2 * 4) + 0)] * (mat->col_major[((1 * 4) + 1)] * mat->col_major[((0 * 4) + 2)]));
	float n2 = (mat->col_major[((1 * 4) + 0)] * (mat->col_major[((0 * 4) + 1)] * mat->col_major[((2 * 4) + 2)]));
	float n3 = (mat->col_major[((0 * 4) + 0)] * (mat->col_major[((2 * 4) + 1)] * mat->col_major[((1 * 4) + 2)]));
	float p = (p1 + (p2 + p3));
	float n = (n1 + (n2 + n3));
	return (p - n);

}

double determinant_of_upper3x3_of_matrix4x4d(const matrix4x4d *mat)
{
	double p1 = (mat->col_major[((0 * 4) + 0)] * (mat->col_major[((1 * 4) + 1)] * mat->col_major[((2 * 4) + 2)]));
	double p2 = (mat->col_major[((1 * 4) + 0)] * (mat->col_major[((2 * 4) + 1)] * mat->col_major[((0 * 4) + 2)]));
	double p3 = (mat->col_major[((2 * 4) + 0)] * (mat->col_major[((0 * 4) + 1)] * mat->col_major[((1 * 4) + 2)]));
	double n1 = (mat->col_major[((2 * 4) + 0)] * (mat->col_major[((1 * 4) + 1)] * mat->col_major[((0 * 4) + 2)]));
	double n2 = (mat->col_major[((1 * 4) + 0)] * (mat->col_major[((0 * 4) + 1)] * mat->col_major[((2 * 4) + 2)]));
	double n3 = (mat->col_major[((0 * 4) + 0)] * (mat->col_major[((2 * 4) + 1)] * mat->col_major[((1 * 4) + 2)]));
	double p = (p1 + (p2 + p3));
	double n = (n1 + (n2 + n3));
	return (p - n);

}

void copy_matrix4x4f(matrix4x4f *out, const matrix4x4f *in)
{
	out->col_major[0] = in->col_major[0];
	out->col_major[1] = in->col_major[1];
	out->col_major[2] = in->col_major[2];
	out->col_major[3] = in->col_major[3];
	out->col_major[4] = in->col_major[4];
	out->col_major[5] = in->col_major[5];
	out->col_major[6] = in->col_major[6];
	out->col_major[7] = in->col_major[7];
	out->col_major[8] = in->col_major[8];
	out->col_major[9] = in->col_major[9];
	out->col_major[10] = in->col_major[10];
	out->col_major[11] = in->col_major[11];
	out->col_major[12] = in->col_major[12];
	out->col_major[13] = in->col_major[13];
	out->col_major[14] = in->col_major[14];
	out->col_major[15] = in->col_major[15];

}

void copy_matrix4x4d(matrix4x4d *out, const matrix4x4d *in)
{
	out->col_major[0] = in->col_major[0];
	out->col_major[1] = in->col_major[1];
	out->col_major[2] = in->col_major[2];
	out->col_major[3] = in->col_major[3];
	out->col_major[4] = in->col_major[4];
	out->col_major[5] = in->col_major[5];
	out->col_major[6] = in->col_major[6];
	out->col_major[7] = in->col_major[7];
	out->col_major[8] = in->col_major[8];
	out->col_major[9] = in->col_major[9];
	out->col_major[10] = in->col_major[10];
	out->col_major[11] = in->col_major[11];
	out->col_major[12] = in->col_major[12];
	out->col_major[13] = in->col_major[13];
	out->col_major[14] = in->col_major[14];
	out->col_major[15] = in->col_major[15];

}

