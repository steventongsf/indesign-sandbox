/* boost random/detail/config.hpp header file
 *
 * Copyright Steven Watanabe 2009
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id: //depot/devtech/14.0/plugin/external/dva/third_party/boost_libraries/boost/random/detail/config.hpp#2 $
 */

#include <boost/config.hpp>

#if (defined(BOOST_NO_OPERATORS_IN_NAMESPACE) || defined(BOOST_NO_MEMBER_TEMPLATE_FRIENDS)) \
    && !defined(BOOST_MSVC)
    #define BOOST_RANDOM_NO_STREAM_OPERATORS
#endif
