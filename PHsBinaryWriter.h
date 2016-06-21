
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_BINARY_WRITER_H

#define _PHS_BINARY_WRITER_H

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
		class BinaryWriter final
		{
		private:
			std::ofstream sStream;

		public:
			BinaryWriter();
			BinaryWriter(BinaryWriter &&sNewBinaryWriter);
			BinaryWriter(const BinaryWriter &sNewBinaryWriter) = delete;
			BinaryWriter(const std::wstring &sNewPath, Bool bAppend);
			~BinaryWriter();

		public:
			BinaryWriter &operator=(BinaryWriter &&sNewBinaryWriter);
			BinaryWriter &operator=(const BinaryWriter &sNewBinaryWriter) = delete;

			Void openWriter(const std::wstring &sNewPath, Bool bAppend);
			Void writeBinary(Char CHAR);
			Void writeBinary(Char *pCHAR, uInt nNewCount);
			Void writeBinary(wChar WCHAR);
			Void writeBinary(Int INT);
			Void writeBinary(uInt UINT);
			Void writeBinary(Float FLOAT);
			Void writeBinary(Double DOUBLE);
			Void writeBinary(const std::string &STRING);
			Void writeBinary(const std::wstring &WSTRING);

			inline Void closeWriter();
			inline Bool writerOpened() const;
		};

		inline Void BinaryWriter::closeWriter()
		{
			this->sStream.close();
		}

		inline Bool BinaryWriter::writerOpened() const
		{
			return this->sStream.is_open();
		}
	}
}

#endif