
/*
	2016.01.25
	Created by PHJ.
*/

#ifndef _PHS_ENTRY_H

#define _PHS_ENTRY_H

#include "PHsCommon.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsEntry
	{
		class Entry
		{
		public:
			static Entry *pEntry;

		public:
			Entry();
			Entry(Entry &&sNewEntry) = default;
			Entry(const Entry &sNewEntry) = default;
			virtual ~Entry() = default;

		public:
			inline static Void stopEntry();
			inline static Bool entryRunning();

			virtual Void entryInitialize() = 0;
			virtual Void entryFinalize() = 0;
			virtual Void entryFrame() = 0;
		};

		inline Void Entry::stopEntry()
		{
			Entry::pEntry = nullptr;
		}

		inline Bool Entry::entryRunning()
		{
			return Entry::pEntry != nullptr;
		}
	}
}

#endif