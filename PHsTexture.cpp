
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_CPP

#define _PHS_TEXTURE_CPP

#include "PHsTexture.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		uInt Texture::nCurrentTextureSlot{0u};

		Texture::Texture(Texture &&sNewTexture)
		{
			this->nTexture = sNewTexture.nTexture;
			sNewTexture.nTexture = 0u;
		}

		Texture::~Texture()
		{
			this->finalizeTexture();
		}

		Texture &Texture::operator=(Texture &&sNewTexture)
		{
			glDeleteTextures(1u, &this->nTexture);
			this->nTexture = sNewTexture;
			sNewTexture.nTexture = 0u;

			return *this;
		}

		Void Texture::initializeTexture()
		{
			glGenTextures(1u, &this->nTexture);
		}

		Void Texture::finalizeTexture()
		{
			if(this->nTexture)
				glDeleteTextures(1u, &this->nTexture), this->nTexture = 0u;
		}
	}
}

#endif