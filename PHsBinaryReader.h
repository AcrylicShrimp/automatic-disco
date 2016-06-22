
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_BINARY_READER_H

#define _PHS_BINARY_READER_H

#include "PHsCommon.h"
#include "PHsEndianness.h"

#include <cassert>
#include <fstream>
#include <string>
#include <utility>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsBinary
	{
		class BinaryReader final
		{
		private:
			std::ifstream sStream;

		public:
			BinaryReader();
			BinaryReader(BinaryReader &&sNewBinaryReader);
			BinaryReader(const BinaryReader &sNewBinaryReader) = delete;
			BinaryReader(const std::wstring &sNewPath);
			~BinaryReader();

		public:
			BinaryReader &operator=(BinaryReader &&sNewBinaryReader);
			BinaryReader &operator=(const BinaryReader &sNewBinaryReader) = delete;

			Void openReader(const std::wstring &sNewPath);
			Char readCHAR();
			Void readCHAR(Char *pNewCHARBuffer, uInt nNewCount);
			wChar readWCHAR();
			Int readINT();
			uInt readUINT();
			Float readFLOAT();
			Double readDOUBLE();
			std::string readSTRING();
			std::wstring readWSTRING();

			inline Void closeReader();
			inline Bool readerOpened() const;
			inline Bool readerEOF() const;
		};

		inline Void BinaryReader::closeReader()
		{
			this->sStream.close();
		}

		inline Bool BinaryReader::readerOpened() const
		{
			return this->sStream.is_open();
		}

		inline Bool BinaryReader::readerEOF() const
		{
			return this->sStream.eof();
		}
	}
}

#endif
