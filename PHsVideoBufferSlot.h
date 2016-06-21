
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_VIDEO_BUFFER_SLOT_H

#define _PHS_VIDEO_BUFFER_SLOT_H

#include "PHsCommon.h"
#include "PHsVideoBuffer.h"
#include "PHsOpenGLExt.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using VideoBufferSlotType = enum __PHs_Video_Buffer_Slot_Type : uInt
		{
			BufferSlotType_Vector1 = 1u,
			BufferSlotType_Vector2,
			BufferSlotType_Vector3,
			BufferSlotType_Vector4,
			BufferSlotType_Matrix22,
			BufferSlotType_Matrix33,
			BufferSlotType_Matrix44,
		};

		using VideoBufferSlotLife = enum __PHs_Video_Buffer_Slot_Life : uInt
		{
			SlotLife_Per_Vertex,
			SlotLife_Per_Instance1,
			SlotLife_Per_Instance2,
			SlotLife_Per_Instance3,
			SlotLife_Per_Instance4,
			SlotLife_Per_Instance5,
			SlotLife_Per_Instance6,
			SlotLife_Per_Instance7,
			SlotLife_Per_Instance8,
			SlotLife_Per_Instance9,
			SlotLife_Per_Instance10,
			SlotLife_Per_Instance11,
			SlotLife_Per_Instance12,
			SlotLife_Per_Instance13,
			SlotLife_Per_Instance14,
			SlotLife_Per_Instance15,
			SlotLife_Per_Instance16
		};

		using VideoBufferSlotElementType = enum __PHs_Video_Buffer_Slot_Element_Type : uInt
		{
			ElementType_Byte = GL_BYTE,
			ElementType_uByte = GL_UNSIGNED_BYTE,
			ElementType_Short = GL_SHORT,
			ElementType_uShort = GL_UNSIGNED_SHORT,
			ElementType_Int = GL_INT,
			ElementType_uInt = GL_UNSIGNED_INT,
			ElementType_Float = GL_FLOAT,
			ElementType_Float_Half = GL_HALF_FLOAT,
			ElementType_Float_Fixed = GL_FIXED,
			ElementType_Double = GL_DOUBLE,
			ElementType_Int_2_10_10_10 = GL_INT_2_10_10_10_REV,
			ElementType_uInt_2_10_10_10 = GL_UNSIGNED_INT_2_10_10_10_REV,
			ElementType_uInt_10F_11F_11F = GL_UNSIGNED_INT_10F_11F_11F_REV
		};

		class VideoBufferSlot final
		{
		private:
			static const VideoBufferSlot *pVideoBufferSlot;

		private:
			uInt nVideoBufferSlot{0u};

		public:
			VideoBufferSlot() = default;
			VideoBufferSlot(VideoBufferSlot &&sNewVideoBufferSlot);
			VideoBufferSlot(const VideoBufferSlot &sNewVideoBufferSlot) = delete;
			~VideoBufferSlot();

		public:
			inline operator uInt() const;

		public:
			VideoBufferSlot &operator=(VideoBufferSlot &&sNewVideoBufferSlot);
			VideoBufferSlot &operator=(const VideoBufferSlot &sNewVideoBufferSlot) = delete;

			Void initializeVideoBufferSlot();
			Void finalizeVideoBufferSlot();

			inline uInt videobufferslotID() const;

		public:
			static Void activeVideoBufferSlot(const VideoBufferSlot &sNewVideoBufferSlot);
			static Void enableVideoBufferSlot(uInt nNewSlotIndex);
			static Void disableVideoBufferSlot(uInt nNewSlotIndex);
			static Void specifyVideoBufferSlot(
				uInt nNewVideoBufferSlotIndex,
				VideoBufferSlotType eNewVideoBufferSlotType,
				VideoBufferSlotLife eNewVideoBufferSlotLife,
				VideoBufferSlotElementType eNewVideoBufferSlotElementType = VideoBufferSlotElementType::ElementType_Float,
				uInt nNewSlotElementSize = sizeof(Float),
				uInt nNewOffset = 0u,
				uInt nNewStride = 0u,
				Bool bNewNormalize = false);
		};

		inline VideoBufferSlot::operator uInt() const
		{
			return this->nVideoBufferSlot;
		}

		inline uInt VideoBufferSlot::videobufferslotID() const
		{
			return this->nVideoBufferSlot;
		}
	}
}

#endif