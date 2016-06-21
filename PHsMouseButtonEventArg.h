
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_MOUSE_BUTTON_EVENT_ARG_H

#define _PHS_MOUSE_BUTTON_EVENT_ARG_H

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
			using MouseButtonEventArg = struct __PHs_Mouse_Button_Event_Argument
			{
			public:
				using MouseButton = enum __PHs_Mouse_Button : Byte
				{
					Button_Left,
					Button_Middle,
					Button_Right
				};

			public:
				Int nCursorX;
				Int nCursorY;
				MouseButton nButtonCode;
				Bool bButtonPressed;
			};
		}
	}
}

#endif