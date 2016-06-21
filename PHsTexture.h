
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_TEXTURE_H

#define _PHS_TEXTURE_H

#include "PHsCommon.h"
#include "PHsOpenGLExt.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using TexDimension = enum __PHs_Texture_Dimension : Int
		{
			//1D texture
			Tex_1D = GL_TEXTURE_1D,

			//2D texture
			Tex_2D = GL_TEXTURE_2D
		};

		using TexTexelFilter = enum __PHs_Texture_Texel_Filter : Int
		{
			//Linear-interpolate a few adjacent texels
			Texel_Linear = GL_LINEAR,

			//Choose the nearest texel
			Texel_Nearest = GL_NEAREST
		};

		using TexMipmapFilter = enum __PHs_Texture_Mipmap_Filter : Int
		{
			//Disable the mipmap, the mipmap will not be generated
			Mipmap_None,

			//Enable the mipmap, and choose a linear-interpolated mipmap, based on the LOD bias
			Mipmap_Linear,

			//Enable the mipmap, and choose a nearest mipmap, based on the LOD bias
			Mipmap_Nearest
		};

		using TexWrappingMode = enum __PHs_Texture_Wrapping_Mode : Int
		{
			Wrap_Clamp_Border = GL_CLAMP_TO_BORDER,
			Wrap_Clamp_Edge = GL_CLAMP_TO_EDGE,
			Wrap_Clamp_Edge_Mirrored = GL_MIRROR_CLAMP_TO_EDGE,
			Wrap_Repeat = GL_REPEAT,
			Wrap_Repeat_Mirrored = GL_MIRRORED_REPEAT
		};

		using TexExtFormat = enum __PHs_Texture_External_Format : Int
		{
			Ext_R = GL_RED,
			Ext_RG = GL_RG,
			Ext_RGB = GL_RGB,
			Ext_BGR = GL_BGR,
			Ext_RGBA = GL_RGBA,
			Ext_BGRA = GL_BGRA,
			Ext_R_I = GL_RED_INTEGER,
			Ext_RG_I = GL_RG_INTEGER,
			Ext_RGB_I = GL_RGB_INTEGER,
			Ext_BGR_I = GL_BGR_INTEGER,
			Ext_RGBA_I = GL_RGBA_INTEGER,
			Ext_BGRA_I = GL_BGRA_INTEGER,
			Ext_Depth = GL_DEPTH_COMPONENT,
			Ext_Stencil = GL_DEPTH_STENCIL,
			Ext_Stencil_Index = GL_STENCIL_INDEX
		};

		using TexIntFormat = enum __PHs_Texture_Internal_Format : Int
		{
			Int_Depth = GL_DEPTH_COMPONENT,
			Int_Stencil = GL_DEPTH_STENCIL,
			Int_R = GL_RED,
			Int_RG = GL_RG,
			Int_RGB = GL_RGB,
			Int_RGBA = GL_RGBA,
			Int_R8 = GL_R8,
			Int_R16 = GL_R16,
			Int_RG8 = GL_RG8,
			Int_RG16 = GL_RG16,
			Int_R3G3B2 = GL_R3_G3_B2,
			Int_RGB4 = GL_RGB4,
			Int_RGB5 = GL_RGB5,
			Int_RGB8 = GL_RGB8,
			Int_RGB10 = GL_RGB10,
			Int_RGB12 = GL_RGB12,
			Int_RGBA2 = GL_RGBA2,
			Int_RGBA4 = GL_RGBA4,
			Int_R5G5B5A1 = GL_RGB5_A1,
			Int_RGBA8 = GL_RGBA8,
			Int_R10G10B10A2 = GL_RGB10_A2,
			Int_R10G10B10A2_UI = GL_RGB10_A2UI,
			Int_RGBA12 = GL_RGBA12,
			Int_RGBA16 = GL_RGBA16,
			Int_R16_F = GL_R16F,
			Int_RG16_F = GL_RG16F,
			Int_RGB16_F = GL_RGB16F,
			Int_RGBA16_F = GL_RGBA16F,
			Int_R32_F = GL_R32F,
			Int_RG32_F = GL_RG32F,
			Int_RGB32_F = GL_RGB32F,
			Int_RGBA32_F = GL_RGBA32F,
			Int_R11G11B10_F = GL_R11F_G11F_B10F,
			Int_R9G9B9E5 = GL_RGB9_E5,			//E : Shared bit
			Int_R8I = GL_R8I,
			Int_R8UI = GL_R8UI,
			Int_R16I = GL_R16I,
			Int_R16UI = GL_R16UI,
			Int_R32I = GL_R32I,
			Int_R32UI = GL_R32UI,
			Int_RG8I = GL_RG8I,
			Int_RG8UI = GL_RG8UI,
			Int_RG16I = GL_RG16I,
			Int_RG16UI = GL_RG16UI,
			Int_RG32I = GL_RG32I,
			Int_RG32UI = GL_RG32UI,
			Int_RGB8I = GL_RGB8I,
			Int_RGB8UI = GL_RGB8UI,
			Int_RGB16I = GL_RGB16I,
			Int_RGB16UI = GL_RGB16UI,
			Int_RGB32I = GL_RGB32I,
			Int_RGB32UI = GL_RGB32UI,
			Int_RGBA8I = GL_RGBA8I,
			Int_RGBA8UI = GL_RGBA8UI,
			Int_RGBA16I = GL_RGBA16I,
			Int_RGBA16UI = GL_RGBA16UI,
			Int_RGBA32I = GL_RGBA32I,
			Int_RGBA32UI = GL_RGBA32UI
		};

		using TexTexelType = enum __PHs_Texture_Texel_Type : Int
		{
			TexelType_Byte = GL_BYTE,
			TexelType_uByte = GL_UNSIGNED_BYTE,
			TexelType_Short = GL_SHORT,
			TexelType_uShort = GL_UNSIGNED_SHORT,
			TexelType_Int = GL_INT,
			TexelType_uInt = GL_UNSIGNED_INT,
			TexelType_Float = GL_FLOAT
		};

		class Texture
		{
		protected:
			static uInt nCurrentTextureSlot;

		protected:
			uInt nTexture{0u};

		protected:
			Texture() = default;
			Texture(Texture &&sNewTexture);
			Texture(const Texture &sNewTexture) = delete;
			virtual ~Texture();

		public:
			inline operator uInt() const;

		public:
			Texture &operator=(Texture &&sNewTexture);
			Texture &operator=(const Texture &sNewTexture) = delete;

			Void initializeTexture();
			Void finalizeTexture();

			inline uInt textureID() const;

		public:
			inline static Void activeTextureSlot(uInt nNewTextureSlot);
		};

		inline Texture::operator uInt() const
		{
			return this->nTexture;
		}

		inline uInt Texture::textureID() const
		{
			return *this;
		}

		inline Void Texture::activeTextureSlot(uInt nNewTextureSlot)
		{
			OpenGLExt::glActiveTexture((Texture::nCurrentTextureSlot = nNewTextureSlot) + GL_TEXTURE0);
		}
	}
}

#endif