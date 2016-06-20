/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>
#include <osjul/report_generator.hpp>

int main() {
    using namespace osjul::report_generator;
    std::cout <<
        report<paper> {
            header{"構文解析概論第３回レポート 学籍番号2014114514 秋津 早苗"},
                footer{"The End of Report"},
                body {
                    "レポートの中身だよ！！"
                }
        }.to_markdown();
}

