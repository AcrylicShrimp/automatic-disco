
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_2D_H

#define _PHS_TEXTURE_2D_H

#include "PHsCommon.h"
#include "PHsOpenGLExt.h"
#include "PHsTexture.h"

#include <unordered_map>
#include <utility>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		class Texture2D final : public Texture
		{
		public:
			Texture2D() = default;
			Texture2D(Texture2D &&sNewTexture2D);
			Texture2D(const Texture2D &sNewTexture2D) = delete;
			~Texture2D() = default;

		public:
			Texture2D &operator=(Texture2D &&sNewTexture2D);
			Texture2D &operator=(const Texture2D &sNewTexture2D) = delete;

		public:
			static Void activeTexture(Texture2D &sNewTexture2D);
			static Void specifyTextureMinifyingFilter(TexTexelFilter eNewMinTexelFilter, TexMipmapFilter eNewMinMipmapFilter);
			static Void specifyTextureMagnificationFilter(TexTexelFilter eNewMagFilter);
			static Void specifyTextureSWrappingMode(TexWrappingMode eNewSWrapMode);
			static Void specifyTextureTWrappingMode(TexWrappingMode eNewTWrapMode);
			static Void specifyTextureAnisotropicMode(Float nNewAnisotropicMode);
			static Void specifyTextureTexel(uInt nNewTexWidth, uInt nNewTexHeight, TexIntFormat eNewIntFormat);
			static Void specifyTextureTexel(uInt nNewTexWidth, uInt nNewTexHeight, TexIntFormat eNewIntFormat, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel);
			static Void updateTextureTexel(Int nNewOffsetX, Int nNewOffsetY, uInt nNewTexWidth, uInt nNewTexHeight, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel);
		};
	}
}

#endif