
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_ENTRY_CPP

#define _PHS_ENTRY_CPP

#include "PHsEntry.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsEntry
	{
		Entry *Entry::pEntry = nullptr;

		Entry::Entry()
		{
			Entry::pEntry = this;
		}
	}
}

#endif