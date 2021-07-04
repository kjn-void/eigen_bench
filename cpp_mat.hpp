#ifndef _CPP_MAT_H_
#define _CPP_MAT_H

#include <Eigen/Core>

using Eigen::Matrix4f;
using Eigen::MatrixXf;

namespace cpp {
    void mat4_mul(Matrix4f &r, const Matrix4f &a, const Matrix4f &b);

    void matn_mul(MatrixXf &r, const MatrixXf &a, const MatrixXf &b);
}

#endif
