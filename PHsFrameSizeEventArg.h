
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_FRAME_SIZE_EVENT_ARG_H

#define _PHS_FRAME_SIZE_EVENT_ARG_H

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
			using FrameSizeEventArg = struct __PHs_Frame_Size_Event_Argument
			{
			public:
				uInt nFrameWidth;
				uInt nFrameHeight;
			};
		}
	}
}

#endif