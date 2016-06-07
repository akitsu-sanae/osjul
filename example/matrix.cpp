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
    std::cout << std::boolalpha;

    std::cout << osjul::la::matrix<double, 2, 2> {{
        {1, 4},
        {5, 6}
    }}.is_symmetry() << std::endl;

    std::cout << osjul::la::matrix<double, 2, 2> {{
        {3, 1},
        {1, 3}
    }}.is_symmetry() << std::endl;

    std::cout << osjul::la::matrix<double, 3, 3> {{
        {1, 3, 4},
        {5, 3, 1},
        {5, 1, 3}
    }}.is_symmetry() << std::endl;

    std::cout << osjul::la::matrix<double, 3, 3> {{
        {1, 3, 4},
        {3, 5, 9},
        {4, 9, 0}
    }}.is_symmetry() << std::endl;

    std::cout << osjul::la::matrix<double, 3, 4> {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    }}.transpose() << std::endl;

    std::cout << osjul::la::matrix<double, 3, 3>::identity() << std::endl;

    std::cout << osjul::la::matrix<double, 4, 4>{{
        {1/2.0, 1/2.0, 1/2.0, 1/2.0},
        {1/2.0, -1/2.0, 1/2.0, -1/2.0},
        {1/2.0, 1/2.0, -1/2.0, -1/2.0},
        {1/2.0, -1/2.0, -1/2.0, 1/2.0}
    }}.is_orthogonal() << std::endl;

    std::cout << osjul::la::matrix<double, 4, 4>{{
        {1/4.0, 1/4.0, 1/4.0, 1/4.0},
        {1/4.0, -1/4.0, 1/4.0, -1/4.0},
        {1/4.0, 1/4.0, -1/4.0, -1/4.0},
        {1/4.0, -1/4.0, -1/4.0, 1/4.0}
    }}.is_orthogonal() << std::endl;

    std::cout << osjul::la::matrix<double, 3, 3>{{
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    }}.child(0, 0) << std::endl;

    // 1
    std::cout << osjul::la::det(osjul::la::matrix<double, 2, 2> {{
        {1, 0},
        {0, 1}
    }}) << std::endl;


    // 3
    std::cout << osjul::la::det(osjul::la::matrix<double, 2, 2> {{
        {3, 9},
        {2, 7}
    }}) << std::endl;

}

