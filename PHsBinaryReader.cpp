
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_BINARY_READER_CPP

#define _PHS_BINARY_READER_CPP

#include "PHsBinaryReader.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsBinary
	{
		using namespace std;

		BinaryReader::BinaryReader()
		{
			//Empty.
		}

		BinaryReader::BinaryReader(BinaryReader &&sNewBinaryReader) :
			sStream{move(sNewBinaryReader.sStream)}
		{
			//Empty.
		}

		BinaryReader::BinaryReader(const wstring &sNewPath) :
			sStream{sNewPath, ifstream::binary | ifstream::in}
		{
			//Empty.
		}

		BinaryReader::~BinaryReader()
		{
			this->closeReader();
		}

		BinaryReader &BinaryReader::operator=(BinaryReader &&sNewBinaryReader)
		{
			this->closeReader();

			this->sStream = move(sNewBinaryReader.sStream);

			return *this;
		}

		Void BinaryReader::openReader(const wstring &sNewPath)
		{
			this->sStream.open(sNewPath, ifstream::binary | ifstream::in);
		}

		Char BinaryReader::readCHAR()
		{
			return static_cast <Char>(this->sStream.get());
		}

		Void BinaryReader::readCHAR(Char *pNewCHARBuffer, uInt nNewCount)
		{
			assert(this->readerOpened() && !this->readerEOF());

			this->sStream.read(pNewCHARBuffer, nNewCount);
		}

		wChar BinaryReader::readWCHAR()
		{
			assert(this->readerOpened() && !this->readerEOF());

			union
			{
			public:
				wChar WCHAR;
				Char CHAR[sizeof(wChar)];
			}CHAR2WCHAR;

			this->sStream.read(CHAR2WCHAR.CHAR, sizeof(wChar));

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&CHAR2WCHAR.WCHAR);

			return CHAR2WCHAR.WCHAR;
		}

		Int BinaryReader::readINT()
		{
			assert(this->readerOpened() && !this->readerEOF());

			union
			{
			public:
				Int INT;
				Char CHAR[sizeof(Int)];
			}CHAR2INT;

			this->sStream.read(CHAR2INT.CHAR, sizeof(Int));

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&CHAR2INT.INT);

			return CHAR2INT.INT;
		}

		uInt BinaryReader::readUINT()
		{
			assert(this->readerOpened() && !this->readerEOF());

			union
			{
			public:
				uInt UINT;
				Char CHAR[sizeof(uInt)];
			}CHAR2UINT;

			this->sStream.read(CHAR2UINT.CHAR, sizeof(uInt));

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&CHAR2UINT.UINT);

			return CHAR2UINT.UINT;
		}

		Float BinaryReader::readFLOAT()
		{
			assert(this->readerOpened() && !this->readerEOF());

			union
			{
			public:
				Float FLOAT;
				Char CHAR[sizeof(Float)];
			}CHAR2FLOAT;

			this->sStream.read(CHAR2FLOAT.CHAR, sizeof(Float));

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&CHAR2FLOAT.FLOAT);

			return CHAR2FLOAT.FLOAT;
		}

		Double BinaryReader::readDOUBLE()
		{
			union
			{
			public:
				Double DOUBLE;
				Char CHAR[sizeof(Double)];
			}CHAR2DOUBLE;

			this->sStream.read(CHAR2DOUBLE.CHAR, sizeof(Double));

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&CHAR2DOUBLE.DOUBLE);

			return CHAR2DOUBLE.DOUBLE;
		}

		string BinaryReader::readSTRING()
		{
			assert(this->readerOpened() && !this->readerEOF());

			uInt nLength = this->readUINT();

			string sString;
			sString.reserve(nLength);

			for(uInt nIndex = 0u ; nIndex < nLength ; ++nIndex)
				sString += this->readCHAR();

			return sString;
		}

		wstring BinaryReader::readWSTRING()
		{
			assert(this->readerOpened() && !this->readerEOF());

			uInt nLength = this->readUINT();

			wstring sString;
			sString.reserve(nLength);

			for(uInt nIndex = 0u ; nIndex < nLength ; ++nIndex)
				sString += this->readWCHAR();

			return sString;
		}
	}
}

#endif