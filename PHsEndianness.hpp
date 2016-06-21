
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_ENDIANNESS_HPP

#define _PHS_ENDIANNESS_HPP

namespace PHs
{
	/*
		TODO : Place your code here
	*/

	inline namespace PHsEndianness
	{
		template <class __Value_Type> Void Endianness::swapByteOrder(__Value_Type *pValue)
		{
			union
			{
			public:
				__Value_Type VALUE;
				Byte BYTE[sizeof(__Value_Type)];
			}TEMP;

			TEMP.VALUE = *pValue;

			for(uInt nIndex = 0u, nReversed = sizeof(__Value_Type) - 1u ; nIndex < sizeof(__Value_Type) ; ++nIndex, --nReversed)
				pValue[nIndex] = TEMP.BYTE[nReversed];
		}
	}
}

#endif