
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_EVENT_H

#define _PHS_EVENT_H

#include "PHsCommon.h"

#include <cassert>
#include <vector>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsEvent
	{
		template <class EventArg> INTERFACE(EventHandler)
		{
		public:
			virtual Void onEvent(const EventArg &sEventArg) = 0;
		};

		template <class EventArg> class Event
		{
		public:
			using EventHandlerVector = std::vector <EventHandler <EventArg> *>;

		private:
			static EventHandlerVector sEventHandlerVector;

		private:
			Event() = delete;
			Event(Event &&sNewEvent) = delete;
			Event(const Event &sNewEvent) = delete;
			~Event() = delete;

		public:
			inline static Void registerEventHandler(EventHandler <EventArg> *pNewHandler);
			inline static Void unregisterEventHandler(EventHandler <EventArg> *pNewHandler);
			inline static Void callEvent(const EventArg &sNewEventArg);
		};
	}
}

#include "PHsEvent.hpp"

#endif