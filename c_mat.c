#include "c_mat.h"

void c_mat4_mul(float *r, const float *a, const float *b)
{
    for(uint32_t i = 0; i < 4; i++) {    
        for(uint32_t j = 0; j < 4; j++) {
            r[i * 4 + j] = 0;
            for(uint32_t k = 0; k < 4; k++) {
                r[i * 4 + j] += a[i * 4 + k] * b[k * 4 + j];
            }    
        }    
    }
}    

void c_matn_mul(float *r, const float *a, const float *b, uint32_t n)
{
    for(uint32_t i = 0; i < n; i++) {    
        for(uint32_t j = 0; j < n; j++) {
            r[i *n + j] = 0;
            for(uint32_t k = 0; k < n; k++) {
                r[i * n + j] += a[i * n + k] * b[k * n + j];
            }    
        }    
    }
}    
