
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_CUSTOM_EVENT_ARG_H

#define _PHS_CUSTOM_EVENT_ARG_H

#include "PHsCommon.h"
#include "PHsEvent.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsEvent
	{
		inline namespace PHsEventArgs
		{
			using CustomEventArg = struct __PHs_Custom_Event_Argument
			{
			public:
				uLong nCustomEventCode;
				Void *pCustomEventFirstArg;
				Void *pCustomEventSecondArg;
			};
		}
	}
}

#endif