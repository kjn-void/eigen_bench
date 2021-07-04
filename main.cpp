#include <benchmark/benchmark.h>
#include <vector>
#include <random>

#include "cpp_mat.hpp"
extern "C" {
    #include "c_mat.h"
}

constexpr uint32_t MAT_N = 1000;

float rnd_helper() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dist(-1, 1);
    return dist(gen);
}

void c_mat4(benchmark::State &state) {
    std::vector<float> r(4 * 4);
    std::vector<float> a(4 * 4);
    std::vector<float> b(4 * 4);

    std::generate(a.begin(), a.end(), rnd_helper);
    std::generate(b.begin(), b.end(), rnd_helper);
    while (state.KeepRunning()) {
        c_mat4_mul(r.data(), a.data(), b.data());
    }
}
BENCHMARK(c_mat4);

void c_matn(benchmark::State &state) {
    std::vector<float> r(MAT_N * MAT_N);
    std::vector<float> a(MAT_N * MAT_N);
    std::vector<float> b(MAT_N * MAT_N);

    std::generate(a.begin(), a.end(), rnd_helper);
    std::generate(b.begin(), b.end(), rnd_helper);
    while (state.KeepRunning()) {
        c_matn_mul(r.data(), a.data(), b.data(), MAT_N);
    }
}
BENCHMARK(c_matn);

void cpp_mat4(benchmark::State &state) {
    Matrix4f r(MAT_N, MAT_N);
    Matrix4f a = Matrix4f::Random();
    Matrix4f b = Matrix4f::Random();

    while (state.KeepRunning()) {
        cpp::mat4_mul(r, a, b);
    }
}
BENCHMARK(cpp_mat4);

void cpp_matn(benchmark::State &state) {
    MatrixXf r(MAT_N, MAT_N);
    MatrixXf a = MatrixXf::Random(MAT_N, MAT_N);
    MatrixXf b = MatrixXf::Random(MAT_N, MAT_N);

    while (state.KeepRunning()) {
        cpp::matn_mul(r, a, b);
    }
}
BENCHMARK(cpp_matn);

BENCHMARK_MAIN();
