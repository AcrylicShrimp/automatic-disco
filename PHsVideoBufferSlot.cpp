
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_VIDEO_BUFFER_SLOT_CPP

#define _PHS_VIDEO_BUFFER_SLOT_CPP

#include "PHsVideoBufferSlot.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		const VideoBufferSlot *VideoBufferSlot::pVideoBufferSlot = nullptr;

		VideoBufferSlot::VideoBufferSlot(VideoBufferSlot &&sNewVideoBufferSlot) :
			nVideoBufferSlot{sNewVideoBufferSlot.nVideoBufferSlot}
		{
			sNewVideoBufferSlot.nVideoBufferSlot = 0u;

			if(VideoBufferSlot::pVideoBufferSlot == &sNewVideoBufferSlot)
				VideoBufferSlot::pVideoBufferSlot = this;
		}

		VideoBufferSlot::~VideoBufferSlot()
		{
			this->finalizeVideoBufferSlot();
		}

		VideoBufferSlot &VideoBufferSlot::operator=(VideoBufferSlot &&sNewVideoBufferSlot)
		{
			OpenGLExt::glDeleteVertexArrays(1u, &this->nVideoBufferSlot);

			this->nVideoBufferSlot = sNewVideoBufferSlot.nVideoBufferSlot;

			sNewVideoBufferSlot.nVideoBufferSlot = 0u;

			if(VideoBufferSlot::pVideoBufferSlot == &sNewVideoBufferSlot)
				VideoBufferSlot::pVideoBufferSlot = this;

			return *this;
		}

		Void VideoBufferSlot::initializeVideoBufferSlot()
		{
			OpenGLExt::glGenVertexArrays(1u, &this->nVideoBufferSlot);
		}

		Void VideoBufferSlot::finalizeVideoBufferSlot()
		{
			if(this->nVideoBufferSlot)
				OpenGLExt::glDeleteVertexArrays(1u, &this->nVideoBufferSlot), this->nVideoBufferSlot = 0u;

			if(VideoBufferSlot::pVideoBufferSlot == this)
				VideoBufferSlot::pVideoBufferSlot = nullptr;
		}

		Void VideoBufferSlot::activeVideoBufferSlot(const VideoBufferSlot &sNewVideoBufferSlot)
		{
			OpenGLExt::glBindVertexArray(sNewVideoBufferSlot);

			VideoBufferSlot::pVideoBufferSlot = &sNewVideoBufferSlot;
		}

		Void VideoBufferSlot::enableVideoBufferSlot(uInt nNewSlotIndex)
		{
			OpenGLExt::glEnableVertexAttribArray(nNewSlotIndex);
		}

		Void VideoBufferSlot::disableVideoBufferSlot(uInt nNewSlotIndex)
		{
			OpenGLExt::glDisableVertexAttribArray(nNewSlotIndex);
		}

		Void VideoBufferSlot::specifyVideoBufferSlot(
			uInt nNewVideoBufferSlotIndex,
			VideoBufferSlotType eNewVideoBufferSlotType,
			VideoBufferSlotLife eNewVideoBufferSlotLife,
			VideoBufferSlotElementType eNewVideoBufferSlotElementType,
			uInt nNewSlotElementSize,
			uInt nNewOffset,
			uInt nNewStride,
			Bool bNewNormalize)
		{
			switch(eNewVideoBufferSlotType)
			{
			case VideoBufferSlotType::BufferSlotType_Vector1:
			case VideoBufferSlotType::BufferSlotType_Vector2:
			case VideoBufferSlotType::BufferSlotType_Vector3:
			case VideoBufferSlotType::BufferSlotType_Vector4:
			{
				OpenGLExt::glVertexAttribPointer(
					nNewVideoBufferSlotIndex,
					eNewVideoBufferSlotType,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);
			}
			return;
			case VideoBufferSlotType::BufferSlotType_Matrix22:
			{
				nNewStride = nNewStride ? nNewStride : nNewSlotElementSize * 4u;

				OpenGLExt::glVertexAttribPointer(
					nNewVideoBufferSlotIndex,
					2u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 0u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);

				OpenGLExt::glVertexAttribPointer(
					++nNewVideoBufferSlotIndex,
					2u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 2u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);
			}
			return;
			case VideoBufferSlotType::BufferSlotType_Matrix33:
			{
				nNewStride = nNewStride ? nNewStride : nNewSlotElementSize * 9u;

				OpenGLExt::glVertexAttribPointer(
					nNewVideoBufferSlotIndex,
					3u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 0u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);

				OpenGLExt::glVertexAttribPointer(
					++nNewVideoBufferSlotIndex,
					3u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 3u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);

				OpenGLExt::glVertexAttribPointer(
					++nNewVideoBufferSlotIndex,
					3u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 6u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);
			}
			return;
			case VideoBufferSlotType::BufferSlotType_Matrix44:
			{
				nNewStride = nNewStride ? nNewStride : nNewSlotElementSize * 16u;

				OpenGLExt::glVertexAttribPointer(
					nNewVideoBufferSlotIndex,
					4u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 0u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);

				OpenGLExt::glVertexAttribPointer(
					++nNewVideoBufferSlotIndex,
					4u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 4u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);

				OpenGLExt::glVertexAttribPointer(
					++nNewVideoBufferSlotIndex,
					4u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 8u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);

				OpenGLExt::glVertexAttribPointer(
					++nNewVideoBufferSlotIndex,
					4u,
					eNewVideoBufferSlotElementType,
					bNewNormalize,
					nNewStride,
					reinterpret_cast <Void *>(nNewOffset + nNewSlotElementSize * 12u));

				OpenGLExt::glVertexAttribDivisor(nNewVideoBufferSlotIndex, eNewVideoBufferSlotLife);
			}
			default:
			return;
			}
		}
	}
}

#endif