
#include <Eigen/Dense>

#include <boost/preprocessor/repetition/repeat.hpp>

#include <chrono>
#include <iostream>
#include <cstdlib>

// Creates a test matrix, as a diagonal square matrix with positive > 0 random
// values.
template <typename T, int N>
void create_test_matrix(Eigen::Matrix<T, N, N>& M)
{
  for (size_t i = 0; i < N; ++i)
  {
    M(i, i) = std::rand() + 1e-3;
  }
}

// Runs a self-adjoint eigensolver to obtain the eigenvalues and eigenvectors
// of a square matrix.
template <typename T, int N>
bool selfadjoint_eigensolver_test(const Eigen::Matrix<T, N, N>& M)
{
  Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, N, N> > eigensolver(M);

  return eigensolver.info() == Eigen::Success;
}

template <typename T, int N>
void test()
{
  typedef std::chrono::high_resolution_clock Time;
  typedef std::chrono::duration<double> Duration;

  Eigen::Matrix<T, N, N> M;
  create_test_matrix(M);

  const auto start = Time::now();

  selfadjoint_eigensolver_test(M);

  const auto end = Time::now();

  const auto dt = Duration(end - start).count();

  std::cout << N << " " << dt << std::endl;
}

#define TEST(z, n, _) test<double, n+1>();

int main(int argc, char** argv)
{
  std::cout << "# N = NxN Matrix size\n"
            << "# t = Time [s] to compute SelfAdjointEigenSolver\n"
            << "#\n"
            << "# N t" << std::endl;

  BOOST_PP_REPEAT(15, TEST, _)

  return EXIT_SUCCESS;
}

