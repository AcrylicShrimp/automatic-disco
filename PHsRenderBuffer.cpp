
/*
	2016.02.03
	Created by PHJ.
*/

#ifndef _PHS_RENDER_BUFFER_CPP

#define _PHS_RENDER_BUFFER_CPP

#include "PHsRenderBuffer.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		const RenderBuffer *RenderBuffer::pRenderBuffer{nullptr};

		RenderBuffer::RenderBuffer(RenderBufferType eNewRenderBufferType) :
			eRenderBufferType{eNewRenderBufferType}
		{
			//Empty.
		}

		RenderBuffer::RenderBuffer(RenderBuffer &&sNewRenderBuffer) :
			nRenderBuffer{sNewRenderBuffer.nRenderBuffer},
			eRenderBufferType{sNewRenderBuffer.eRenderBufferType}
		{
			sNewRenderBuffer.nRenderBuffer = 0u;

			if(RenderBuffer::pRenderBuffer == &sNewRenderBuffer)
				RenderBuffer::pRenderBuffer = this;
		}

		RenderBuffer::~RenderBuffer()
		{
			this->finalizeRenderBuffer();
		}

		RenderBuffer &RenderBuffer::operator=(RenderBuffer &&sNewRenderBuffer)
		{
			if(this->nRenderBuffer)
				OpenGLExt::glDeleteRenderbuffers(1u, &this->nRenderBuffer);

			this->nRenderBuffer = sNewRenderBuffer.nRenderBuffer;
			this->eRenderBufferType = sNewRenderBuffer.eRenderBufferType;

			sNewRenderBuffer.nRenderBuffer = 0u;

			if(RenderBuffer::pRenderBuffer == &sNewRenderBuffer)
				RenderBuffer::pRenderBuffer = this;

			return *this;
		}

		Void RenderBuffer::initializeRenderBuffer()
		{
			OpenGLExt::glGenRenderbuffers(1u, &this->nRenderBuffer);
		}

		Void RenderBuffer::finalizeRenderBuffer()
		{
			if(this->nRenderBuffer)
				OpenGLExt::glDeleteRenderbuffers(1u, &this->nRenderBuffer), this->nRenderBuffer = 0u;

			if(RenderBuffer::pRenderBuffer == this)
				RenderBuffer::pRenderBuffer = nullptr;
		}
	}
}

#endif