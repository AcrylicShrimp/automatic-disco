
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_1D_CPP

#define _PHS_TEXTURE_1D_CPP

#include "PHsTexture1D.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using namespace std;

		Texture1D::Texture1D(Texture1D &&sNewTexture1D)
		{
			this->Texture::Texture(move(sNewTexture1D));
		}

		Texture1D &Texture1D::operator=(Texture1D &&sNewTexture1D)
		{
			this->Texture::operator=(move(sNewTexture1D));

			return *this;
		}

		Void Texture1D::activeTexture(Texture1D &sNewTexture1D)
		{
			glBindTexture(GL_TEXTURE_1D, sNewTexture1D);
		}

		Void Texture1D::specifyTextureMinifyingFilter(TexTexelFilter eNewMinTexelFilter, TexMipmapFilter eNewMinMipmapFilter)
		{
			switch(eNewMinMipmapFilter)
			{
			case TexMipmapFilter::Mipmap_None:
			{
				glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, eNewMinTexelFilter);
			}
			return;
			case TexMipmapFilter::Mipmap_Linear:
			{
				glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, eNewMinTexelFilter == TexTexelFilter::Texel_Linear ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_LINEAR);
				OpenGLExt::glGenerateMipmap(GL_TEXTURE_1D);
			}
			return;
			case TexMipmapFilter::Mipmap_Nearest:
			{
				glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, eNewMinTexelFilter == TexTexelFilter::Texel_Linear ? GL_LINEAR_MIPMAP_NEAREST : GL_NEAREST_MIPMAP_NEAREST);
				OpenGLExt::glGenerateMipmap(GL_TEXTURE_1D);
			}
			default:
			return;
			}
		}

		Void Texture1D::specifyTextureMagnificationFilter(TexTexelFilter eNewMagFilter)
		{
			glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, eNewMagFilter);
		}
		
		Void Texture1D::specifyTextureSWrappingMode(TexWrappingMode eNewSWrapMode)
		{
			glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, eNewSWrapMode);
		}
		
		Void Texture1D::specifyTextureAnisotropicMode(Float nNewAnisotropicMode)
		{
			glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAX_ANISOTROPY_EXT, nNewAnisotropicMode);
		}
		
		Void Texture1D::specifyTextureTexel(uInt nNewTexWidth, TexIntFormat eNewIntFormat)
		{
			glTexImage1D(GL_TEXTURE_1D, 0, eNewIntFormat, nNewTexWidth, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
		}
		
		Void Texture1D::specifyTextureTexel(uInt nNewTexWidth, TexIntFormat eNewIntFormat, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel)
		{
			glTexImage1D(GL_TEXTURE_1D, 0, eNewIntFormat, nNewTexWidth, 0, eNewExtFormat, eNewTexelType, pNewTexel);
		}

		Void Texture1D::updateTextureTexel(Int nNewOffsetX, uInt nNewTexWidth, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel)
		{
			glTexSubImage1D(GL_TEXTURE_1D, 0, nNewOffsetX, nNewTexWidth, eNewExtFormat, eNewTexelType, pNewTexel);
		}
	}
}

#endif