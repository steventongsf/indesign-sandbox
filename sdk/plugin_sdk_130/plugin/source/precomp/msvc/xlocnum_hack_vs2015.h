// xlocnum internal header (from <locale>)
#pragma once
#ifndef _XLOCNUM_
#define _XLOCNUM_

// Define a very specific symbol so we can detect if this is our 'fixed' hack version or the original MS Visual Studio 2015 version.
// This has originally been based on the MS Visual Studio 2010 -- this is now a refresh based on the MS Visual Studio 2015 header.
// All changes from the original version are commented using @CL.
#define XLOCNUM_HACK_TO_FIX_NUM_PUNCT_IN_OUR_UTF8_STREAM

#ifndef RC_INVOKED
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <streambuf>

// @CL 629817
#ifndef _NOEXCEPT
#define _NOEXCEPT
#endif

 #pragma pack(push,_CRT_PACKING)
 #pragma warning(push,3)
 #pragma push_macro("new")
 #undef new

 // @CL 939278
 #ifndef _NEW_CRT
	#define _NEW_CRT new
	#define _DELETE_CRT(ptr)		delete (ptr)
	#define _DELETE_CRT_VEC(ptr)	delete[] (ptr)
	_STD_BEGIN
	typedef bool _Bool;
	_STD_END
#endif
 
 #pragma warning(disable: 4189 4275)

		// TEXT-TO-NUMERIC CONVERSION FUNCTIONS

 #if !defined(MRTDLL) && !defined(_M_CEE_PURE)
_C_LIB_DECL
 #endif /* !defined(MRTDLL) etc. */

extern _CRTIMP2_PURE float __CLRCALL_PURE_OR_CDECL _Stofx(const char *,
	_Out_opt_ _Deref_post_opt_valid_ char **,
	long, int *);
extern _CRTIMP2_PURE double __CLRCALL_PURE_OR_CDECL _Stodx(const char *,
	_Out_opt_ _Deref_post_opt_valid_ char **,
	long, int *);
extern _CRTIMP2_PURE long double __CLRCALL_PURE_OR_CDECL _Stoldx(const char *,
	_Out_opt_ _Deref_post_opt_valid_ char **,
	long, int *);
extern _CRTIMP2_PURE long __CLRCALL_PURE_OR_CDECL _Stolx(const char *,
	_Out_opt_ _Deref_post_opt_valid_ char **,
	int, int *);
extern _CRTIMP2_PURE unsigned long __CLRCALL_PURE_OR_CDECL _Stoulx(const char *,
	_Out_opt_ _Deref_post_opt_valid_ char **,
	int, int *);
extern _CRTIMP2_PURE _LONGLONG __CLRCALL_PURE_OR_CDECL _Stollx(const char *,
	_Out_opt_ _Deref_post_opt_valid_ char **,
	int, int *);
extern _CRTIMP2_PURE _ULONGLONG __CLRCALL_PURE_OR_CDECL _Stoullx(const char *,
	_Out_opt_ _Deref_post_opt_valid_ char **,
	int, int *);

 #if !defined(MRTDLL) && !defined(_M_CEE_PURE)
_END_C_LIB_DECL
 #endif /* !defined(MRTDLL) etc. */

_STD_BEGIN

	// FUNCTION _Stodx_v2
inline double _Stodx_v2(const char *_Str, char **_Endptr, int _Pten, int *_Perr)
	{	// convert string to double
	int& _Errno_ref = errno;	// Nonzero cost, pay it once
	const int _Orig = _Errno_ref;

	_Errno_ref = 0;
	double _Val = _CSTD strtod(_Str, _Endptr);
	*_Perr = _Errno_ref;
	_Errno_ref = _Orig;

	if (_Pten != 0)
		_Val *= _CSTD pow(10.0, static_cast<double>(_Pten));

	return (_Val);
	}

	// FUNCTION _Stofx_v2
inline float _Stofx_v2(const char *_Str, char **_Endptr, int _Pten, int *_Perr)
	{	// convert string to float
	int& _Errno_ref = errno;	// Nonzero cost, pay it once
	const int _Orig = _Errno_ref;

	_Errno_ref = 0;
	float _Val = _CSTD strtof(_Str, _Endptr);
	*_Perr = _Errno_ref;
	_Errno_ref = _Orig;

	if (_Pten != 0)
		_Val *= _CSTD powf(10.0f, static_cast<float>(_Pten));

	return (_Val);
	}

// TEMPLATE FUNCTION _Find_elem
template<class _Elem> inline
	size_t _Find_elem(_Elem *_Base, _Elem _Ch)
	{	// lookup _Ch in NUL-terminated string _Base
	_Elem *_Ptr = _Base;
	for (; *_Ptr != (_Elem)0 && *_Ptr != _Ch; ++_Ptr)
		;
	return ((size_t)(_Ptr - _Base));
	}

inline wchar_t *_Maklocwcs(const wchar_t *_Ptr)
	{	// copy NTWCS to allocated storage
	size_t _Count = _CSTD wcslen(_Ptr) + 1;

	wchar_t *_Ptrdest = (wchar_t *)_calloc_dbg(_Count, sizeof (wchar_t),
		_CRT_BLOCK, __FILE__, __LINE__);

	if (!_Ptrdest)
		_Xbad_alloc();
	_CSTD wmemcpy(_Ptrdest, _Ptr, _Count);
	return (_Ptrdest);
	}

		// TEMPLATE CLASS numpunct
template<class _Elem>
	class numpunct
		: public locale::facet
	{	// facet for defining numeric punctuation text
public:
	typedef basic_string<_Elem, char_traits<_Elem>, allocator<_Elem> >
		string_type;
	typedef _Elem char_type;

	// @CL 260679: commented out _CRTIMP2_PURE - see XLOCNUM_HACK_TO_FIX_NUM_PUNCT_IN_OUR_UTF8_STREAM
	__PURE_APPDOMAIN_GLOBAL /*_CRTIMP2_PURE*/ static locale::id id;	// unique facet id

	_Elem decimal_point() const
		{	// return decimal point
		return (do_decimal_point());
		}

	_Elem thousands_sep() const
		{	// return thousands separator
		return (do_thousands_sep());
		}

	string grouping() const
		{	// return grouping string
		return (do_grouping());
		}

	string_type falsename() const
		{	// return name for false
		return (do_falsename());
		}

	string_type truename() const
		{	// return name for true
		return (do_truename());
		}

	explicit numpunct(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	// construct from current locale
		_BEGIN_LOCINFO(_Lobj)
			_Init(_Lobj);
			if (_Kseparator == 0)
				_Kseparator =	// NB: differs from "C" locale
					_MAKLOCCHR(_Elem, ',', _Lobj._Getcvt());
		_END_LOCINFO()
		}

	numpunct(const _Locinfo& _Lobj, size_t _Refs = 0, bool _Isdef = false)
		: locale::facet(_Refs)
		{	// construct from specified locale
		_Init(_Lobj, _Isdef);
		}

	static size_t _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	// return locale category mask and construct standard facet
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new numpunct<_Elem>(
				_Locinfo(_Ploc->c_str()), 0, true);
		return (_X_NUMERIC);
		}

