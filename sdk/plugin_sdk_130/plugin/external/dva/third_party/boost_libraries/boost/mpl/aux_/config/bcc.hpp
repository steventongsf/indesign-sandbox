
#ifndef BOOST_MPL_AUX_CONFIG_BCC_HPP_INCLUDED
#define BOOST_MPL_AUX_CONFIG_BCC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: //depot/devtech/14.0/plugin/external/dva/third_party/boost_libraries/boost/mpl/aux_/config/bcc.hpp#2 $
// $Date: 2018/09/10 $
// $Revision: #2 $

#include <boost/mpl/aux_/config/workaround.hpp>

#if    !defined(BOOST_MPL_CFG_BCC590_WORKAROUNDS) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE) \
    && BOOST_WORKAROUND(__BORLANDC__, >= 0x590) \
    && BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x610))

#   define BOOST_MPL_CFG_BCC590_WORKAROUNDS

#endif

#endif // BOOST_MPL_AUX_CONFIG_BCC_HPP_INCLUDED
