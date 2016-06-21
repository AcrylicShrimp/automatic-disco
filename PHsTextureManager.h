
/*
	2016.01.28
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_MANAGER_H

#define _PHS_TEXTURE_MANAGER_H

#include "PHsCommon.h"
#include "PHsEndianness.h"
#include "PHsManagerBase.h"
#include "PHsOpenGLExt.h"
#include "PHsTexture2D.h"

#include <string>
#include <unordered_map>

#include <freeimage\FreeImage.h>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using TextureHandle = struct __PHs_Texture_Handle
		{
		public:
			uInt nReferenceCount;
			Texture2D sTexture2D;
		};

		class TextureManager final : public ManagerBase <TextureManager>
		{
		public:
			friend ManagerBase <TextureManager>;

		private:
			std::unordered_map <std::wstring, TextureHandle> sTextureHandleMap;

		public:
			TexTexelFilter eMinTexelFilter;
			TexTexelFilter eMagTexelFilter;
			TexMipmapFilter eMinMipmapFilter;
			TexWrappingMode eSWrappingMode;
			TexWrappingMode eTWrappingMode;
			Float nAnistropicMode;

		private:
			TextureManager();
			TextureManager(TextureManager &&sNewTextureManager) = delete;
			TextureManager(const TextureManager &sNewTextureManager) = delete;
			~TextureManager();

		public:
			Texture2D *getTexture(const std::wstring &sNewTexturePath, TexIntFormat eNewInternalFormat);
			Void releaseTexture(const std::wstring &sNewTexturePath);
		};
	}
}

#endif