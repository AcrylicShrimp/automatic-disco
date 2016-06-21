
/*
	2016.01.20
	Created by PHJ.
*/

#ifndef _PHS_COMMON_HPP

#define _PHS_COMMON_HPP

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
#ifdef _DEBUG

	inline namespace PHsDebug
	{
		inline __PHs_Debug::__PHs_Debug()
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		}
	}

#endif

	inline namespace PHsUtility
	{
		template <class __Measure_Type> inline __Measure_Type &&Min(__Measure_Type &&tLeft, __Measure_Type &&tRight)
		{
			return tLeft < tRight ? std::forward <__Measure_Type>(tLeft) : std::forward <__Measure_Type>(tRight);
		}

		template <class __Measure_Type> inline const __Measure_Type &Min(const __Measure_Type &tLeft, const __Measure_Type &tRight)
		{
			return tLeft < tRight ? tLeft : tRight;
		}

		template <class __Measure_Type> inline __Measure_Type &&Max(__Measure_Type &&tLeft, __Measure_Type &&tRight)
		{
			return tLeft < tRight ? std::forward <__Measure_Type>(tRight) : std::forward <__Measure_Type>(tLeft);
		}

		template <class __Measure_Type> inline const __Measure_Type &Max(const __Measure_Type &tLeft, const __Measure_Type &tRight)
		{
			return tLeft < tRight ? tRight : tLeft;
		}

		template <class __Measure_Type, __Measure_Type __Epsilon_Value> inline Bool Same(const __Measure_Type &tLeft, const __Measure_Type &tRight)
		{
			return abs(tLeft - tRight) <= __Epsilon_Value;
		}

		template <class __Measure_Type, __Measure_Type __Epsilon_Value> inline Bool Diff(const __Measure_Type &tLeft, const __Measure_Type &tRight)
		{
			return abs(tLeft - tRight) > __Epsilon_Value;
		}

		inline long double operator ""_Deg(long double nDegree)
		{
			return 3.14159265358979l / 180.0l * nDegree;
		}

		template <class __Value_Type> inline __Value_Type minValue()
		{
			static_assert(false, "Integer type only.");
			return __Value_Type();
		}

		template <class __Value_Type> inline __Value_Type maxValue()
		{
			static_assert(false, "Integer type only.");
			return __Value_Type();
		}

		template <> inline Byte minValue <Byte>()
		{
			return Byte(0x00);
		}

		template <> inline Byte maxValue <Byte>()
		{
			return Byte(0xFF);
		}

		template <> inline Short minValue <Short>()
		{
			return Short(0x8000);
		}

		template <> inline Short maxValue <Short>()
		{
			return Short(0x7FFF);
		}

		template <> inline uShort minValue <uShort>()
		{
			return uShort(0x0000u);
		}

		template <> inline uShort maxValue <uShort>()
		{
			return uShort(0xFFFFu);
		}

		template <> inline Int minValue <Int>()
		{
			return Int(0x80000000);
		}

		template <> inline Int maxValue <Int>()
		{
			return Int(0x7FFFFFFF);
		}

		template <> inline uInt minValue <uInt>()
		{
			return uInt(0x00000000u);
		}

		template <> inline uInt maxValue <uInt>()
		{
			return uInt(0xFFFFFFFFu);
		}

		template <> inline Long minValue <Long>()
		{
			return Long(0x8000000000000000i64);
		}

		template <> inline Long maxValue <Long>()
		{
			return Long(0x7FFFFFFFFFFFFFFFi64);
		}

		template <> inline uLong minValue <uLong>()
		{
			return uLong(0x0000000000000000ui64);
		}

		template <> inline uLong maxValue <uLong>()
		{
			return uLong(0xFFFFFFFFFFFFFFFFui64);
		}
	}
}

#endif