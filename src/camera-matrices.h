/* 
 * Autogenerated by rtgen. Licenced under the terms of the GPL.
 */

#ifndef __CGEN_camera_matrices_H__
#define __CGEN_camera_matrices_H__
#include "stdbool.h"

#include "vectors.h"
#include "matrix.h"

void extract_dir_vec3d_of_matrix(vec3d *out, const matrix4x4d *lookat);
void extract_dir_vec3f_of_matrix(vec3f *out, const matrix4x4f *lookat);
void extract_dir_vec4d_of_matrix(vec4d *out, const matrix4x4d *lookat);
void extract_dir_vec4f_of_matrix(vec4f *out, const matrix4x4f *lookat);
void extract_pos_vec3d_of_matrix(vec3d *out, const matrix4x4d *lookat);
void extract_pos_vec3f_of_matrix(vec3f *out, const matrix4x4f *lookat);
void extract_pos_vec4d_of_matrix(vec4d *out, const matrix4x4d *lookat);
void extract_pos_vec4f_of_matrix(vec4f *out, const matrix4x4f *lookat);
void extract_right_vec3d_of_matrix(vec3d *out, const matrix4x4d *lookat);
void extract_right_vec3f_of_matrix(vec3f *out, const matrix4x4f *lookat);
void extract_right_vec4d_of_matrix(vec4d *out, const matrix4x4d *lookat);
void extract_right_vec4f_of_matrix(vec4f *out, const matrix4x4f *lookat);
void extract_up_vec3d_of_matrix(vec3d *out, const matrix4x4d *lookat);
void extract_up_vec3f_of_matrix(vec3f *out, const matrix4x4f *lookat);
void extract_up_vec4d_of_matrix(vec4d *out, const matrix4x4d *lookat);
void extract_up_vec4f_of_matrix(vec4f *out, const matrix4x4f *lookat);
void make_gl_viewing_matrixd(matrix4x4d *out, const matrix4x4d *lookat);
void make_gl_viewing_matrixf(matrix4x4f *out, const matrix4x4f *lookat);
void make_projection_matrixd(matrix4x4d *out, double fovy_degree, double aspect, double near, double far);
void make_projection_matrixf(matrix4x4f *out, float fovy_degree, float aspect, float near, float far);
void make_lookat_matrixd(matrix4x4d *out, const vec3d *pos, const vec3d *dir, const vec3d *up);
void make_lookat_matrixf(matrix4x4f *out, const vec3f *pos, const vec3f *dir, const vec3f *up);
void make_ortographic_matirxd(matrix4x4d *out, double right, double left, double top, double bottom, double near, double far);
void make_ortographic_matirxf(matrix4x4f *out, float right, float left, float top, float bottom, float near, float far);

#endif