protected:
	virtual __CLR_OR_THIS_CALL ~numpunct() _NOEXCEPT
		{	// destroy the object
		_Tidy();
		}

	numpunct(const char *_Locname, size_t _Refs = 0, bool _Isdef = false)
		: locale::facet(_Refs)
		{	// construct from specified locale
		_BEGIN_LOCINFO(_Lobj(_Locname))
			_Init(_Lobj, _Isdef);
		_END_LOCINFO()
		}

	template<class _Elem2>
		void _Getvals(_Elem2, const lconv *_Ptr, _Locinfo::_Cvtvec _Cvt)
		{	// get values
		_Dp = _MAKLOCCHR(_Elem2, _Ptr->decimal_point[0], _Cvt);
		_Kseparator = _MAKLOCCHR(_Elem2, _Ptr->thousands_sep[0], _Cvt);
		}

	template<>
		void _Getvals(wchar_t, const lconv *_Ptr, _Locinfo::_Cvtvec)
		{	// get values
		_Dp = (_Elem)_Ptr->_W_decimal_point[0];
		_Kseparator = (_Elem)_Ptr->_W_thousands_sep[0];
		}

	void _Init(const _Locinfo& _Lobj, bool _Isdef = false)
		{	// initialize from _Lobj
		const lconv *_Ptr = _Lobj._Getlconv();
		_Locinfo::_Cvtvec _Cvt = _Lobj._Getcvt();	// conversion information

		_Grouping = 0;
		_Falsename = 0;
		_Truename = 0;

		_TRY_BEGIN
		_Grouping = _MAKLOCSTR(char, _Isdef ? "" : _Ptr->grouping,
			_Lobj._Getcvt());
		_Falsename = _MAKLOCSTR(_Elem, _Lobj._Getfalse(), _Cvt);
		_Truename = _MAKLOCSTR(_Elem, _Lobj._Gettrue(), _Cvt);
		_CATCH_ALL
		_Tidy();
		_RERAISE;
		_CATCH_END

		if (_Isdef)
			{	// apply defaults for required facets
//			_Grouping = _MAKLOCSTR(char, "", _Cvt);
			_Dp = _MAKLOCCHR(_Elem, '.', _Cvt);
			_Kseparator = _MAKLOCCHR(_Elem, ',', _Cvt);
			}
		else
			_Getvals((_Elem)0, _Ptr, _Cvt);
		}

	virtual _Elem __CLR_OR_THIS_CALL do_decimal_point() const
		{	// return decimal point
		return (_Dp);
		}

	virtual _Elem __CLR_OR_THIS_CALL do_thousands_sep() const
		{	// return thousands separator
		return (_Kseparator);
		}

	virtual string __CLR_OR_THIS_CALL do_grouping() const
		{	// return grouping string
		return (string(_Grouping));
		}

	virtual string_type __CLR_OR_THIS_CALL do_falsename() const
		{	// return name for false
		return (string_type(_Falsename));
		}

	virtual string_type __CLR_OR_THIS_CALL do_truename() const
		{	// return name for true
		return (string_type(_Truename));
		}

private:
	void _Tidy()
		{	// free all storage
		_CSTD free((void *)_Grouping);
		_CSTD free((void *)_Falsename);
		_CSTD free((void *)_Truename);
		}

	const char *_Grouping;	// grouping string, "" for "C" locale
	_Elem _Dp;	// decimal point, '.' for "C" locale
	_Elem _Kseparator;	// thousands separator, '\0' for "C" locale
	const _Elem *_Falsename;	// name for false, "false" for "C" locale
	const _Elem *_Truename;	// name for true, "true" for "C" locale
	};

		// TEMPLATE CLASS numpunct_byname
template<class _Elem>
	class numpunct_byname
		: public numpunct<_Elem>
	{	// numpunct for named locale
public:
	explicit numpunct_byname(const char *_Locname, size_t _Refs = 0)
		: numpunct<_Elem>(_Locname, _Refs)
		{	// construct for named locale
		}

	explicit numpunct_byname(const string& _Str, size_t _Refs = 0)
		: numpunct<_Elem>(_Str.c_str(), _Refs)
		{	// construct for named locale
		}

protected:
	virtual __CLR_OR_THIS_CALL ~numpunct_byname() _NOEXCEPT
		{	// destroy the object
		}
	};

		// STATIC numpunct::id OBJECT
template<class _Elem>
	__PURE_APPDOMAIN_GLOBAL locale::id numpunct<_Elem>::id;

		// TEMPLATE CLASS num_get
template<class _Elem,
	class _InIt = istreambuf_iterator<_Elem, char_traits<_Elem> > >
	class num_get
		: public locale::facet
	{	// facet for converting text to encoded numbers
public:
	typedef numpunct<_Elem> _Mypunct;
	typedef basic_string<_Elem, char_traits<_Elem>, allocator<_Elem> >
		_Mystr;

	static size_t __CLRCALL_OR_CDECL _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	// return locale category mask and construct standard facet
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new num_get<_Elem, _InIt>(
				_Locinfo(_Ploc->c_str()));
		return (_X_NUMERIC);
		}

	__PURE_APPDOMAIN_GLOBAL static locale::id id;	// unique facet id

protected:
	virtual __CLR_OR_THIS_CALL ~num_get() _NOEXCEPT
		{	// destroy the object
		}

	void _Init(const _Locinfo&)
		{	// initialize from _Locinfo object
		}

