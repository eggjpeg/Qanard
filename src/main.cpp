#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor-blas/xlinalg.hpp>

int main() {
  xt::xarray<double> A
    {{1., 0., 1.},
     {2., 1., 1.},
     {0., 1., 1.},
     {1., 1., 2.}};

  xt::xarray<double> B
    {{1., 2., 1.},
     {2., 3., 1.},
     {4., 2., 2.}};

  auto AB = xt::linalg::dot(A, B);

  std::cout << AB << "\n";

  return 0;
}

