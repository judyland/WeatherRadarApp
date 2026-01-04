//-----------------------------------------------------------------------------
// File Name:		SafeArrayT.h
// Project Name:	EntityDevice
//-----------------------------------------------------------------------------
#ifndef SAFE_ARRAY_T__H
#define SAFE_ARRAY_T__H

#if defined(_MSC_VER) && !defined(__KLOCWORK__)
#	pragma once
#endif

#include "Crt/CrtStdInt.h"
#include <cstdarg>
#include <cassert>
#ifdef _MSC_VER
#	ifdef IMPLEMENT_MS_SECURED_STR
#		include <crtdefs.h>
#	endif // IMPLEMENT_MS_SECURED_STR
#endif // _MSC_VER


#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(push, 1)
#endif

#ifdef _DEBUG
	#define USE_SAFE_ARRAY
#else
	//#define USE_SAFE_ARRAY
#endif

#ifdef USE_SAFE_ARRAY
	// - IMPLEMENT_MS_SECURED_STR is currently not relevant, because we encountered problems when using this template for 'char *'
	// - If IMPLEMENT_MS_SECURED_STR is used, we need to consider that _CRT_SECURE_CPP_NOTHROW is defined in VS-2010 but not in VS-2005
	// #define IMPLEMENT_MS_SECURED_STR
	#define DEF_ARRAY(ARR_NAME, ELEM_TYPE, ARRAY_SIZE) CSafeArrayT<ELEM_TYPE, ARRAY_SIZE> ARR_NAME
#else
	#define DEF_ARRAY(ARR_NAME, ELEM_TYPE, ARRAY_SIZE) ELEM_TYPE ARR_NAME[ARRAY_SIZE]
#endif

template <typename TypeName, std::uint32_t nArrSize>
class CSafeArrayT
{
public:
	typedef TypeName (&TypeNameArrRefType)[nArrSize];
	typedef const TypeName (&TypeNameConstArrRef)[nArrSize];

	TypeName &operator[] (const std::int32_t nIndex);				// making it unsigned causes ambiguity
	const TypeName &operator[] (const std::int32_t nIndex) const;	// making it unsigned causes ambiguity
	operator TypeNameConstArrRef() const;
	operator TypeNameArrRefType();

private:
	TypeName m_aArray[nArrSize];
};

template <typename TypeName, std::uint32_t nArrSize>
TypeName &CSafeArrayT<TypeName, nArrSize>::operator[] (const std::int32_t nIndex)
{
	assert((0 <= nIndex) && (std::uint32_t(nIndex) < nArrSize));
	return m_aArray[std::uint32_t(nIndex)];
}

template <typename TypeName, std::uint32_t nArrSize>
const TypeName &CSafeArrayT<TypeName, nArrSize>::operator[] (const std::int32_t nIndex) const
{
	assert((0 <= nIndex) && (std::uint32_t(nIndex) < nArrSize));
	return m_aArray[std::uint32_t(nIndex)];
}

template <typename TypeName, std::uint32_t nArrSize>
CSafeArrayT<TypeName, nArrSize>::operator typename CSafeArrayT<TypeName, nArrSize>::TypeNameConstArrRef() const
{
	return TypeNameConstArrRef(m_aArray);
}

template <typename TypeName, std::uint32_t nArrSize>
CSafeArrayT<TypeName, nArrSize>::operator typename CSafeArrayT<TypeName, nArrSize>::TypeNameArrRefType()
{
	return TypeNameArrRefType(m_aArray);
}

// =============================================================================
// MS secured string operations for CSafeArrayT (WINDOWS only)
// =============================================================================

#ifdef _MSC_VER

// IMPLEMENT_MS_SECURED_STR should be defined in order to use these functions
#ifdef IMPLEMENT_MS_SECURED_STR

extern "C++"
{
	template <std::uint32_t _Size>
	inline errno_t __CRTDECL strcat_s(CSafeArrayT<char, _Size> &_Dst, const char *pszSource) _CRT_SECURE_CPP_NOTHROW
	{
		return strcat_s(_Dst, _Size, pszSource);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL strcpy_s(CSafeArrayT<char, _Size> &_Dst, const char *_Src) _CRT_SECURE_CPP_NOTHROW
	{
		return strcpy_s(_Dst, _Size, _Src);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL strerror_s(CSafeArrayT<char, _Size> &_Dst, int errnum) _CRT_SECURE_CPP_NOTHROW
	{
		return strerror_s(_Dst, _Size, errnum);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL _strerror_s(CSafeArrayT<char, _Size> &_Dst, const char *strErrMsg) _CRT_SECURE_CPP_NOTHROW
	{
		return _strerror_s(_Dst, _Size, strErrMsg);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL _strlwr_s(CSafeArrayT<char, _Size> &_Dst) _CRT_SECURE_CPP_NOTHROW
	{
		return _strlwr_s(_Dst, _Size);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL _strlwr_s_l(CSafeArrayT<char, _Size> &_Dst, _locale_t locale) _CRT_SECURE_CPP_NOTHROW
	{
		return _strlwr_s_l(_Dst, _Size, locale);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL strncat_s(CSafeArrayT<char, _Size> &_Dst, const char *pszSource, std::uint32_t nCount) _CRT_SECURE_CPP_NOTHROW
	{
		return strncat_s(_Dst, _Size, pszSource, nCount);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL _strncat_s_l(CSafeArrayT<char, _Size> &_Dst, const char *pszSource, std::uint32_t nCount, _locale_t locale) _CRT_SECURE_CPP_NOTHROW
	{
		return _strncat_s_l(_Dst, _Size, pszSource, nCount, locale);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL strncpy_s(CSafeArrayT<char, _Size> &_Dst, const char *pszSource, std::uint32_t nCount) _CRT_SECURE_CPP_NOTHROW
	{
		return strncpy_s(_Dst, _Size, pszSource, nCount);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL _strncpy_s_l(CSafeArrayT<char, _Size> &_Dst, const char *pszSource, std::uint32_t nCount, _locale_t locale) _CRT_SECURE_CPP_NOTHROW
	{
		return _strncpy_s_l(_Dst, _Size, pszSource, nCount, locale);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL _strupr_s(CSafeArrayT<char, _Size> &_Dst) _CRT_SECURE_CPP_NOTHROW
	{
		return _strupr_s(_Dst, _Size);
	}

	template <std::uint32_t _Size>
	inline errno_t __CRTDECL _strupr_s_l(CSafeArrayT<char, _Size> &_Dst, _locale_t locale) _CRT_SECURE_CPP_NOTHROW
	{
		return _strupr_s_l(_Dst, _Size, locale);
	}

	template <std::uint32_t _Size>
	inline int __CRTDECL vsprintf_s(CSafeArrayT<char, _Size> &_Dst, const char *pszFormat, std::va_list argptr) _CRT_SECURE_CPP_NOTHROW
	{
		return vsprintf_s(_Dst, _Size, pszFormat, argptr);
	}

	template <std::uint32_t _Size>
	inline int __CRTDECL _vsnprintf_s(CSafeArrayT<char, _Size> &_Dst, std::uint32_t nCount, const char *pszFormat, std::va_list argptr) _CRT_SECURE_CPP_NOTHROW
	{
		return _vsnprintf_s(_Dst, _Size, nCount, pszFormat, argptr);
	}

	__pragma(warning(push));
	__pragma(warning(disable: 4793));

	template <std::uint32_t _Size>
	inline int __CRTDECL sprintf_s(CSafeArrayT<char, _Size> &_Dst, const char *pszFormat, ...) _CRT_SECURE_CPP_NOTHROW
	{
		std::va_list _ArgList;
		_crt_va_start(_ArgList, pszFormat);
		return sprintf_s(_Dst, _Size, pszFormat, _ArgList);
	}

	__pragma(warning(pop));
}

#endif // IMPLEMENT_MS_SECURED_STR
#endif // _MSC_VER

#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(pop)
#endif

#endif // SAFE_ARRAY_T__H
