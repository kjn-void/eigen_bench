# eigen_bench

Very simple comparison between naive C for-loop style matrix
multiplication vs Eigen SIMD optimized library.

# Requirements

	* CMake 3.0 or later
	* Google benchmark
	* Eigen library
	* pkg-config that can find Google benchmark and Eigen

# Example run

Machine is an Intel NUC with i7-8559U

```
kjonsson@bean:~/eigen_bench$ ./bootstrap.sh
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Looking for pthread_create
-- Looking for pthread_create - not found
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE
-- Found PkgConfig: /usr/bin/pkg-config (found version "0.29.1")
-- Checking for module 'benchmark'
--   Found benchmark, version 1.5.5.14
-- Checking for module 'eigen3'
--   Found eigen3, version 3.3.4
-- Configuring done
-- Generating done
-- Build files have been written to: /home/kjonsson/eigen_bench/build
Scanning dependencies of target eigen
[ 25%] Building CXX object CMakeFiles/eigen.dir/main.cpp.o
[ 50%] Building CXX object CMakeFiles/eigen.dir/cpp_mat.cpp.o
[ 75%] Building C object CMakeFiles/eigen.dir/c_mat.c.o
[100%] Linking CXX executable eigen
[100%] Built target eigen
kjonsson@bean:~/eigen_bench$ cd build/
kjonsson@bean:~/eigen_bench/build$ ./eigen --benchmark_min_time=3
2021-07-04T17:26:30+02:00
Running ./eigen
Run on (8 X 4500 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
Load Average: 0.00, 0.04, 0.07
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
c_mat4           23.4 ns         23.4 ns    175700836
c_matn      916196543 ns    916136039 ns            5
cpp_mat4         4.70 ns         4.70 ns    897026206
cpp_matn     86841916 ns     86836076 ns           49
```
