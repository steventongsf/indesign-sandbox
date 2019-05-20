/* boost random/mersenne_twister.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Copyright Steven Watanabe 2010
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id: //depot/devtech/14.0/plugin/external/dva/third_party/boost_libraries/boost/random/detail/generator_seed_seq.hpp#2 $
 *
 */

#ifndef BOOST_RANDOM_DETAIL_GENERATOR_SEED_SEQ_HPP_INCLUDED
#define BOOST_RANDOM_DETAIL_GENERATOR_SEED_SEQ_HPP_INCLUDED

namespace boost {
namespace random {
namespace detail {

template<class Generator>
class generator_seed_seq {
public:
    generator_seed_seq(Generator& g) : gen(&g) {}
    template<class It>
    void generate(It first, It last) {
        for(; first != last; ++first) {
            *first = (*gen)();
        }
    }
private:
    Generator* gen;
};

}
}
}

#endif
