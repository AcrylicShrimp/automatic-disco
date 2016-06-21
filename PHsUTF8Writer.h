
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_UTF8_WRITER_H

#define _PHS_UTF8_WRITER_H

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
		class UTF8Writer final
		{
		private:
			Bool bOpened{false};
			std::ofstream sStream;

		public:
			UTF8Writer() = default;
			UTF8Writer(UTF8Writer &&sNewUTF8Writer) = delete;
			UTF8Writer(const UTF8Writer &sNewUTF8Writer) = delete;
			inline UTF8Writer(const std::wstring &sNewPath, Bool bNewAppend);
			inline ~UTF8Writer();

		public:
			Void openWriter(const std::wstring &sNewPath, Bool bNewAppend);
			Void writeWriter(const std::string &sNewContent);

		public:
			inline Void closeWriter();
			inline Bool writerOpened() const;
		};

		inline UTF8Writer::UTF8Writer(const std::wstring &sNewPath, Bool bNewAppend)
		{
			this->openWriter(sNewPath, bNewAppend);
		}

		inline UTF8Writer::~UTF8Writer()
		{
			this->closeWriter();
		}

		inline Void UTF8Writer::closeWriter()
		{
			this->sStream.flush();
			this->sStream.close();

			this->bOpened = false;
		}

		inline Bool UTF8Writer::writerOpened() const
		{
			return this->bOpened;
		}
	}
}

#endif