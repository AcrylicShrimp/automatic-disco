
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_UTF8_READER_H

#define _PHS_UTF8_READER_H

#include "PHsCommon.h"

#include <string>
#include <fstream>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsString
	{
		class UTF8Reader final
		{
		private:
			uInt nLength{0u};
			std::string sContent;
			std::ifstream sStream;

		public:
			UTF8Reader() = default;
			UTF8Reader(UTF8Reader &&sNewUTF8Reader) = delete;
			UTF8Reader(const UTF8Reader &sNewUTF8Reader) = delete;
			inline UTF8Reader(const std::wstring &sNewPath);
			~UTF8Reader() = default;

		public:
			Void readReader(const std::wstring &sNewPath);

		public:
			inline uInt readerLength() const;
			inline const std::string &readerContent() const;
		};

		inline UTF8Reader::UTF8Reader(const std::wstring &sNewPath)
		{
			this->readReader(sNewPath);
		}

		inline uInt UTF8Reader::readerLength() const
		{
			return this->nLength;
		}

		inline const std::string &UTF8Reader::readerContent() const
		{
			return this->sContent;
		}
	}
}

#endif