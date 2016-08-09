/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_CACHE_HPP
#define OSJUL_CACHE_HPP

namespace osjul {

template<typename Result>
struct cache {
    using result_type = Result;

    result_type value() {
        if (is_need_update) {
            calc();
            is_need_update = false;
        }
        return result;
    }
    virtual void calc() = 0;
protected:
    void need_update() {
        is_need_update = true;
    }
    result_type result;
private:
    bool is_need_update = true;
};


}

#endif

