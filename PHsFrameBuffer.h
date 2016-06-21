
/*
	2016.02.03
	Created by PHJ.
*/

#ifndef _PHS_FRAME_BUFFER_H

#define _PHS_FRAME_BUFFER_H

#include "PHsCommon.h"
#include "PHsOpenGLExt.h"
#include "PHsRenderBuffer.h"
#include "PHsTexture.h"
#include "PHsTexture2D.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		class FrameBuffer final
		{
		private:
			uInt nFrameBuffer{0u};

		public:
			FrameBuffer() = default;
			FrameBuffer(FrameBuffer &&sNewFrameBuffer);
			FrameBuffer(const FrameBuffer &sNewFrameBuffer) = delete;
			~FrameBuffer();

		public:
			inline operator uInt() const;

		public:
			Void initializeFrameBuffer();
			Void finalizeFrameBuffer();

			inline uInt framebufferID() const;

			inline static Void activeFrameBuffer();
			inline static Void activeFrameBuffer(const FrameBuffer &sNewFrameBuffer);

		};

		inline FrameBuffer::operator uInt() const
		{
			return this->nFrameBuffer;
		}

		inline uInt FrameBuffer::framebufferID() const
		{
			return this->nFrameBuffer;
		}

		inline Void FrameBuffer::activeFrameBuffer()
		{
			OpenGLExt::glBindFramebuffer(GL_FRAMEBUFFER, 0u);
		}

		inline Void FrameBuffer::activeFrameBuffer(const FrameBuffer &sNewFrameBuffer)
		{
			OpenGLExt::glBindFramebuffer(GL_FRAMEBUFFER, sNewFrameBuffer);
		}


	}
}

#endif