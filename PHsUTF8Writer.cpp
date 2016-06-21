
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_UTF8_WRITER_CPP

#define _PHS_UTF8_WRITER_CPP

#include "PHsUTF8Writer.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsString
	{
		using namespace std;

		Void UTF8Writer::openWriter(const std::wstring &sNewPath, Bool bNewAppend)
		{
			if(this->bOpened)
				return;

			this->sStream.open(sNewPath, bNewAppend ? ofstream::app | ofstream::out : ofstream::out);
			this->bOpened = this->sStream.is_open();
		}

		Void UTF8Writer::writeWriter(const std::string &sNewContent)
		{
			if(this->bOpened)
				this->sStream << sNewContent;
		}
	}
}

#endif