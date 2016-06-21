
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_ENDIANNESS_CPP

#define _PHS_ENDIANNESS_CPP

#include "PHsEndianness.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsEndianness
	{
		Bool Endianness::blittleEndian = Endianness::checkEndian();

		Bool Endianness::checkEndian()
		{
			union
			{
			public:
				uShort SHORT;
				Byte BYTE[sizeof(uShort)];
			}CHECKER;

			CHECKER.SHORT = 1u;
			return CHECKER.BYTE[0] == 1u;
		}
	}
}

#endif