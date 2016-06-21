
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_MOUSE_MOVE_EVENT_ARG_H

#define _PHS_MOUSE_MOVE_EVENT_ARG_H

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
			using MouseMoveEventArg = struct __PHs_Mouse_Move_Event_Argument
			{
			public:
				Int nCursorX;
				Int nCursorY;
			};
		}
	}
}

#endif