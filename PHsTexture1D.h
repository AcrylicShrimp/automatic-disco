
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_1D_H

#define _PHS_TEXTURE_1D_H

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
		class Texture1D final : public Texture
		{
		public:
			Texture1D() = default;
			Texture1D(Texture1D &&sNewTexture1D);
			Texture1D(const Texture1D &sNewTexture1D) = delete;
			~Texture1D() = default;

		public:
			Texture1D &operator=(Texture1D &&sNewTexture1D);
			Texture1D &operator=(const Texture1D &sNewTexture1D) = delete;

		public:
			static Void activeTexture(Texture1D &sNewTexture1D);
			static Void specifyTextureMinifyingFilter(TexTexelFilter eNewMinTexelFilter, TexMipmapFilter eNewMinMipmapFilter);
			static Void specifyTextureMagnificationFilter(TexTexelFilter eNewMagFilter);
			static Void specifyTextureSWrappingMode(TexWrappingMode eNewSWrapMode);
			static Void specifyTextureAnisotropicMode(Float nNewAnisotropicMode);
			static Void specifyTextureTexel(uInt nNewTexWidth, TexIntFormat eNewIntFormat);
			static Void specifyTextureTexel(uInt nNewTexWidth, TexIntFormat eNewIntFormat, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel);
			static Void updateTextureTexel(Int nNewOffsetX, uInt nNewTexWidth, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel);
		};
	}
}

#endif