
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_UTF_CONVERSION_CPP

#define _PHS_UTF_CONVERSION_CPP

#include "PHsUTFConversion.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsString
	{
		Void UTFConversion::toUTF8(const std::wstring &sSrc, std::string &sDst)
		{
			sDst.clear();

			Char vDst[3]
			{
				//Empty.
			};

			for(wChar wSrc : sSrc)
			{
				uInt nLength = UTFConversion::toUTF8(wSrc, vDst);

				for(uInt nIndex = 0u ; nIndex < nLength ; ++nIndex)
					sDst += vDst[nIndex];
			}
		}

		Void UTFConversion::toUTF16(const std::string &sSrc, std::wstring &sDst)
		{
			sDst.clear();

			for(auto iIndex = sSrc.cbegin(), iEnd = sSrc.cend() ; iIndex != iEnd && *iIndex != EOF ; )
				sDst += UTFConversion::toUTF16(iIndex);
		}
	}
}

#endif