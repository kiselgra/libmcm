#include "vectors.h"

#include <math.h>

void make_vec3f(vec3f *v, float x, float y, float z) {
	v->x = x;
	v->y = y;
	v->z = z;
}


bool equal_vec3fs_under_eps(const vec3f *a, const vec3f *b, float eps) {
	return (fabs(a->x - b->x) <= eps) && (fabs(a->y - b->y) <= eps) && (fabs(a->z - b->z) <= eps);
}


void cross_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs) {
	out->x = lhs->y * rhs->z - lhs->z * rhs->y;
	out->y = lhs->z * rhs->x - lhs->x * rhs->z;
	out->z = lhs->x * rhs->y - lhs->y * rhs->x;
}

float dot_vec3f(const vec3f *lhs, const vec3f *rhs) {
	return lhs->x * rhs->x + lhs->y * rhs->y + lhs->z * rhs->z;
}

float length_of_vec3f(const vec3f *v) {
	return sqrtf(dot_vec3f(v, v));
}



void add_components_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs) {
	out->x = lhs->x + rhs->x;
	out->y = lhs->y + rhs->y;
	out->z = lhs->z + rhs->z;
}

void sub_components_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs) {
	out->x = lhs->x - rhs->x;
	out->y = lhs->y - rhs->y;
	out->z = lhs->z - rhs->z;
}

void multiply_components_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs) {
	out->x = lhs->x * rhs->x;
	out->y = lhs->y * rhs->y;
	out->z = lhs->z * rhs->z;
}

void multiply_vec3f_by_scalar(vec3f *out, const vec3f *lhs, float rhs) {
	out->x = lhs->x * rhs;
	out->y = lhs->y * rhs;
	out->z = lhs->z * rhs;
}

void divide_vec3f_by_scalar(vec3f *out, const vec3f *lhs, float rhs) {
	out->x = lhs->x / rhs;
	out->y = lhs->y / rhs;
	out->z = lhs->z / rhs;
}


float component_val(const vec3f *v, int c) {
	return ((float*)v)[c];
}

void change_component(vec3f *v, int c, float val) {
	((float*)v)[c] = val;
}



