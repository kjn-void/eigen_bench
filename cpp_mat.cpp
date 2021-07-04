#include "cpp_mat.hpp"
#include <algorithm>

namespace cpp {

void mat4_mul(Matrix4f &r, const Matrix4f &a, const Matrix4f &b)
{
    r = a * b;
}

void matn_mul(MatrixXf &r, const MatrixXf &a, const MatrixXf &b)
{
    r = a * b;
}

}