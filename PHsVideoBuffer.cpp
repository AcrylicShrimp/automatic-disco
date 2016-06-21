
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_VIDEO_BUFFER_CPP

#define _PHS_VIDEO_BUFFER_CPP

#include "PHsVideoBuffer.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		const VideoBuffer *VideoBuffer::pVideoBuffer{nullptr};

		VideoBuffer::VideoBuffer(VideoBufferType eNewVideoBufferType) :
			eVideoBufferType{eNewVideoBufferType}
		{
			//Empty.
		}

		VideoBuffer::VideoBuffer(VideoBuffer &&sNewVideoBuffer) :
			nVideoBuffer{sNewVideoBuffer.nVideoBuffer},
			eVideoBufferType{sNewVideoBuffer.eVideoBufferType}
		{
			sNewVideoBuffer.nVideoBuffer = 0u;

			if(VideoBuffer::pVideoBuffer == &sNewVideoBuffer)
				VideoBuffer::pVideoBuffer = this;
		}

		VideoBuffer::~VideoBuffer()
		{
			this->finalizeVideoBuffer();
		}

		VideoBuffer &VideoBuffer::operator=(VideoBuffer &&sNewVideoBuffer)
		{
			OpenGLExt::glDeleteBuffers(1u, &this->nVideoBuffer);
			
			this->nVideoBuffer = sNewVideoBuffer.nVideoBuffer;
			this->eVideoBufferType = sNewVideoBuffer.eVideoBufferType;

			sNewVideoBuffer.nVideoBuffer = 0u;

			if(VideoBuffer::pVideoBuffer == &sNewVideoBuffer)
				VideoBuffer::pVideoBuffer = this;

			return *this;
		}

		Void VideoBuffer::initializeVideoBuffer()
		{
			OpenGLExt::glGenBuffers(1u, &this->nVideoBuffer);
		}

		Void VideoBuffer::finalizeVideoBuffer()
		{
			if(this->nVideoBuffer)
				OpenGLExt::glDeleteBuffers(1u, &this->nVideoBuffer), this->nVideoBuffer = 0u;

			if(VideoBuffer::pVideoBuffer == this)
				VideoBuffer::pVideoBuffer = nullptr;
		}
	}
}

#endif