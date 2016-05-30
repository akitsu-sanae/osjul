/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_LINER_ALGEBRA_MATRIX_HPP
#define OSJUL_LINER_ALGEBRA_MATRIX_HPP

#include <cstddef>
#include <array>
#include <iostream>

namespace osjul {
namespace la {

template<typename T, std::size_t W, std::size_t H>
struct matrix {
    using value_type = T;
    static constexpr std::size_t Width = W;
    static constexpr std::size_t Height = H;
    using this_type = matrix<value_type, Width, Height>;

    struct invalid_index_exception {};

    value_type const& at(int x, int y) const {
        if (x < 0 || x > Width)
            throw invalid_index_exception{};
        if (y < 0 || y > Height)
            throw invalid_index_exception{};
        return elems[y][x];
    }
    value_type& at(int x, int y) {
        if (x < 0 || x > Width)
            throw invalid_index_exception{};
        if (y < 0 || y > Height)
            throw invalid_index_exception{};

        return elems[y][x];
    }

    this_type operator+(this_type const& rhs) const {
        this_type result = *this;
        for (int y=0; y<Height; y++) {
            for (int x=0; x<Width; x++) {
                result.at(x, y) = rhs.at(x, y);
            }
        }
        return result;
    }

    template<std::size_t I>
    matrix<value_type, I, Height> operator*(matrix<value_type, I, Width> const& rhs) const {
        matrix<value_type, I, Height> result = {};
        for (int y=0; y<Height; y++) {
            for (int x=0; x<I; x++) {
                for (int i=0; i<Width; i++)
                    result.at(x, y) += this->at(i, y) * rhs.at(x, i);
            }
        }
        return result;
    }


    value_type elems[Height][Width];
};

template<typename T, std::size_t W, std::size_t H>
inline static std::ostream& operator<<(std::ostream& os, matrix<T, W, H> const& m) {
    os << W << " x " << H << " matrix" << std::endl;
    for (std::size_t y=0; y<H; y++) {
        std::cout << "    ";
        for (std::size_t x=0; x<W; x++) {
            std::cout << m.at(x, y) << ", ";
        }
        std::cout << std::endl;
    }
}


}
}

#endif

