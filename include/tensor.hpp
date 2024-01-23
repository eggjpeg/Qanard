#include <xtensor/xarray.hpp>
#include <xtensor-blas/xlinalg.hpp>

#include <types.hpp>

class Tensor : public xt::xarray<Complex> {
  public:
    Tensor(const auto& t): xt::xarray<Complex>(t) {}

    Tensor kron(const Tensor& arg) const {
      return xt::linalg::kron(*this, arg);
    }

    Tensor operator*(const Tensor& arg) const {
      return this->kron(arg);
    }
};