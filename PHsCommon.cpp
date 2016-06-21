
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_COMMON_CPP

#define _PHS_COMMON_CPP

#include "PHsCommon.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
#ifdef _DEBUG

	inline namespace PHsDebug
	{
		static const __PHs_Debug __PHS_DEBUG;
	}

#endif
}

#endif