public:
	explicit __CLR_OR_THIS_CALL num_get(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	// construct from current locale
		_BEGIN_LOCINFO(_Lobj)
			_Init(_Lobj);
		_END_LOCINFO()
		}

	__CLR_OR_THIS_CALL num_get(const _Locinfo& _Lobj, size_t _Refs = 0)
		: locale::facet(_Refs)
		{	// construct from specified locale
		_Init(_Lobj);
		}

	typedef _Elem char_type;
	typedef _InIt iter_type;

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase,	ios_base::iostate& _State,
			bool& _Val) const
		{	// get bool from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase,	ios_base::iostate& _State,
			unsigned short& _Val) const
		{	// get unsigned short from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase,	ios_base::iostate& _State,
			unsigned int& _Val) const
		{	// get unsigned int from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long& _Val) const
		{	// get long from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned long& _Val) const
		{	// get unsigned long from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			_LONGLONG& _Val) const
		{	// get long long from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			_ULONGLONG& _Val) const
		{	// get unsigned long long from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			float& _Val) const
		{	// get float from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			double& _Val) const
		{	// get double from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long double& _Val) const
		{	// get long double from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt __CLR_OR_THIS_CALL get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			void *& _Val) const
		{	// get void pointer from [_First, _Last) into _Val
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

protected:
	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			bool& _Val) const
		{	// get bool from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		int _Ans = -1;	// negative answer indicates failure

		if (_Iosbase.flags() & ios_base::boolalpha)
			{	// get false name or true name
			typedef typename _Mystr::size_type _Mystrsize;
			const _Mypunct& _Punct_fac = _USE(_Iosbase.getloc(), _Mypunct);
			_Mystr _Str((_Mystrsize)1, (char_type)0);
			_Str += _Punct_fac.falsename();
			_Str += (char_type)0;
			_Str += _Punct_fac.truename();	// construct "\0false\0true"
			_Ans = _Getloctxt(_First, _Last, (size_t)2, _Str.c_str());
			}
		else
			{	// get zero or nonzero integer
			char _Ac[_MAX_INT_DIG], *_Ep;
			int _Errno = 0;
			const unsigned long _Ulo = _CSTD _Stoulx(_Ac, &_Ep,
				_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
					_Iosbase.getloc()), &_Errno);
			if (_Ep != _Ac && _Errno == 0 && _Ulo <= 1)
				_Ans = _Ulo;
			}

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ans < 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans != 0;	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned short& _Val) const
		{	// get unsigned short from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_MAX_INT_DIG], *_Ep;
		int _Errno = 0;
		int _Base = _Getifld(_Ac, _First, _Last, _Iosbase.flags(),
			_Iosbase.getloc());	// gather field into _Ac
		char *_Ptr = _Ac[0] == '-' ? _Ac + 1 : _Ac;	// point past any sign
		const unsigned long _Ans =
			_CSTD _Stoulx(_Ptr, &_Ep, _Base, &_Errno);	// convert

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ptr || _Errno != 0 || USHRT_MAX < _Ans)
			_State |= ios_base::failbit;
		else
			_Val = (unsigned short)(_Ac[0] == '-'
				? 0 -_Ans : _Ans);	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned int& _Val) const
		{	// get unsigned int from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_MAX_INT_DIG], *_Ep;
		int _Errno = 0;
		int _Base = _Getifld(_Ac, _First, _Last, _Iosbase.flags(),
			_Iosbase.getloc());	// gather field into _Ac
		char *_Ptr = _Ac[0] == '-' ? _Ac + 1 : _Ac;	// point past any sign
		const unsigned long _Ans =
			_CSTD _Stoulx(_Ptr, &_Ep, _Base, &_Errno);	// convert

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ptr || _Errno != 0 || UINT_MAX < _Ans)
			_State |= ios_base::failbit;
		else
			_Val = _Ac[0] == '-' ? 0 -_Ans : _Ans;	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long& _Val) const
		{	// get long from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_MAX_INT_DIG], *_Ep;
		int _Errno = 0;
		const long _Ans = _CSTD _Stolx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	// gather field, convert

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned long& _Val) const
		{	// get unsigned long from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_MAX_INT_DIG], *_Ep;
		int _Errno = 0;
		const unsigned long _Ans = _CSTD _Stoulx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	// gather field, convert

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			_LONGLONG& _Val) const
		{	// get long long from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_MAX_INT_DIG], *_Ep;
		int _Errno = 0;
		const _LONGLONG _Ans = _CSTD _Stollx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	// gather field, convert

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			_ULONGLONG& _Val) const
		{	// get unsigned long long from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_MAX_INT_DIG], *_Ep;
		int _Errno = 0;
		const _ULONGLONG _Ans = _CSTD _Stoullx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	// gather field, convert

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	// deliver value
		return (_First);
		}

// Sentinel value used by num_get::do_get() to enable correct "V2" behavior in _Getffld() and _Getffldx()
#define _ENABLE_V2_BEHAVIOR	1000000000

// Size of char buffer used by num_get::do_get() for float/double/long double
#define _FLOATING_BUFFER_SIZE	(_MAX_EXP_DIG + _MAX_SIG_DIG_V2 + 16)

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			float& _Val) const
		{	// get float from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_FLOATING_BUFFER_SIZE], *_Ep;
		int _Errno = 0;
		int _Hexexp = _ENABLE_V2_BEHAVIOR;
		float _Ans = _Stofx_v2(_Ac, &_Ep,
			_Getffld(_Ac, _First, _Last,
				_Iosbase, &_Hexexp), &_Errno);	// gather field, convert

		if (_Hexexp != _ENABLE_V2_BEHAVIOR && _Hexexp != 0)
			_Ans = _CSTD ldexpf(_Ans, 4 * _Hexexp);

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			double& _Val) const
		{	// get double from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_FLOATING_BUFFER_SIZE], *_Ep;
		int _Errno = 0;
		int _Hexexp = _ENABLE_V2_BEHAVIOR;
		double _Ans = _Stodx_v2(_Ac, &_Ep,
			_Getffld(_Ac, _First, _Last,
				_Iosbase, &_Hexexp), &_Errno);	// gather field, convert

		if (_Hexexp != _ENABLE_V2_BEHAVIOR && _Hexexp != 0)
			_Ans = _CSTD ldexp(_Ans, 4 * _Hexexp);

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	// deliver value
		return (_First);
		}

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long double& _Val) const
		{	// get long double from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_FLOATING_BUFFER_SIZE], *_Ep;
		int _Errno = 0;
		int _Hexexp = _ENABLE_V2_BEHAVIOR;
		long double _Ans = _Stodx_v2(_Ac, &_Ep,
			_Getffld(_Ac, _First, _Last,
				_Iosbase, &_Hexexp), &_Errno);	// gather field, convert, "widen" double to long double

		if (_Hexexp != _ENABLE_V2_BEHAVIOR && _Hexexp != 0)
			_Ans = _CSTD ldexpl(_Ans, 4 * _Hexexp);

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	// deliver value
		return (_First);
		}

#undef _FLOATING_BUFFER_SIZE

	virtual _InIt __CLR_OR_THIS_CALL do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			void *& _Val) const
		{	// get void pointer from [_First, _Last) into _Val
		_DEBUG_RANGE(_First, _Last);
		char _Ac[_MAX_INT_DIG], *_Ep;
		int _Errno = 0;

		int _Base = _Getifld(_Ac, _First, _Last, ios_base::hex,
			_Iosbase.getloc());	// gather field
		const _ULONGLONG _Ans =
			(sizeof (void *) == sizeof (unsigned long))
				? (_ULONGLONG)_CSTD _Stoulx(_Ac, &_Ep, _Base, &_Errno)
				: _CSTD _Stoullx(_Ac, &_Ep, _Base, &_Errno);

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = (void *)((char *)0 + _Ans);	// deliver value
		return (_First);
		}

private:
	int __CLRCALL_OR_CDECL _Getifld(char *_Ac,
		_InIt& _First, _InIt& _Last, ios_base::fmtflags _Basefield,
			const locale& _Loc) const
		{	// get integer field from [_First, _Last) into _Ac
		const _Mypunct& _Punct_fac = _USE(_Loc, _Mypunct);
		const string _Grouping = _Punct_fac.grouping();
		const _Elem _Kseparator = _Grouping.size() == 0
			? (_Elem)0 : _Punct_fac.thousands_sep();

		enum {
			_NUMGET_SIGNOFF = 22,
			_NUMGET_XOFF = 24};
		static const char _Src[] = {"0123456789ABCDEFabcdef-+Xx"};	// TRANSITION, VSO#202551
		_Elem _Atoms[sizeof (_Src)];
		const ctype<_Elem>& _Ctype_fac =
			_USE(_Loc, ctype<_Elem>);
		_Ctype_fac.widen(&_Src[0], &_Src[sizeof (_Src)], _Atoms);

		char *_Ptr = _Ac;

		if (_First == _Last)
			;	// empty field
		else if (*_First == _Atoms[_NUMGET_SIGNOFF + 1])
			*_Ptr++ = '+', ++_First;	// gather plus sign
		else if (*_First == _Atoms[_NUMGET_SIGNOFF])
			*_Ptr++ = '-', ++_First;	// gather minus sign

		_Basefield &= ios_base::basefield;
		int _Base = _Basefield == ios_base::oct ? 8
			: _Basefield == ios_base::hex ? 16
			: _Basefield == ios_base::_Fmtzero ? 0 : 10;

		bool _Seendigit = false;	// seen a digit in input
		bool _Nonzero = false;	// seen a nonzero digit in input

		if (_First != _Last && *_First == _Atoms[0])
			{	// leading zero, look for 0x, 0X
			_Seendigit = true, ++_First;
			if (_First != _Last && (*_First == _Atoms[_NUMGET_XOFF + 1]
					|| *_First == _Atoms[_NUMGET_XOFF])
				&& (_Base == 0 || _Base == 16))
				_Base = 16, _Seendigit = false, ++_First;
			else if (_Base == 0)
				_Base = 8;
			}

		size_t _Dlen = _Base == 0 || _Base == 10 ? 10
			: _Base == 8 ? 8 : 16 + 6;
		string _Groups((size_t)1, (char)_Seendigit);
		size_t _Group = 0;

		for (char *const _Pe = &_Ac[_MAX_INT_DIG - 1];
			_First != _Last; ++_First)
			{	// look for digits and separators
			size_t _Idx = _Find_elem(_Atoms, *_First);
			if (_Idx < _Dlen)
				{	// got a digit, characterize it and add to group size
				*_Ptr = _Src[_Idx];
				if ((_Nonzero || *_Ptr != '0') && _Ptr < _Pe)
					++_Ptr, _Nonzero = true;
				_Seendigit = true;
				if (_Groups[_Group] != CHAR_MAX)
					++_Groups[_Group];
				}
			else if (_Groups[_Group] == '\0'
				|| _Kseparator == (_Elem)0
				|| *_First != _Kseparator)
				break;	// not a group separator, done
			else
				{	// add a new group to _Groups string
				_Groups.append((string::size_type)1, '\0');
				++_Group;
				}
			}

		if (_Group == 0)
			;	// no thousands separators seen
		else if ('\0' < _Groups[_Group])
			++_Group;	// add trailing group to group count
		else
			_Seendigit = false;	// trailing separator, fail

		for (const char *_Pg = &_Grouping[0]; _Seendigit && 0 < _Group; )
			if (*_Pg == CHAR_MAX)
				break;	// end of grouping constraints to check
			else if ((0 < --_Group && *_Pg != _Groups[_Group])
				|| (0 == _Group && *_Pg < _Groups[_Group]))
				_Seendigit = false;	// bad group size, fail
			else if ('\0' < _Pg[1])
				++_Pg;	// group size okay, advance to next test

		if (_Seendigit && !_Nonzero)
			*_Ptr++ = '0';	// zero field, replace stripped zero(s)
		else if (!_Seendigit)
			_Ptr = _Ac;	// roll back pointer to indicate failure
		*_Ptr = '\0';
		return (_Base);
		}

	int __CLRCALL_OR_CDECL _Getffld(char *_Ac,
		_InIt& _First, _InIt &_Last,
		ios_base& _Iosbase, int *_Phexexp) const
		{	// get floating-point field from [_First, _Last) into _Ac
		if ((_Iosbase.flags() & ios_base::floatfield) == ios_base::hexfloat)
			return (_Getffldx(_Ac, _First, _Last,
				_Iosbase, _Phexexp));	// hex format

		const _Mypunct& _Punct_fac = _USE(_Iosbase.getloc(), _Mypunct);
		const string _Grouping = _Punct_fac.grouping();
		char *_Ptr = _Ac;
		bool _Bad = false;
		bool _Sticky = false;

		enum {
			_NUMGET_SIGNOFF = 10,
			_NUMGET_EOFF = 12};
		static const char _Src[] = {"0123456789-+Ee"};	// TRANSITION, VSO#202551
		_Elem _Atoms[sizeof (_Src)];
		const ctype<_Elem>& _Ctype_fac =
			_USE(_Iosbase.getloc(), ctype<_Elem>);
		_Ctype_fac.widen(&_Src[0], &_Src[sizeof (_Src)], _Atoms);

		if (_First == _Last)
			;	// empty field
		else if (*_First == _Atoms[_NUMGET_SIGNOFF + 1])
			*_Ptr++ = '+', ++_First;	// gather plus sign
		else if (*_First == _Atoms[_NUMGET_SIGNOFF])
			*_Ptr++ = '-', ++_First;	// gather minus sign

		char *_Leading = _Ptr;	// remember backstop
		*_Ptr++ = '0';	// backstop carries from sticky bit

		bool _Seendigit = false;	// seen a digit in input
		int _Significant = 0;	// number of significant digits
		int _Pten = 0;	// power of 10 multiplier
		size_t _Idx;

		const int _Max_sig_dig = (*_Phexexp == _ENABLE_V2_BEHAVIOR ? _MAX_SIG_DIG_V2 : _MAX_SIG_DIG_V1);

		const char *_Pg = &_Grouping[0];
		if (*_Pg == CHAR_MAX || *_Pg <= '\0')
			for (; _First != _Last
				&& (_Idx = _Find_elem(_Atoms, *_First)) < 10;
					_Seendigit = true, ++_First)
				if (_Max_sig_dig <= _Significant)
					{	// enough digits, scale by 10 and update _Sticky
					++_Pten;
					if (0 < _Idx)
						_Sticky = true;
					}
				else if (_Idx == 0 && _Significant == 0)
					;	// drop leading zeros
				else
					{	// save a significant digit
					*_Ptr++ = _Src[_Idx];
					++_Significant;
					}
		else
			{	// grouping specified, gather digits and group sizes
			const _Elem _Kseparator = _Grouping.size() == 0
				? (_Elem)0 : _Punct_fac.thousands_sep();
			string _Groups((size_t)1, '\0');
			size_t _Group = 0;

			for (; _First != _Last; ++_First)
				if ((_Idx = _Find_elem(_Atoms, *_First)) < 10)
					{	// got a digit, add to group size
					_Seendigit = true;
					if (_Max_sig_dig <= _Significant)
						{	// enough digits, scale by 10 and update _Sticky
						++_Pten;
						if (0 < _Idx)
							_Sticky = true;
						}
					else if (_Idx == 0 && _Significant == 0)
						;	// drop leading zeros
					else
						{	// save a significant digit
						*_Ptr++ = _Src[_Idx];
						++_Significant;
						}
					if (_Groups[_Group] != CHAR_MAX)
						++_Groups[_Group];
					}
				else if (_Groups[_Group] == '\0'
					|| _Kseparator == (_Elem)0
					|| *_First != _Kseparator)
					break;	// not a group separator, done
				else
					{	// add a new group to _Groups string
					_Groups.append((size_t)1, '\0');
					++_Group;
					}
			if (_Group == 0)
				;	// no thousands separators seen
			else if ('\0' < _Groups[_Group])
				++_Group;	// add trailing group to group count
			else
				_Bad = true;	// trailing separator, fail

			while (!_Bad && 0 < _Group)
				if (*_Pg == CHAR_MAX)
					break;	// end of grouping constraints to check
				else if ((0 < --_Group && *_Pg != _Groups[_Group])
					|| (0 == _Group && *_Pg < _Groups[_Group]))
					_Bad = true;	// bad group size, fail
				else if ('\0' < _Pg[1])
					++_Pg;	// group size okay, advance to next test
			}

		if (_First != _Last && *_First == _Punct_fac.decimal_point())
			*_Ptr++ = localeconv()->decimal_point[0], ++_First;	// add .

		if (*_Phexexp != _ENABLE_V2_BEHAVIOR && _Significant == 0)
			{	// 0000. so far
			for (; _First != _Last && *_First == _Atoms[0];
				_Seendigit = true, ++_First)
				--_Pten;	// just count leading fraction zeros
			if (_Pten < 0)
				*_Ptr++ = '0', ++_Pten;	// put one back
			}

		for (; _First != _Last
				&& (_Idx = _Find_elem(_Atoms, *_First)) < 10;
				_Seendigit = true, ++_First)
			if (_Significant < _Max_sig_dig)
				{	// save a significant fraction digit
				*_Ptr++ = _Src[_Idx];
				++_Significant;
				}
			else if (0 < _Idx)
				_Sticky = true;	// just update _Sticky

		if (_Sticky)
			{	// increment ls digit in memory of those lost
			char *_Px = _Ptr;
			for (; --_Px != _Leading; )
				{	// add in carry
				if (*_Px == localeconv()->decimal_point[0])
					;	// skip over decimal point
				else if (*_Px != '9')
					{	// carry stops here
					++*_Px;
					break;
					}
				else
					*_Px = '0';	// propagate carry
				}

			if (_Px == _Leading)
				{	// change "999..." to "1000..." and scale _Pten
				*_Px = '1';
				++_Pten;
				}
			}

		if (_Seendigit && _First != _Last
			&& (*_First == _Atoms[_NUMGET_EOFF + 1]
				|| *_First == _Atoms[_NUMGET_EOFF]))
			{	// 'e' or 'E', collect exponent
			*_Ptr++ = 'e', ++_First;
			_Seendigit = false, _Significant = 0;

			if (_First == _Last)
				;	// 'e' or 'E' is last element
			else if (*_First == _Atoms[_NUMGET_SIGNOFF + 1])
				*_Ptr++ = '+', ++_First;	// gather plus sign
			else if (*_First == _Atoms[_NUMGET_SIGNOFF])
				*_Ptr++ = '-', ++_First;	// gather minus sign
			for (; _First != _Last && *_First == _Atoms[0]; )
				_Seendigit = true, ++_First;	// strip leading zeros
			if (_Seendigit)
				*_Ptr++ = '0';	// put one back
			for (; _First != _Last
				&& (_Idx = _Find_elem(_Atoms, *_First)) < 10;
				_Seendigit = true, ++_First)
				if (_Significant < _MAX_EXP_DIG)
					{	// save a significant exponent digit
					*_Ptr++ = _Src[_Idx];
					++_Significant;
					}
			}

		if (_Bad || !_Seendigit)
			_Ptr = _Ac;	// roll back pointer to indicate failure
		*_Ptr = '\0';
		return (_Pten);
		}

	int __CLRCALL_OR_CDECL _Getffldx(char *_Ac,
		_InIt& _First, _InIt &_Last,
		ios_base& _Iosbase, int *_Phexexp) const
		{	// get hex floating-point field from [_First, _Last) into _Ac
		const _Mypunct& _Punct_fac = _USE(_Iosbase.getloc(), _Mypunct);
		const string _Grouping = _Punct_fac.grouping();

		enum {
			_NUMGET_SIGNOFF = 22,
			_NUMGET_XOFF = 24,
			_NUMGET_POFF = 26};
		static const char _Src[] = {"0123456789ABCDEFabcdef-+XxPp"};	// TRANSITION, VSO#202551
		_Elem _Atoms[sizeof (_Src)];
		const ctype<_Elem>& _Ctype_fac =
			_USE(_Iosbase.getloc(), ctype<_Elem>);
		_Ctype_fac.widen(&_Src[0], &_Src[sizeof (_Src)], _Atoms);

		char *_Ptr = _Ac;
		bool _Bad = false;
		size_t _Idx;

		if (_First == _Last)
			;	// empty field
		else if (*_First == _Atoms[_NUMGET_SIGNOFF + 1])
			*_Ptr++ = '+', ++_First;	// gather plus sign
		else if (*_First == _Atoms[_NUMGET_SIGNOFF])
			*_Ptr++ = '-', ++_First;	// gather minus sign

		*_Ptr++ = '0';
		*_Ptr++ = 'x';

		bool _Seendigit = false;	// seen a digit in input
		int _Significant = 0;	// number of significant digits
		int _Phex = 0;	// power of 10 multiplier

		if (_First == _Last || *_First != _Atoms[0])
			;
		else if (++_First != _Last
			&& (*_First == _Atoms[_NUMGET_XOFF + 1]
				|| *_First == _Atoms[_NUMGET_XOFF]))
			++_First;	// discard any 0x or 0X
		else
			_Seendigit = true;	// '0' not followed by 'x' or 'X'

		const int _Max_sig_dig = (*_Phexexp == _ENABLE_V2_BEHAVIOR ? _MAX_SIG_DIG_V2 : _MAX_SIG_DIG_V1);

		const char *_Pg = &_Grouping[0];
		if (*_Pg == CHAR_MAX || *_Pg <= '\0')
			for (; _First != _Last
				&& (_Idx = _Find_elem(_Atoms, *_First)) < _NUMGET_SIGNOFF;
					_Seendigit = true, ++_First)
				if (_Max_sig_dig <= _Significant)
					++_Phex;	// just scale by 10
				else if (_Idx == 0 && _Significant == 0)
					;	// drop leading zeros
				else
					{	// save a significant digit
					*_Ptr++ = _Src[_Idx];
					++_Significant;
					}
		else
			{	// grouping specified, gather digits and group sizes
			const _Elem _Kseparator = _Grouping.size() == 0
				? (_Elem)0 : _Punct_fac.thousands_sep();
			string _Groups((size_t)1, '\0');
			size_t _Group = 0;

			for (; _First != _Last; ++_First)
				if ((_Idx = _Find_elem(_Atoms, *_First)) < _NUMGET_SIGNOFF)
					{	// got a digit, add to group size
					_Seendigit = true;
					if (_Max_sig_dig <= _Significant)
						++_Phex;	// just scale by 10
					else if (_Idx == 0 && _Significant == 0)
						;	// drop leading zeros
					else
						{	// save a significant digit
						*_Ptr++ = _Src[_Idx];
						++_Significant;
						}
					if (_Groups[_Group] != CHAR_MAX)
						++_Groups[_Group];
					}
				else if (_Groups[_Group] == '\0'
					|| _Kseparator == (_Elem)0
					|| *_First != _Kseparator)
					break;	// not a group separator, done
				else
					{	// add a new group to _Groups string
					_Groups.append((size_t)1, '\0');
					++_Group;
					}
			if (_Group == 0)
				;	// no thousands separators seen
			else if ('\0' < _Groups[_Group])
				++_Group;	// add trailing group to group count
			else
				_Bad = true;	// trailing separator, fail

			while (!_Bad && 0 < _Group)
				if (*_Pg == CHAR_MAX)
					break;	// end of grouping constraints to check
				else if ((0 < --_Group && *_Pg != _Groups[_Group])
					|| (0 == _Group && *_Pg < _Groups[_Group]))
					_Bad = true;	// bad group size, fail
				else if ('\0' < _Pg[1])
					++_Pg;	// group size okay, advance to next test
			}

		if (_Seendigit && _Significant == 0)
			*_Ptr++ = '0';	// save at least one leading digit

		if (_First != _Last && *_First == _Punct_fac.decimal_point())
			*_Ptr++ = localeconv()->decimal_point[0], ++_First;	// add .

		if (_Significant == 0)
			{	// 0000. so far
			for (; _First != _Last && *_First == _Atoms[0];
				_Seendigit = true, ++_First)
				--_Phex;	// just count leading fraction zeros
			if (_Phex < 0)
				*_Ptr++ = '0', ++_Phex;	// put one back
			}

		for (; _First != _Last
				&& (_Idx = _Find_elem(_Atoms, *_First)) < _NUMGET_SIGNOFF;
				_Seendigit = true, ++_First)
			if (_Significant < _Max_sig_dig)
				{	// save a significant fraction digit
				*_Ptr++ = _Src[_Idx];
				++_Significant;
				}

		if (_Seendigit && _First != _Last
			&& (*_First == _Atoms[_NUMGET_POFF + 1]
				|| *_First == _Atoms[_NUMGET_POFF]))
			{	// 'p' or 'P', collect exponent
			*_Ptr++ = 'p', ++_First;
			_Seendigit = false, _Significant = 0;

			if (_First == _Last)
				;	// 'p' or 'P' is last element
			else if (*_First == _Atoms[_NUMGET_SIGNOFF + 1])
				*_Ptr++ = '+', ++_First;	// gather plus sign
			else if (*_First == _Atoms[_NUMGET_SIGNOFF])
				*_Ptr++ = '-', ++_First;	// gather minus sign
			for (; _First != _Last && *_First == _Atoms[0]; )
				_Seendigit = true, ++_First;	// strip leading zeros
			if (_Seendigit)
				*_Ptr++ = '0';	// put one back
			for (; _First != _Last
				&& (_Idx = _Find_elem(_Atoms, *_First)) < _NUMGET_SIGNOFF;
				_Seendigit = true, ++_First)
				if (_Significant < _MAX_EXP_DIG)
					{	// save a significant exponent digit
					*_Ptr++ = _Src[_Idx];
					++_Significant;
					}
			}

		if (_Bad || !_Seendigit)
			_Ptr = _Ac;	// roll back pointer to indicate failure
		*_Ptr = '\0';
		*_Phexexp = _Phex;	// power of 16 multiplier
		return (0);	// power of 10 multiplier
		}

#undef _ENABLE_V2_BEHAVIOR

	};

		// STATIC num_get::id OBJECT
template<class _Elem,
	class _InIt>
	__PURE_APPDOMAIN_GLOBAL locale::id num_get<_Elem, _InIt>::id;

		// TEMPLATE CLASS num_put
template<class _Elem,
	class _OutIt = ostreambuf_iterator<_Elem, char_traits<_Elem> > >
	class num_put
		: public locale::facet
	{	// facet for converting encoded numbers to text
public:
	typedef numpunct<_Elem> _Mypunct;
	typedef basic_string<_Elem, char_traits<_Elem>, allocator<_Elem> >
		_Mystr;

	static size_t __CLRCALL_OR_CDECL _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	// return locale category mask and construct standard facet
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new num_put<_Elem, _OutIt>(
				_Locinfo(_Ploc->c_str()));
		return (_X_NUMERIC);
		}

	__PURE_APPDOMAIN_GLOBAL static locale::id id;	// unique facet id

protected:
	virtual __CLR_OR_THIS_CALL ~num_put() _NOEXCEPT
		{	// destroy the object
		}

	void __CLR_OR_THIS_CALL _Init(const _Locinfo&)
		{	// initialize from _Locinfo object
		}

public:
	explicit __CLR_OR_THIS_CALL num_put(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	// construct from current locale
		_BEGIN_LOCINFO(_Lobj)
			_Init(_Lobj);
		_END_LOCINFO()
		}

	__CLR_OR_THIS_CALL num_put(const _Locinfo& _Lobj, size_t _Refs = 0)
		: locale::facet(_Refs)
		{	// construct from specified locale
		_Init(_Lobj);
		}

	typedef _Elem char_type;
	typedef _OutIt iter_type;

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, bool _Val) const
		{	// put formatted bool to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long _Val) const
		{	// put formatted long to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, unsigned long _Val) const
		{	// put formatted unsigned long to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, _LONGLONG _Val) const
		{	// put formatted long long to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, _ULONGLONG _Val) const
		{	// put formatted unsigned long long to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, double _Val) const
		{	// put formatted double to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long double _Val) const
		{	// put formatted long double to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt __CLR_OR_THIS_CALL put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, const void *_Val) const
		{	// put formatted void pointer to _Dest
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

protected:
	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, bool _Val) const
		{	// put formatted bool to _Dest
		_DEBUG_POINTER(_Dest);
		if (!(_Iosbase.flags() & ios_base::boolalpha))
			return (do_put(_Dest, _Iosbase, _Fill, (long)_Val));
		else
			{	// put "false" or "true"
			const _Mypunct& _Punct_fac = _USE(_Iosbase.getloc(), _Mypunct);
			_Mystr _Str;
			if (_Val)
				_Str.assign(_Punct_fac.truename());
			else
				_Str.assign(_Punct_fac.falsename());

			size_t _Fillcount = _Iosbase.width() <= 0
				|| (size_t)_Iosbase.width() <= _Str.size()
					? 0 : (size_t)_Iosbase.width() - _Str.size();

			if ((_Iosbase.flags() & ios_base::adjustfield) != ios_base::left)
				{	// put leading fill
				_Dest = _Rep(_Dest, _Fill, _Fillcount);
				_Fillcount = 0;
				}
			_Dest = _Put(_Dest, _Str.c_str(), _Str.size());	// put field
			_Iosbase.width(0);
			return (_Rep(_Dest, _Fill, _Fillcount));	// put trailing fill
			}
		}

	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long _Val) const
		{	// put formatted long to _Dest
		char _Buf[2 * _MAX_INT_DIG], _Fmt[6];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			_CSTD sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "ld",
				_Iosbase.flags()), _Val)));
		}

	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, unsigned long _Val) const
		{	// put formatted unsigned long to _Dest
		char _Buf[2 * _MAX_INT_DIG], _Fmt[6];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			_CSTD sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "lu",
				_Iosbase.flags()), _Val)));
		}

	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, _LONGLONG _Val) const
		{	// put formatted long long to _Dest
		char _Buf[2 * _MAX_INT_DIG], _Fmt[8];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			_CSTD sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "Ld",
				_Iosbase.flags()), _Val)));
		}

	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, _ULONGLONG _Val) const
		{	// put formatted unsigned long long to _Dest
		char _Buf[2 * _MAX_INT_DIG], _Fmt[8];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			_CSTD sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "Lu",
				_Iosbase.flags()), _Val)));
		}

	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, double _Val) const
		{	// put formatted double to _Dest
		string _Buf;
		char _Fmt[8];
		bool _Isfixed = (_Iosbase.flags() & ios_base::floatfield)
			== ios_base::fixed;
		streamsize _Precision = _Iosbase.precision() <= 0 && !_Isfixed
			? 6 : _Iosbase.precision();	// desired precision
		size_t _Bufsize = (size_t)_Precision;
		if (_Isfixed && 1e10 < _CSTD fabs(_Val))
			{	// f or F format
			int _Ptwo;
			(void)_CSTD frexp(_Val, &_Ptwo);
			_Bufsize += _CSTD abs(_Ptwo) * 30103L / 100000L;
			}
		_Buf.resize(_Bufsize + 50);	// add fudge factor

		int _Ngen = _CSTD sprintf_s((char *)_Buf.c_str(), _Buf.size(),
			_Ffmt(_Fmt, 0, _Iosbase.flags()), (int)_Precision, _Val);

		return (_Fput(_Dest, _Iosbase, _Fill, _Buf.c_str(), _Ngen));
		}

	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long double _Val) const
		{	// put formatted long double to _Dest
		string _Buf;
		char _Fmt[8];
		bool _Isfixed = (_Iosbase.flags() & ios_base::floatfield)
			== ios_base::fixed;
		streamsize _Precision = _Iosbase.precision() <= 0 && !_Isfixed
			? 6 : _Iosbase.precision();	// desired precision
		size_t _Bufsize = (size_t)_Precision;
		if (_Isfixed && 1e10 < _CSTD fabsl(_Val))
			{	// f or F format
			int _Ptwo;
			(void)_CSTD frexpl(_Val, &_Ptwo);
			_Bufsize += _CSTD abs(_Ptwo) * 30103L / 100000L;
			}
		_Buf.resize(_Bufsize + 50);	// add fudge factor

		int _Ngen = _CSTD sprintf_s((char *)_Buf.c_str(), _Buf.size(),
			_Ffmt(_Fmt, 'L', _Iosbase.flags()), (int)_Precision, _Val);

		return (_Fput(_Dest, _Iosbase, _Fill, _Buf.c_str(), _Ngen));
		}

	virtual _OutIt __CLR_OR_THIS_CALL do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, const void *_Val) const
		{	// put formatted void pointer to _Dest
		char _Buf[2 * _MAX_INT_DIG];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			_CSTD sprintf_s(_Buf, sizeof (_Buf), "%p", _Val)));
		}

