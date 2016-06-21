
/*
	2016.02.03
	Created by PHJ.
*/

#ifndef _PHS_RENDER_BUFFER_H

#define _PHS_RENDER_BUFFER_H

#include "PHsCommon.h"
#include "PHsOpenGLExt.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using RenderBufferType = enum __PHs_Render_Buffer_Type : uInt
		{
			RenderBufferType_R8 = GL_R8,
			RenderBufferType_R16 = GL_R16,
			RenderBufferType_R8I = GL_R8I,
			RenderBufferType_R16I = GL_R16I,
			RenderBufferType_R32I = GL_R32I,
			RenderBufferType_R8UI = GL_R8UI,
			RenderBufferType_R16UI = GL_R16UI,
			RenderBufferType_R32UI = GL_R32UI,
			RenderBufferType_R16F = GL_R16F,
			RenderBufferType_R32F = GL_R32F,

			RenderBufferType_RG8 = GL_RG8,
			RenderBufferType_RG16 = GL_RG16,
			RenderBufferType_RG8I = GL_RG8I,
			RenderBufferType_RG16I = GL_RG16I,
			RenderBufferType_RG32I = GL_RG32I,
			RenderBufferType_RG8UI = GL_RG8UI,
			RenderBufferType_RG16UI = GL_RG16UI,
			RenderBufferType_RG32UI = GL_RG32UI,
			RenderBufferType_RG16F = GL_RG16F,
			RenderBufferType_RG32F = GL_RG32F,

			RenderBufferType_RGBA8 = GL_RGBA8,
			RenderBufferType_RGBA16 = GL_RGBA16,
			RenderBufferType_RGBA8I = GL_RGBA8I,
			RenderBufferType_RGBA16I = GL_RGBA16I,
			RenderBufferType_RGBA32I = GL_RGBA32I,
			RenderBufferType_RGBA8UI = GL_RGBA8UI,
			RenderBufferType_RGBA16UI = GL_RGBA16UI,
			RenderBufferType_RGBA32UI = GL_RGBA32UI,
			RenderBufferType_RGBA16F = GL_RGBA16F,
			RenderBufferType_RGBA32F = GL_RGBA32F,

			RenderBufferType_D16 = GL_DEPTH_COMPONENT16,
			RenderBufferType_D24 = GL_DEPTH_COMPONENT24,
			RenderBufferType_D32F = GL_DEPTH_COMPONENT32F,

			RenderBufferType_D24S8 = GL_DEPTH24_STENCIL8,
			RenderBufferType_D32FS8 = GL_DEPTH32F_STENCIL8
		};

		class RenderBuffer final
		{
		private:
			static const RenderBuffer *pRenderBuffer;

		private:
			uInt nRenderBuffer{0u};
			RenderBufferType eRenderBufferType;

		public:
			RenderBuffer(RenderBufferType eNewRenderBufferType);
			RenderBuffer(RenderBuffer &&sNewRenderBuffer);
			RenderBuffer(const RenderBuffer &sNewRenderBuffer) = delete;
			~RenderBuffer();

		public:
			inline operator uInt() const;

		public:
			RenderBuffer &operator=(RenderBuffer &&sNewRenderBuffer);
			RenderBuffer &operator=(const RenderBuffer &sNewRenderBuffer) = delete;

			Void initializeRenderBuffer();
			Void finalizeRenderBuffer();

			inline uInt renderbufferID() const;
			inline RenderBufferType renderbufferType() const;

			inline static Void activeRenderBuffer(const RenderBuffer &sNewRenderBuffer);
			inline static Void specifyRenderBuffer(uInt nNewWidth, uInt nNewHeight);
		};

		inline RenderBuffer::operator uInt() const
		{
			return this->nRenderBuffer;
		}

		inline uInt RenderBuffer::renderbufferID() const
		{
			return this->nRenderBuffer;
		}

		inline RenderBufferType RenderBuffer::renderbufferType() const
		{
			return this->eRenderBufferType;
		}

		inline Void RenderBuffer::activeRenderBuffer(const RenderBuffer &sNewRenderBuffer)
		{
			OpenGLExt::glBindRenderbuffer(GL_RENDERBUFFER, sNewRenderBuffer);

			RenderBuffer::pRenderBuffer = &sNewRenderBuffer;
		}

		inline Void RenderBuffer::specifyRenderBuffer(uInt nNewWidth, uInt nNewHeight)
		{
			if(RenderBuffer::pRenderBuffer)
				OpenGLExt::glRenderbufferStorage(GL_RENDERBUFFER, RenderBuffer::pRenderBuffer->eRenderBufferType, nNewWidth, nNewHeight);
		}
	}
}

#endif