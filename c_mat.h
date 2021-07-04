#ifndef _C_MAT_H_
#define _C_MAT_H_

#include <stdint.h>

void c_mat4_mul(float *r, const float *a, const float *b);

void c_matn_mul(float *r, const float *a, const float *b, uint32_t);

#endif
