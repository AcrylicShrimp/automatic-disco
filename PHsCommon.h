
/*
	2016.01.20
	Created by PHJ.
*/

#ifndef _PHS_COMMON_H

#define _PHS_COMMON_H

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>

#endif

#include <cassert>
#include <intrin.h>
#include <cmath>
#include <utility>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsDef
	{
		using Void = void;

		using Bool = bool;

		using Char = char;
		using Byte = unsigned char;
		using wChar = wchar_t;

		using Short = short;
		using Int = int;
		using Long = long long;

		using uShort = unsigned short;
		using uInt = unsigned int;
		using uLong = unsigned long long;

		using Float = float;
		using Double = double;

		using Char16Ext = __m128i;
		using Byte16Ext = __m128i;
		using Int4Ext = __m128i;
		using Long2Ext = __m128i;

		using Float4Ext = __m128;
		using Double2Ext = __m128d;

		//For interface
		class Interface
		{
		protected:
			Interface() = default;
			Interface(Interface &&sNewInterface) = default;
			Interface(const Interface &sNewInterface) = default;
			virtual ~Interface() = default;
		};

#define INTERFACE(CLASS) class CLASS : public PHs::PHsDef::Interface

	}

#ifdef _PHS_DLL_EXPORT

#define _PHS_DLL __declspec(dllexport)

#else

#define _PHS_DLL __declspec(dllimport)

#endif

#ifdef _DEBUG

	inline namespace PHsDebug
	{
		class __PHs_Debug
		{
		public:
			inline __PHs_Debug();
			__PHs_Debug(__PHs_Debug &&sNew__PHs_Debug) = delete;
			__PHs_Debug(const __PHs_Debug &sNew__PHs_Debug) = delete;
			~__PHs_Debug() = default;
		};
	}

#endif

	inline namespace PHsUtility
	{
		template <class __Measure_Type> inline __Measure_Type &&Min(__Measure_Type &&tLeft, __Measure_Type &&tRight);
		template <class __Measure_Type> inline const __Measure_Type &Min(const __Measure_Type &tLeft, const __Measure_Type &tRight);
		template <class __Measure_Type> inline __Measure_Type &&Max(__Measure_Type &&tLeft, __Measure_Type &&tRight);
		template <class __Measure_Type> inline const __Measure_Type &Max(const __Measure_Type &tLeft, const __Measure_Type &tRight);

		template <class __Measure_Type, __Measure_Type __Epsilon_Value> inline Bool Same(const __Measure_Type &tLeft, const __Measure_Type &tRight);
		template <class __Measure_Type, __Measure_Type __Epsilon_Value> inline Bool Diff(const __Measure_Type &tLeft, const __Measure_Type &tRight);

		inline long double operator ""_Deg(long double nDegree);

		template <class __Value_Type> inline __Value_Type minValue();
		template <class __Value_Type> inline __Value_Type maxValue();

		template <> inline Byte minValue <Byte>();
		template <> inline Byte maxValue <Byte>();
		template <> inline Short minValue <Short>();
		template <> inline Short maxValue <Short>();
		template <> inline uShort minValue <uShort>();
		template <> inline uShort maxValue <uShort>();
		template <> inline Int minValue <Int>();
		template <> inline Int maxValue <Int>();
		template <> inline uInt minValue <uInt>();
		template <> inline uInt maxValue <uInt>();
		template <> inline Long minValue <Long>();
		template <> inline Long maxValue <Long>();
		template <> inline uLong minValue <uLong>();
		template <> inline uLong maxValue <uLong>();
	}
}

#include "PHsCommon.hpp"

#endif