#ifndef CRT_STD_INT__H
#define CRT_STD_INT__H

#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(push, 8)
#endif

// This header is a wrapper for stdint.h in order to add it to
// the std namespace for portability to compilers pre C++11.

// In Linux compile with either one of:
//	g++ -std=c++11
//	g++ -std=gnu++11

#if defined(_MSC_VER)
#	if _MSC_VER <= 1500
#		define IMPLEMENT_CRT_STD_INT
#	else
//		NOTHING
#	endif
#elif defined(__linux__)
//	NOTHING
#elif defined(__vxworks)
#	if defined(VXWORKS__653)
#		include "stdint_vxw_653.h"
//#		include "types/vxTypes.h"
#		define IMPLEMENT_CRT_STD_INT
#	else
//		NOTHING
#	endif
#elif defined(__INTEGRITY)
#	define IMPLEMENT_CRT_STD_INT
//	__STDC_LIMIT_MACROS is required in order to define the C99 macros found in stdint.h
#	if !defined(__STDC_LIMIT_MACROS)
#		define __STDC_LIMIT_MACROS
#	endif
#else
//	???
#endif

#ifndef IMPLEMENT_CRT_STD_INT
#	include <cstdint>
#else
#	if !defined(VXWORKS__653)
#		include <stdint.h>
#	endif
namespace std
{
	using ::int8_t;
	using ::int16_t;
	using ::int32_t;
	using ::int64_t;
	using ::uint8_t;
	using ::uint16_t;
	using ::uint32_t;
	using ::uint64_t;

//#	if !defined(VXWORKS__653)
	using ::int_least8_t;
	using ::int_least16_t;
	using ::int_least32_t;
	using ::int_least64_t;
	using ::uint_least8_t;
	using ::uint_least16_t;
	using ::uint_least32_t;
	using ::uint_least64_t;

	using ::int_fast8_t;
	using ::int_fast16_t;
	using ::int_fast32_t;
	using ::int_fast64_t;
	using ::uint_fast8_t;
	using ::uint_fast16_t;
	using ::uint_fast32_t;
	using ::uint_fast64_t;

	using ::intmax_t;
	using ::uintmax_t;
	using ::intptr_t;
	using ::uintptr_t;
//#	endif
}
#endif

#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(pop)
#endif

#endif // CRT_STD_INT__H
