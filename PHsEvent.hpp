
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_EVENT_HPP

#define _PHS_EVENT_HPP

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsEvent
	{
		template <class EventArg> typename Event <EventArg>::EventHandlerVector Event <EventArg>::sEventHandlerVector;

		template <class EventArg> inline Void Event <EventArg>::registerEventHandler(EventHandler <EventArg> *pNewHandler)
		{
			assert(pNewHandler);
			Event <EventArg>::sEventHandlerVector.push_back(pNewHandler);
		}

		template <class EventArg> inline Void Event <EventArg>::unregisterEventHandler(EventHandler <EventArg> *pNewHandler)
		{
			auto iEnd = Event <EventArg>::sEventHandlerVector.cend();
			for(auto iIndex = Event <EventArg>::sEventHandlerVector.cbegin() ; iIndex != iEnd ; ++iIndex)
			{
				if(*iIndex == pNewHandler)
				{
					Event <EventArg>::sEventHandlerVector.erase(iIndex);
					return;
				}
			}
		}

		template <class EventArg> inline Void Event <EventArg>::callEvent(const EventArg &sNewEventArg)
		{
			for(EventHandler <EventArg> *pEventHandler : Event <EventArg>::sEventHandlerVector)
				pEventHandler->onEvent(sNewEventArg);
		}
	}
}

#endif