private:
	char *__CLRCALL_OR_CDECL _Ffmt(char *_Fmt,
		char _Spec, ios_base::fmtflags _Flags) const
		{	// generate sprintf format for floating-point
		char *_Ptr = _Fmt;
		*_Ptr++ = '%';

		if (_Flags & ios_base::showpos)
			*_Ptr++ = '+';
		if (_Flags & ios_base::showpoint)
			*_Ptr++ = '#';
		*_Ptr++ = '.';
		*_Ptr++ = '*';	// for precision argument
		if (_Spec != '\0')
			*_Ptr++ = _Spec;	// 'L' qualifier for long double only

		ios_base::fmtflags _Ffl = _Flags & ios_base::floatfield;
		if (_Flags & ios_base::uppercase)
			*_Ptr++ = _Ffl == ios_base::fixed ? 'f'
				: _Ffl == ios_base::hexfloat ? 'A'	// added with TR1
				: _Ffl == ios_base::scientific ? 'E' : 'G';	// specifier
		else
			*_Ptr++ = _Ffl == ios_base::fixed ? 'f'
				: _Ffl == ios_base::hexfloat ? 'a'	// added with TR1
				: _Ffl == ios_base::scientific ? 'e' : 'g';	// specifier

		*_Ptr = '\0';
		return (_Fmt);
		}

	_OutIt __CLRCALL_OR_CDECL _Fput(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, const char *_Buf,
			size_t _Count) const
		{	// put formatted floating-point to _Dest
		_DEBUG_POINTER(_Dest);
		size_t _Prefix = 0 < _Count && (*_Buf == '+' || *_Buf == '-')
			? 1 : 0;

		const char *_Exps;
		if ((_Iosbase.flags() & ios_base::floatfield) != ios_base::hexfloat)
			_Exps = "eE";
		else
			{	// correct for hexadecimal floating-point
			_Exps = "pP";
			if (_Prefix + 2 <= _Count && _Buf[_Prefix] == '0'
				&& (_Buf[_Prefix + 1] == 'x' || _Buf[_Prefix + 1] == 'X'))
				_Prefix += 2;
			}
		const size_t _Eoff =
			_CSTD strcspn(&_Buf[0], _Exps);	// find exponent
		char _Dp[2] = {"."};
		_Dp[0] = _CSTD localeconv()->decimal_point[0];
		const size_t _Poff =
			_CSTD strcspn(&_Buf[0], &_Dp[0]);	// find decimal point

		const ctype<_Elem>& _Ctype_fac =
			_USE(_Iosbase.getloc(), ctype<_Elem>);
		_Mystr _Groupstring(_Count, _Elem(0));	// reserve space
		_Ctype_fac.widen(&_Buf[0], &_Buf[_Count], &_Groupstring[0]);

		const _Mypunct& _Punct_fac = _USE(_Iosbase.getloc(), _Mypunct);
		const string _Grouping = _Punct_fac.grouping();
		const _Elem _Kseparator = _Punct_fac.thousands_sep();

		if (_Poff != _Count)
			_Groupstring[_Poff] = _Punct_fac.decimal_point();

		size_t _Off = _Poff == _Count ? _Eoff : _Poff;
		const char *_Pg = &_Grouping[0];
		while (*_Pg != CHAR_MAX && '\0' < *_Pg
			&& (size_t)*_Pg < _Off - _Prefix)
			{	// add thousands separator
			_Groupstring.insert(_Off -= *_Pg, (size_t)1, _Kseparator);
			if ('\0' < _Pg[1])
				++_Pg;	// not last group, advance
			}

		_Count = _Groupstring.size();
		size_t _Fillcount = _Iosbase.width() <= 0
			|| (size_t)_Iosbase.width() <= _Count
				? 0 : (size_t)_Iosbase.width() - _Count;

		ios_base::fmtflags _Adjustfield =
			_Iosbase.flags() & ios_base::adjustfield;
		if (_Adjustfield != ios_base::left
			&& _Adjustfield != ios_base::internal)
			{	// put leading fill
			_Dest = _Rep(_Dest, _Fill, _Fillcount);
			_Fillcount = 0;
			_Dest = _Put(_Dest, &_Groupstring[0], _Prefix);
			}
		else if (_Adjustfield == ios_base::internal)
			{	// put internal fill
			_Dest = _Put(_Dest, &_Groupstring[0], _Prefix);
			_Dest = _Rep(_Dest, _Fill, _Fillcount);
			_Fillcount = 0;
			}
		else
			_Dest = _Put(_Dest, &_Groupstring[0], _Prefix);

		_Dest = _Put(_Dest, &_Groupstring[_Prefix], _Count - _Prefix);
		_Iosbase.width(0);
		return (_Rep(_Dest, _Fill, _Fillcount));	// put trailing fill
		}

	char *__CLRCALL_OR_CDECL _Ifmt(char *_Fmt,
		const char *_Spec, ios_base::fmtflags _Flags) const
		{	// generate sprintf format for integer
		char *_Ptr = _Fmt;
		*_Ptr++ = '%';

		if (_Flags & ios_base::showpos)
			*_Ptr++ = '+';
		if (_Flags & ios_base::showbase)
			*_Ptr++ = '#';
		if (_Spec[0] != 'L')
			*_Ptr++ = _Spec[0];	// qualifier
		else

			{	/* change L to I64 */
			*_Ptr++ = 'I';
			*_Ptr++ = '6';
			*_Ptr++ = '4';
			}

		ios_base::fmtflags _Basefield = _Flags & ios_base::basefield;
		*_Ptr++ = _Basefield == ios_base::oct ? 'o'
			: _Basefield != ios_base::hex ? _Spec[1]	// 'd' or 'u'
			: _Flags & ios_base::uppercase ? 'X' : 'x';
		*_Ptr = '\0';
		return (_Fmt);
		}

	_OutIt __CLRCALL_OR_CDECL _Iput(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, char *_Buf, size_t _Count) const
		{	// put formatted integer to _Dest
		_DEBUG_POINTER(_Dest);
		size_t _Prefix = 0 < _Count && (*_Buf == '+' || *_Buf == '-')
			? 1 : 0;
		if ((_Iosbase.flags() & ios_base::basefield) == ios_base::hex
			&& _Prefix + 2 <= _Count && _Buf[_Prefix] == '0'
			&& (_Buf[_Prefix + 1] == 'x' || _Buf[_Prefix + 1] == 'X'))
			_Prefix += 2;

		const ctype<_Elem>& _Ctype_fac =
			_USE(_Iosbase.getloc(), ctype<_Elem>);
		_Mystr _Groupstring(_Count, _Elem(0));	// reserve space
		_Ctype_fac.widen(&_Buf[0], &_Buf[_Count], &_Groupstring[0]);

		const _Mypunct& _Punct_fac = _USE(_Iosbase.getloc(), _Mypunct);
		const string _Grouping = _Punct_fac.grouping();
		const char *_Pg = &_Grouping[0];
		if (*_Pg != CHAR_MAX && '\0' < *_Pg)
			{	// grouping specified, add thousands separators
			const _Elem _Kseparator = _Punct_fac.thousands_sep();
			while (*_Pg != CHAR_MAX && '\0' < *_Pg
				&& (size_t)*_Pg < _Count - _Prefix)
				{	// insert thousands separator
				_Count -= *_Pg;
				_Groupstring.insert(_Count, 1, _Kseparator);
				if ('\0' < _Pg[1])
					++_Pg;	// not last group, advance
				}
			}

		_Count = _Groupstring.size();
		size_t _Fillcount = _Iosbase.width() <= 0
			|| (size_t)_Iosbase.width() <= _Count
				? 0 : (size_t)_Iosbase.width() - _Count;

		ios_base::fmtflags _Adjustfield =
			_Iosbase.flags() & ios_base::adjustfield;
		if (_Adjustfield != ios_base::left
			&& _Adjustfield != ios_base::internal)
			{	// put leading fill
			_Dest = _Rep(_Dest, _Fill, _Fillcount);
			_Fillcount = 0;
			_Dest = _Put(_Dest, &_Groupstring[0], _Prefix);
			}
		else if (_Adjustfield == ios_base::internal)
			{	// put internal fill
			_Dest = _Put(_Dest, &_Groupstring[0], _Prefix);
			_Dest = _Rep(_Dest, _Fill, _Fillcount);
			_Fillcount = 0;
			}
		else
			_Dest = _Put(_Dest, &_Groupstring[0], _Prefix);

		_Dest = _Put(_Dest, &_Groupstring[_Prefix], _Count - _Prefix);
		_Iosbase.width(0);
		return (_Rep(_Dest, _Fill, _Fillcount));	// put trailing fill
		}

	_OutIt __CLRCALL_OR_CDECL _Put(_OutIt _Dest,
		const _Elem *_Ptr, size_t _Count) const
		{	// put [_Ptr, _Ptr + _Count) to _Dest
		for (; 0 < _Count; --_Count, (void)++_Dest, ++_Ptr)
			*_Dest = *_Ptr;
		return (_Dest);
		}

	_OutIt __CLRCALL_OR_CDECL _Rep(_OutIt _Dest,
		_Elem _Ch, size_t _Count) const
		{	// put _Count * _Ch to _Dest
		for (; 0 < _Count; --_Count, (void)++_Dest)
			*_Dest = _Ch;
		return (_Dest);
		}
	};

		// STATIC num_put::id OBJECT
