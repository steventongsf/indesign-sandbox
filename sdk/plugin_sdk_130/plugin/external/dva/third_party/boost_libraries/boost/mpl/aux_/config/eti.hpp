
#ifndef BOOST_MPL_AUX_CONFIG_ETI_HPP_INCLUDED
#define BOOST_MPL_AUX_CONFIG_ETI_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: //depot/devtech/14.0/plugin/external/dva/third_party/boost_libraries/boost/mpl/aux_/config/eti.hpp#2 $
// $Date: 2018/09/10 $
// $Revision: #2 $

#include <boost/mpl/aux_/config/msvc.hpp>
#include <boost/mpl/aux_/config/workaround.hpp>

// flags for MSVC 6.5's so-called "early template instantiation bug"
#if    !defined(BOOST_MPL_CFG_MSVC_60_ETI_BUG) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE) \
    && BOOST_WORKAROUND(BOOST_MSVC, < 1300)

#   define BOOST_MPL_CFG_MSVC_60_ETI_BUG

#endif

#if    !defined(BOOST_MPL_CFG_MSVC_70_ETI_BUG) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE) \
    && BOOST_WORKAROUND(BOOST_MSVC, == 1300)

#   define BOOST_MPL_CFG_MSVC_70_ETI_BUG

#endif

#if    !defined(BOOST_MPL_CFG_MSVC_ETI_BUG) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE) \
    && ( defined(BOOST_MPL_CFG_MSVC_60_ETI_BUG) \
        || defined(BOOST_MPL_CFG_MSVC_70_ETI_BUG) \
        )

#   define BOOST_MPL_CFG_MSVC_ETI_BUG

#endif

#endif // BOOST_MPL_AUX_CONFIG_ETI_HPP_INCLUDED
