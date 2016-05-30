#include "../osjul/liner_algebra.hpp"


int main() {
    osjul::la::matrix<double, 2, 2> m {{
        {1, 0},
        {0, 1}
    }};
    osjul::la::matrix<double, 1, 2> n {{
        {4},
        {2}
    }};
    std::cout << m * n << std::endl;


    osjul::la::matrix<double, 2, 2> a {{
        {2, -1},
        {-3, 4}
    }};
    osjul::la::matrix<double, 1, 2> b {{
        {1}, {2}
    }};
    std::cout << a*b << std::endl;

    osjul::la::matrix<double, 2, 2> c {{
        {1, -1},
        {-2, 3}
    }};
    osjul::la::matrix<double, 2, 2> d {{
        {1, 2},
        {3, 4}
    }};
    std::cout << c * d << std::endl;

    osjul::la::matrix<double, 2, 1> e {{
        {1, 2}
    }};
    osjul::la::matrix<double, 2, 2> f {{
        {2, -1},
        {-3, 4}
    }};
    std::cout << e * f << std::endl;
}
