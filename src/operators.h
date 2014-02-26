#ifdef __cplusplus

//#include <libmcm/vectors.h>
//#include <libmcm/matrix.h>
#include <iostream>

#ifndef LIBMCM_EPS_FLOAT
#define LIBMCM_EPS_FLOAT 1e-6
#endif
#ifndef LIBMCM_EPS_DOUBLE
#define LIBMCM_EPS_DOUBLE 1e-10
#endif

/********************************* OPERATORS FOR VEC2F *********************************/

inline vec2f operator+(const vec2f &lhs, const vec2f &rhs) {
	vec2f out;
	add_components_vec2f(&out, &lhs, &rhs);
	
	return out;
}

inline vec2f operator-(const vec2f &lhs, const vec2f &rhs) {
	vec2f out;
	sub_components_vec2f(&out, &lhs, &rhs);
	
	return out;
}

inline vec2f operator-(const vec2f &vec) {
	const vec2f inv = vec2f(-vec.x, -vec.y);
	
	return inv;
}

inline vec2f operator*(const vec2f &lhs, float rhs) {
	vec2f out;
	mul_vec2f_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec2f operator*(const vec2f &lhs, const vec2f &rhs) {
	vec2f out;
	mul_components_vec2f(&out, &lhs, &rhs);
	
	return out;
}

inline vec2f operator/(const vec2f &lhs, float rhs) {
	vec2f out;
	div_vec2f_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec2f operator/(const vec2f &lhs, const vec2f &rhs) {
	vec2f out;
	div_components_vec2f(&out, &lhs, &rhs);
	
	return out;
}

inline float operator|(const vec2f &lhs, const vec2f &rhs) {
	return dot_vec2f(&lhs, &rhs);
}

inline bool operator==(const vec2f &lhs, const vec2f &rhs) {
	return equal_under_eps_vec2f(&lhs, &rhs, LIBMCM_EPS_FLOAT);
}

inline std::ostream& operator<<(std::ostream &out, const vec2f &vec) {
	out << "(" << vec.x << " " << vec.y << ")";
	return out;
}


/********************************* OPERATORS FOR VEC2D *********************************/
inline vec2d operator+(const vec2d &lhs, const vec2d &rhs) {
	vec2d out;
	add_components_vec2d(&out, &lhs, &rhs);
	
	return out;
}

inline vec2d operator-(const vec2d &lhs, const vec2d &rhs) {
	vec2d out;
	sub_components_vec2d(&out, &lhs, &rhs);
	
	return out;
}

inline vec2d operator-(const vec2d &vec) {
	const vec2d inv = vec2d(-vec.x, -vec.y);
	
	return inv;
}

inline vec2d operator*(const vec2d &lhs, double rhs) {
	vec2d out;
	mul_vec2d_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec2d operator*(const vec2d &lhs, const vec2d &rhs) {
	vec2d out;
	mul_components_vec2d(&out, &lhs, &rhs);
	
	return out;
}

inline vec2d operator/(const vec2d &lhs, double rhs) {
	vec2d out;
	div_vec2d_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec2d operator/(const vec2d &lhs, const vec2d &rhs) {
	vec2d out;
	div_components_vec2d(&out, &lhs, &rhs);
	
	return out;
}

inline float operator|(const vec2d &lhs, const vec2d &rhs) {
	return dot_vec2d(&lhs, &rhs);
}

inline bool operator==(const vec2d &lhs, const vec2d &rhs) {
	return equal_under_eps_vec2d(&lhs, &rhs, LIBMCM_EPS_DOUBLE);
}

inline std::ostream& operator<<(std::ostream &out, const vec2d &vec) {
	out << "(" << vec.x << " " << vec.y << ")";
	return out;
}


/********************************* OPERATORS FOR VEC3F *********************************/
inline vec3f operator+(const vec3f &lhs, const vec3f &rhs) {
	vec3f out;
	add_components_vec3f(&out, &lhs, &rhs);
	
	return out;
}

inline vec3f operator-(const vec3f &lhs, const vec3f &rhs) {
	vec3f out;
	sub_components_vec3f(&out, &lhs, &rhs);
	
	return out;
}

inline vec3f operator-(const vec3f &vec) {
	const vec3f inv = vec3f(-vec.x, -vec.y, -vec.z);
	
	return inv;
}

inline vec3f operator*(const vec3f &lhs, float rhs) {
	vec3f out;
	mul_vec3f_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec3f operator*(const vec3f &lhs, const vec3f &rhs) {
	vec3f out;
	mul_components_vec3f(&out, &lhs, &rhs);
	
	return out;
}

inline vec3f operator/(const vec3f &lhs, float rhs) {
	vec3f out;
	div_vec3f_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec3f operator/(const vec3f &lhs, const vec3f &rhs) {
	vec3f out;
	div_components_vec3f(&out, &lhs, &rhs);
	
	return out;
}

inline float operator|(const vec3f &lhs, const vec3f &rhs) {
	return dot_vec3f(&lhs, &rhs);
}

inline bool operator==(const vec3f &lhs, const vec3f &rhs) {
	return equal_under_eps_vec3f(&lhs, &rhs, LIBMCM_EPS_FLOAT);
}

inline std::ostream& operator<<(std::ostream &out, const vec3f &vec) {
	out << "(" << vec.x << " " << vec.y << " " << vec.z << ")";
	return out;
}

/********************************* OPERATORS FOR VEC3D *********************************/
inline vec3d operator+(const vec3d &lhs, const vec3d &rhs) {
	vec3d out;
	add_components_vec3d(&out, &lhs, &rhs);
	
	return out;
}

inline vec3d operator-(const vec3d &lhs, const vec3d &rhs) {
	vec3d out;
	sub_components_vec3d(&out, &lhs, &rhs);
	
	return out;
}

inline vec3d operator-(const vec3d &vec) {
	const vec3d inv = vec3d(-vec.x, -vec.y, -vec.z);
	
	return inv;
}

inline vec3d operator*(const vec3d &lhs, double rhs) {
	vec3d out;
	mul_vec3d_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec3d operator*(const vec3d &lhs, const vec3d &rhs) {
	vec3d out;
	mul_components_vec3d(&out, &lhs, &rhs);
	
	return out;
}

inline vec3d operator/(const vec3d &lhs, double rhs) {
	vec3d out;
	div_vec3d_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec3d operator/(const vec3d &lhs, const vec3d &rhs) {
	vec3d out;
	div_components_vec3d(&out, &lhs, &rhs);
	
	return out;
}

inline float operator|(const vec3d &lhs, const vec3d &rhs) {
	return dot_vec3d(&lhs, &rhs);
}

inline bool operator==(const vec3d &lhs, const vec3d &rhs) {
	return equal_under_eps_vec3d(&lhs, &rhs, LIBMCM_EPS_DOUBLE);
}

inline std::ostream& operator<<(std::ostream &out, const vec3d &vec) {
	out << "(" << vec.x << " " << vec.y << " " << vec.z << ")";
	return out;
}



/********************************* OPERATORS FOR VEC4F *********************************/
inline vec4f operator+(const vec4f &lhs, const vec4f &rhs) {
	vec4f out;
	add_components_vec4f(&out, &lhs, &rhs);
	
	return out;
}

inline vec4f operator-(const vec4f &lhs, const vec4f &rhs) {
	vec4f out;
	sub_components_vec4f(&out, &lhs, &rhs);
	
	return out;
}

inline vec4f operator-(const vec4f &vec) {
	const vec4f inv = vec4f(-vec.x, -vec.y, -vec.z, -vec.w);
	
	return inv;
}

inline vec4f operator*(const vec4f &lhs, float rhs) {
	vec4f out;
	mul_vec4f_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec4f operator*(const vec4f &lhs, const vec4f &rhs) {
	vec4f out;
	mul_components_vec4f(&out, &lhs, &rhs);
	
	return out;
}

inline vec4f operator/(const vec4f &lhs, float rhs) {
	vec4f out;
	div_vec4f_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec4f operator/(const vec4f &lhs, const vec4f &rhs) {
	vec4f out;
	div_components_vec4f(&out, &lhs, &rhs);
	
	return out;
}

inline float operator|(const vec4f &lhs, const vec4f &rhs) {
	return dot_vec4f(&lhs, &rhs);
}

inline bool operator==(const vec4f &lhs, const vec4f &rhs) {
	return equal_under_eps_vec4f(&lhs, &rhs, LIBMCM_EPS_FLOAT);
}

inline std::ostream& operator<<(std::ostream &out, const vec4f &vec) {
	out << "(" << vec.x << " " << vec.y << " " << vec.z << " " << vec.w << ")";
	return out;
}


/********************************* OPERATORS FOR VEC4D *********************************/
inline vec4d operator+(const vec4d &lhs, const vec4d &rhs) {
	vec4d out;
	add_components_vec4d(&out, &lhs, &rhs);
	
	return out;
}

inline vec4d operator-(const vec4d &lhs, const vec4d &rhs) {
	vec4d out;
	sub_components_vec4d(&out, &lhs, &rhs);
	
	return out;
}

inline vec4d operator-(const vec4d &vec) {
	const vec4d inv = vec4d(-vec.x, -vec.y, -vec.z, -vec.w);
	
	return inv;
}

inline vec4d operator*(const vec4d &lhs, double rhs) {
	vec4d out;
	mul_vec4d_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec4d operator*(const vec4d &lhs, const vec4d &rhs) {
	vec4d out;
	mul_components_vec4d(&out, &lhs, &rhs);
	
	return out;
}

inline vec4d operator/(const vec4d &lhs, double rhs) {
	vec4d out;
	div_vec4d_by_scalar(&out, &lhs, rhs);
	
	return out;
}

inline vec4d operator/(const vec4d &lhs, const vec4d &rhs) {
	vec4d out;
	div_components_vec4d(&out, &lhs, &rhs);
	
	return out;
}

inline float operator|(const vec4d &lhs, const vec4d &rhs) {
	return dot_vec4d(&lhs, &rhs);
}

inline bool operator==(const vec4d &lhs, const vec4d &rhs) {
	return equal_under_eps_vec4d(&lhs, &rhs, LIBMCM_EPS_DOUBLE);
}

inline std::ostream& operator<<(std::ostream &out, const vec4d &vec) {
	out << "(" << vec.x << " " << vec.y << " " << vec.z << " " << vec.w << ")";
	return out;
}



/********************************* TEMPLATE OPERATORS *********************************/
template<typename T>
inline T operator+=(T &lhs, const T &rhs) {
	lhs = lhs + rhs;
	return lhs;
}

template<typename T>
inline T operator-=(T &lhs, const T &rhs) {
	lhs = lhs - rhs;
	return lhs;
}

// template<typename T, typename S>
// inline T operator*(const S lhs, const T &rhs) {
// 	return rhs * lhs;
// }

template<typename T, typename S>
inline T operator*=(T &lhs, const S &rhs) {
	lhs = lhs * rhs;
	return lhs;
}

// template<typename T, typename S>
// inline T operator/(const S lhs, const T &rhs) {
// 	return rhs / lhs;
// }

template<typename T, typename S>
inline T operator/=(T &lhs, const S &rhs) {
	lhs = lhs / rhs;
	return lhs;
}

template<typename T>
inline bool operator!=(const T &lhs, const T &rhs) {
	return !(lhs == rhs);
}

#endif
