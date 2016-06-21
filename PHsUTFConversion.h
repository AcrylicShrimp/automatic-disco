
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_UTF_CONVERSION_H

#define _PHS_UTF_CONVERSION_H

#include "PHsCommon.h"

#include <string>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsString
	{
		class UTFConversion
		{
		public:
			UTFConversion() = delete;
			UTFConversion(UTFConversion &&sNewUTFConversion) = delete;
			UTFConversion(const UTFConversion &sNewUTFConversion) = delete;
			~UTFConversion() = delete;

		public:
			static Void toUTF8(const std::wstring &sSrc, std::string &sDst);
			static Void toUTF16(const std::string &sSrc, std::wstring &sDst);

			inline static uInt toUTF8(wChar nSrc, Char vDst[3]);
			inline static wChar toUTF16(std::string::const_iterator &iSrc);
		};

		inline uInt UTFConversion::toUTF8(wChar nSrc, Char vDst[3])
		{
			uShort nWideChar = static_cast <uShort>(nSrc);

			if(nWideChar < 0x80u)
			{
				vDst[0] = static_cast <Char>(nSrc);

				return 1u;
			}
			else if(nWideChar < 0x800u)
			{
				Byte vBuf[2] =
				{
					static_cast <Byte>((static_cast <uShort>(nSrc) & 0xFF00u) >> 8u),
					static_cast <Byte>(static_cast <uShort>(nSrc) & 0xFFu),
				};

				vBuf[0] = vBuf[0] << 2u | vBuf[1] >> 6u | 0xC0u;
				vBuf[1] = vBuf[1] & 0x3Fu | 0x80u;

				vDst[0] = static_cast <Char>(vBuf[0]);
				vDst[1] = static_cast <Char>(vBuf[1]);

				return 2u;
			}
			else
			{
				Byte vBuf[3] =
				{
					0u,
					static_cast <Byte>((static_cast <uShort>(nSrc) & 0xFF00u) >> 8u),
					static_cast <Byte>(static_cast <uShort>(nSrc) & 0xFFu),
				};

				vBuf[0] = vBuf[1] >> 4u | 0xE0u;
				vBuf[1] = (vBuf[1] & 0xFu) << 2u | vBuf[2] >> 6u | 0x80u;
				vBuf[2] = vBuf[2] & 0x3Fu | 0x80u;

				vDst[0] = static_cast <Char>(vBuf[0]);
				vDst[1] = static_cast <Char>(vBuf[1]);
				vDst[2] = static_cast <Char>(vBuf[2]);

				return 3u;
			}
		}

		inline wChar UTFConversion::toUTF16(std::string::const_iterator &iSrc)
		{
			Byte nByteChar = *iSrc;

			if(nByteChar < 0x80u)
				return *iSrc++;
			else if((nByteChar & 0xE0u) == 0xC0u)
			{
				wChar nFirst = *iSrc++ & 0x1F;
				wChar nLast = *iSrc++ & 0x3F;

				nLast |= nFirst << 6u;
				nFirst >>= 2u;

				return nFirst << 8u | nLast;
			}
			else if((nByteChar & 0xF0u) == 0xE0u)
			{
				wChar nFirst = (*iSrc++ & 0xF) << 4u;
				wChar nLast = *iSrc++ & 0x3F;

				nFirst |= nLast >> 2u;
				nLast = nLast << 6u | *iSrc++ & 0x3F;

				return nFirst << 8u | nLast;
			}
			else
				return ++iSrc, L'?';
		}
	}
}

#endif