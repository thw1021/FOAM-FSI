
/*
 * Author
 *   David Blom, TU Delft. All rights reserved.
 *
 * Class
 *  Picard Integral Exponential Solver (PIES)
 */

#pragma once

#include "SDC.H"
#include <complex>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/constants/constants.hpp>
#include <numeric>

namespace sdc
{
    template<typename T>
    inline std::complex<T>
    exp( const std::complex<T> & x )
    {
        using std::exp; // use ADL
        T const & r = exp( x.real() );
        return std::polar( r, x.imag() );
    }

    template<typename precision>
    class PIES : public SDC
    {
        public:
            PIES(
                std::shared_ptr<SDCSolver> solver,
                scalar rho,
                scalar delta,
                scalar tol,
                int minSweeps,
                int maxSweeps
                );

            PIES(
                scalar rho,
                scalar delta,
                scalar tol
                );

            virtual ~PIES();

        private:
            void computeCoefficients();

            scalar rho;
            scalar delta;
    };
}

#include "PIES.tpp"
