
#ifndef BOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED
#define BOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: //depot/devtech/14.0/plugin/external/dva/third_party/boost_libraries/boost/mpl/aux_/config/has_apply.hpp#2 $
// $Date: 2018/09/10 $
// $Revision: #2 $

#include <boost/mpl/aux_/config/has_xxx.hpp>
#include <boost/mpl/aux_/config/msvc.hpp>
#include <boost/mpl/aux_/config/workaround.hpp>

#if !defined(BOOST_MPL_CFG_NO_HAS_APPLY) \
    && (   defined(BOOST_MPL_CFG_NO_HAS_XXX) \
        || BOOST_WORKAROUND(__EDG_VERSION__, < 300) \
        || BOOST_WORKAROUND(BOOST_MSVC, <= 1300) \
        || BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3202)) \
        )

#   define BOOST_MPL_CFG_NO_HAS_APPLY

#endif

#endif // BOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED