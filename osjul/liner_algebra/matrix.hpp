/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_LINER_ALGEBRA_MATRIX_HPP
#define OSJUL_LINER_ALGEBRA_MATRIX_HPP

#include <cfloat>
#include <cstddef>
#include <cmath>
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

    matrix<value_type, Height, Width> transpose() const {
        matrix<value_type, Height, Width> result;
        for (int y=0; y<Height; y++) {
            for (int x=0; x<Width; x++) {
                result.at(y, x) = this->at(x, y);
            }
        }
        return result;
    }

    matrix<value_type, Width-1, Height-1> child(int x, int y) const {
        if (!is_squared())
            throw not_squared_exception{};
        matrix<value_type, Width-1, Height-1> result;
        int ty = 0;
        for (int y_=0; y_<Height; y_++) {
            if (y_ == y)
                continue;
            int tx = 0;
            for (int x_=0; x_<Width; x_++) {
                if (x_ == x)
                    continue;
                result.at(tx, ty) = at(x_, y_);
                    tx++;
            }
            ty++;
        }
        return result;
    }

    struct not_squared_exception {};
    struct not_symmetry_exception {};
    struct not_orthogonal_exception {};

    static bool is_squared() {
        return Width == Height;
    }
    bool is_symmetry() const {
        for (int y=0; y<Height; y++) {
            for (int x=y+1; x<Width; x++) {
                if (at(x, y) != at(y, x))
                    return false;
            }
        }
        return true;
    }
    bool is_orthogonal() const {
        // A * (A^t) == I
        auto tmp = (*this) * this->transpose();
        return tmp == matrix<value_type, Width, Height>::identity();
    }

    static matrix<value_type, Width, Height> identity() {
        if (!is_squared())
            throw not_squared_exception{};
        matrix<value_type, Width, Height> result;
        for (int i=0; i<Width; i++)
            result.at(i, i) = static_cast<value_type>(1.0);
        return result;
    }
    value_type elems[Height][Width];
};

template<typename T, std::size_t N>
inline static T det(osjul::la::matrix<T, N, N> const& m) {
    auto result = static_cast<typename osjul::la::matrix<T, N, N>::value_type>(0);
    int k = 1;
    for (int i=0; i<osjul::la::matrix<T, N, N>::Width; i++) {
        result += k * m.at(0, i) * det(m.child(0, i));
        k *= -1;
    }
}
template<typename T>
inline static T det(osjul::la::matrix<T, 1, 1> const& m) {
    return m.at(0, 0);
}

template<typename T, std::size_t W, std::size_t H>
inline static bool operator==(osjul::la::matrix<T, W, H> const& lhs, osjul::la::matrix<T, W, H> const& rhs) {
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            if (std::abs(lhs.at(x, y) - rhs.at(x, y)) > DBL_EPSILON) {
                return false;
            }
        }
    }
    return true;
}

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

