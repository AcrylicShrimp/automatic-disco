
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_FRAME_KEY_EVENT_ARG_H

#define _PHS_FRAME_KEY_EVENT_ARG_H

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
			using FrameKeyEventArg = struct __PHs_Frame_Key_Event_Argument
			{
			public:
				Byte nKeyCode;
				Bool bKeyPressed;
			};
		}
	}
}

#endif