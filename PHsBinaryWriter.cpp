
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_BINARY_WRITER_CPP

#define _PHS_BINARY_WRITER_CPP

#include "PHsBinaryWriter.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsBinary
	{
		using namespace std;

		BinaryWriter::BinaryWriter()
		{
			//Empty.
		}

		BinaryWriter::BinaryWriter(BinaryWriter &&sNewBinaryWriter) :
			sStream{move(sNewBinaryWriter.sStream)}
		{
			//Empty.
		}

		BinaryWriter::BinaryWriter(const std::wstring &sNewPath, Bool bAppend) :
			sStream{sNewPath, bAppend ? ofstream::app | ofstream::binary | ofstream::out : ofstream::binary | ofstream::out}
		{
			//Empty.
		}

		BinaryWriter::~BinaryWriter()
		{
			this->closeWriter();
		}

		BinaryWriter &BinaryWriter::operator=(BinaryWriter &&sNewBinaryWriter)
		{
			this->closeWriter();

			this->sStream = move(sNewBinaryWriter.sStream);

			return *this;
		}

		Void BinaryWriter::openWriter(const std::wstring &sNewPath, Bool bAppend)
		{
			this->sStream.open(sNewPath, bAppend ? ofstream::app | ofstream::binary | ofstream::out : ofstream::binary | ofstream::out);
		}

		Void BinaryWriter::writeBinary(Char CHAR)
		{
			assert(this->writerOpened());

			this->sStream.put(CHAR);
		}

		Void BinaryWriter::writeBinary(Char *pCHAR, uInt nNewCount)
		{
			assert(this->writerOpened());

			this->sStream.write(pCHAR, nNewCount);
		}

		Void BinaryWriter::writeBinary(wChar WCHAR)
		{
			assert(this->writerOpened());

			union
			{
			public:
				wChar WCHAR;
				Char CHAR[sizeof(wChar)];
			}WCHAR2CHAR;

			WCHAR2CHAR.WCHAR = WCHAR;

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&WCHAR2CHAR.WCHAR);

			this->sStream.write(WCHAR2CHAR.CHAR, sizeof(wChar));
		}

		Void BinaryWriter::writeBinary(Int INT)
		{
			assert(this->writerOpened());

			union
			{
			public:
				Int INT;
				Char CHAR[sizeof(Int)];
			}INT2CHAR;

			INT2CHAR.INT = INT;

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&INT2CHAR.INT);

			this->sStream.write(INT2CHAR.CHAR, sizeof(Int));
		}

		Void BinaryWriter::writeBinary(uInt UINT)
		{
			assert(this->writerOpened());

			union
			{
			public:
				uInt UINT;
				Char CHAR[sizeof(uInt)];
			}UINT2CHAR;

			UINT2CHAR.UINT = UINT;

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&UINT2CHAR.UINT);

			this->sStream.write(UINT2CHAR.CHAR, sizeof(uInt));
		}

		Void BinaryWriter::writeBinary(Float FLOAT)
		{
			assert(this->writerOpened());

			union
			{
			public:
				Float FLOAT;
				Char CHAR[sizeof(Float)];
			}FLOAT2CHAR;

			FLOAT2CHAR.FLOAT = FLOAT;

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&FLOAT2CHAR.FLOAT);

			this->sStream.write(FLOAT2CHAR.CHAR, sizeof(Float));
		}

		Void BinaryWriter::writeBinary(Double DOUBLE)
		{
			assert(this->writerOpened());

			union
			{
			public:
				Double DOUBLE;
				Char CHAR[sizeof(Double)];
			}DOUBLE2CHAR;

			DOUBLE2CHAR.DOUBLE = DOUBLE;

			if(!Endianness::littleEndian())
				Endianness::swapByteOrder(&DOUBLE2CHAR.DOUBLE);

			this->sStream.write(DOUBLE2CHAR.CHAR, sizeof(Double));
		}

		Void BinaryWriter::writeBinary(const std::string &STRING)
		{
			assert(this->writerOpened());

			this->writeBinary(STRING.length());

			for(Char CHAR : STRING)
				this->writeBinary(CHAR);
		}

		Void BinaryWriter::writeBinary(const std::wstring &WSTRING)
		{
			assert(this->writerOpened());

			this->writeBinary(WSTRING.length());
			
			for(wChar WCHAR : WSTRING)
				this->writeBinary(WCHAR);
		}
	}
}

#endif