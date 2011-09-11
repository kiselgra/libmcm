#ifndef __VECTOR3_H__ 
#define __VECTOR3_H__ 

#include <stdbool.h>

typedef struct {
	float x,y,z;
} vec3f;

typedef struct {
	double x,y,z;
} vec3d;

typedef struct {
	float x,y,z,w;
} vec4f;

typedef struct {
	double x,y,z,w;
} vec4d;

void make_vec3f(vec3f *v, float x, float y, float z);

static inline float* component(const vec3f *v, int n) { return ((float*)v)+n; }

bool equal_vec3fs_under_eps(const vec3f *a, const vec3f *b, float epsilon);

void cross_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs);	// NOT save to assume it works in-place.
float dot_vec3f(const vec3f *lhs, const vec3f *rhs);	
float length_of_vec3f(const vec3f *v);

void add_components_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs);	// save to assume it works in-place
void sub_components_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs);	// save to assume it works in-place
void multiply_components_vec3f(vec3f *out, const vec3f *lhs, const vec3f *rhs);	// save to assume it works in-place
void multiply_vec3f_by_scalar(vec3f *out, const vec3f *lhs, float rhs);	// save to assume it works in-place
void divide_vec3f_by_scalar(vec3f *out, const vec3f *lhs, float rhs);	// save to assume it works in-place

float component_val(const vec3f *v, int c);
void change_component(vec3f *v, int c, float val);


#endif

