
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_UTF8_READER_CPP

#define _PHS_UTF8_READER_CPP

#include "PHsUTF8Reader.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsString
	{
		using namespace std;

		Void UTF8Reader::readReader(const wstring &sNewPath)
		{
			this->sStream.open(sNewPath, ifstream::in);

			if(this->sStream.is_open())
			{
				this->sContent.clear();

				Int nCharacter;
				for(this->nLength = 0u ; !this->sStream.eof() && (nCharacter = this->sStream.get()) != EOF ; ++this->nLength)
					this->sContent += nCharacter;

				this->sStream.close();
			}
		}
	}
}

#endif