
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_VIDEO_BUFFER_H

#define _PHS_VIDEO_BUFFER_H

#include "PHsCommon.h"
#include "PHsOpenGLExt.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using VideoBufferType = enum __PHs_Video_Buffer_Type : uInt
		{
			BufferType_Array = GL_ARRAY_BUFFER,
			BufferType_Element = GL_ELEMENT_ARRAY_BUFFER
		};

		using VideoBufferUsage = enum __PHs_Video_Buffer_Usage : uInt
		{
			BufferUsage_StaticDraw = GL_STATIC_DRAW,
			BufferUsage_StaticRead = GL_STATIC_READ,
			BufferUsage_StaticCopy = GL_STATIC_COPY,

			BufferUsage_DynamicDraw = GL_DYNAMIC_DRAW,
			BufferUsage_DynamicRead = GL_DYNAMIC_READ,
			BufferUsage_DynamicCopy = GL_DYNAMIC_COPY,

			BufferUsage_StreamDraw = GL_STREAM_DRAW,
			BufferUsage_StreamRead = GL_STREAM_READ,
			BufferUsage_StreamCopy = GL_STREAM_COPY
		};

		class VideoBuffer final
		{
		private:
			static const VideoBuffer *pVideoBuffer;

		private:
			uInt nVideoBuffer{0u};
			VideoBufferType eVideoBufferType;

		public:
			VideoBuffer(VideoBufferType eNewVideoBufferType);
			VideoBuffer(VideoBuffer &&sNewVideoBuffer);
			VideoBuffer(const VideoBuffer &sNewVideoBuffer) = delete;
			~VideoBuffer();

		public:
			inline operator uInt() const;

		public:
			VideoBuffer &operator=(VideoBuffer &&sNewVideoBuffer);
			VideoBuffer &operator=(const VideoBuffer &sNewVideoBuffer) = delete;

			Void initializeVideoBuffer();
			Void finalizeVideoBuffer();

			inline uInt videobufferID() const;
			inline VideoBufferType videobufferType() const;

		public:
			inline static Void activeVideoBuffer(const VideoBuffer &sNewVideoBuffer);
			inline static Void specifyVideoBuffer(VideoBufferUsage eNewVideoBufferUsage, uInt nNewVideoBufferSize, Void *pNewVideoBufferData = nullptr);
		};

		inline VideoBuffer::operator uInt() const
		{
			return this->nVideoBuffer;
		}

		inline uInt VideoBuffer::videobufferID() const
		{
			return this->nVideoBuffer;
		}

		inline VideoBufferType VideoBuffer::videobufferType() const
		{
			return this->eVideoBufferType;
		}

		inline Void VideoBuffer::activeVideoBuffer(const VideoBuffer &sNewVideoBuffer)
		{
			OpenGLExt::glBindBuffer(sNewVideoBuffer.eVideoBufferType, sNewVideoBuffer);

			VideoBuffer::pVideoBuffer = &sNewVideoBuffer;
		}

		inline Void VideoBuffer::specifyVideoBuffer(VideoBufferUsage eNewVideoBufferUsage, uInt nNewVideoBufferSize, Void *pNewVideoBufferData)
		{
			if(VideoBuffer::pVideoBuffer)
				OpenGLExt::glBufferData(VideoBuffer::pVideoBuffer->eVideoBufferType, nNewVideoBufferSize, pNewVideoBufferData, eNewVideoBufferUsage);
		}
	}
}

#endif