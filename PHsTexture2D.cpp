
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_2D_CPP

#define _PHS_TEXTURE_2D_CPP

#include "PHsTexture2D.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using namespace std;

		Texture2D::Texture2D(Texture2D &&sNewTexture2D)
		{
			this->Texture::Texture(move(sNewTexture2D));
		}

		Texture2D &Texture2D::operator=(Texture2D &&sNewTexture2D)
		{
			this->Texture::operator=(move(sNewTexture2D));

			return *this;
		}

		Void Texture2D::activeTexture(Texture2D &sNewTexture2D)
		{
			glBindTexture(GL_TEXTURE_2D, sNewTexture2D);
		}

		Void Texture2D::specifyTextureMinifyingFilter(TexTexelFilter eNewMinTexelFilter, TexMipmapFilter eNewMinMipmapFilter)
		{
			switch(eNewMinMipmapFilter)
			{
			case TexMipmapFilter::Mipmap_None:
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, eNewMinTexelFilter);
			}
			return;
			case TexMipmapFilter::Mipmap_Linear:
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, eNewMinTexelFilter == TexTexelFilter::Texel_Linear ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_LINEAR);
				OpenGLExt::glGenerateMipmap(GL_TEXTURE_2D);
			}
			return;
			case TexMipmapFilter::Mipmap_Nearest:
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, eNewMinTexelFilter == TexTexelFilter::Texel_Linear ? GL_LINEAR_MIPMAP_NEAREST : GL_NEAREST_MIPMAP_NEAREST);
				OpenGLExt::glGenerateMipmap(GL_TEXTURE_2D);
			}
			default:
			return;
			}
		}

		Void Texture2D::specifyTextureMagnificationFilter(TexTexelFilter eNewMagFilter)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, eNewMagFilter);
		}

		Void Texture2D::specifyTextureSWrappingMode(TexWrappingMode eNewSWrapMode)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, eNewSWrapMode);
		}

		Void Texture2D::specifyTextureTWrappingMode(TexWrappingMode eNewTWrapMode)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, eNewTWrapMode);
		}

		Void Texture2D::specifyTextureAnisotropicMode(Float nNewAnisotropicMode)
		{
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, nNewAnisotropicMode);
		}

		Void Texture2D::specifyTextureTexel(uInt nNewTexWidth, uInt nNewTexHeight, TexIntFormat eNewIntFormat)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, eNewIntFormat, nNewTexWidth, nNewTexHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
		}

		Void Texture2D::specifyTextureTexel(uInt nNewTexWidth, uInt nNewTexHeight, TexIntFormat eNewIntFormat, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, eNewIntFormat, nNewTexWidth, nNewTexHeight, 0, eNewExtFormat, eNewTexelType, pNewTexel);
		}

		Void Texture2D::updateTextureTexel(Int nNewOffsetX, Int nNewOffsetY, uInt nNewTexWidth, uInt nNewTexHeight, TexExtFormat eNewExtFormat, TexTexelType eNewTexelType, const Void *pNewTexel)
		{
			glTexSubImage2D(GL_TEXTURE_2D, 0, nNewOffsetX, nNewOffsetY, nNewTexWidth, nNewTexHeight, eNewExtFormat, eNewTexelType, pNewTexel);
		}
	}
}

#endif