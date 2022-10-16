#pragma once
#include <complex>

// complex numbers using directive
using comp = std::complex<double>;

// signal consts
namespace signaLib{
    const double PI = atan(1) * 4;
    const comp IMAG_J{0, 1};
    const comp IMAG_MINUS_J{0, -1};
}