template<class _Elem,
	class _OutIt>
	__PURE_APPDOMAIN_GLOBAL locale::id num_put<_Elem, _OutIt>::id;

 #if defined(_DLL_CPPLIB) && !defined(_M_CEE_PURE)

  #if !defined(_CRTBLD) || defined(__FORCE_INSTANCE)
template __PURE_APPDOMAIN_GLOBAL locale::id numpunct<char>::id;
template class _CRTIMP2_PURE num_get<char,
	istreambuf_iterator<char, char_traits<char> > >;
template class _CRTIMP2_PURE num_put<char,
	ostreambuf_iterator<char, char_traits<char> > >;

template __PURE_APPDOMAIN_GLOBAL locale::id numpunct<wchar_t>::id;
template class _CRTIMP2_PURE num_get<wchar_t,
	istreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
template class _CRTIMP2_PURE num_put<wchar_t,
	ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
  #endif /* !defined(_CRTBLD) || defined(__FORCE_INSTANCE) */

  #ifdef __FORCE_INSTANCE
template __PURE_APPDOMAIN_GLOBAL locale::id numpunct<unsigned short>::id;
template class _CRTIMP2_PURE num_get<unsigned short,
	istreambuf_iterator<unsigned short, char_traits<unsigned short> > >;
template class _CRTIMP2_PURE num_put<unsigned short,
	ostreambuf_iterator<unsigned short, char_traits<unsigned short> > >;
  #endif /* __FORCE_INSTANCE */
 #endif /* defined(_DLL_CPPLIB) etc. */
_STD_END
 #pragma pop_macro("new")
 #pragma warning(pop)
 #pragma pack(pop)
#endif /* RC_INVOKED */
#endif /* _XLOCNUM_ */

/*
 * Copyright (c) by P.J. Plauger. All rights reserved.
 * Consult your license regarding permissions and restrictions.
V6.50:0009 */
