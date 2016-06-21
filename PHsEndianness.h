
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_ENDIANNESS_H

#define _PHS_ENDIANNESS_H

#include "PHsCommon.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsEndianness
	{
		class Endianness
		{
		private:
			static Bool blittleEndian;

		public:
			Endianness() = delete;
			Endianness(Endianness &&sNewEndianness) = delete;
			Endianness(const Endianness &sNewEndianness) = delete;
			~Endianness() = delete;

		public:
			template <class __Value_Type> static Void swapByteOrder(__Value_Type *pValue);

			inline static Bool littleEndian();

		private:
			static Bool checkEndian();
		};

		inline Bool Endianness::littleEndian()
		{
			return Endianness::blittleEndian;
		}
	}
}

#include "PHsEndianness.hpp"

#endif