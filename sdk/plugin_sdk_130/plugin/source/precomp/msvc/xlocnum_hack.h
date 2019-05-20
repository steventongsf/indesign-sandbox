#if _MSC_VER < 1900
	#include "xlocnum_hack_vs2010-2013.h"
#elif _MSC_VER == 1900
	#include "xlocnum_hack_vs2015.h"
#elif _MSC_VER >= 1910 && _MSC_VER < 1914
	#include "xlocnum_hack_vs2017.h"
#elif _MSC_VER == 1914 // VS 2017 version 15.7
	#include "xlocnum_hack_vs2017_15_7.h"
#elif _MSC_VER >= 1915 && _MSC_VER < 1920 // VS 2017 version 15.8 and higher
	#include "xlocnum_hack_vs2017_15_8.h"
#else
	#error "You need to update xlocnum hack header by copying over the header from your Visual Studio installation and applying the same changes as to the previous versions. Be careful, this header also changes between minor versions of Visual Studio."
#endif