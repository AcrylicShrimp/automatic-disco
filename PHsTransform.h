
/*
	2016.04.24
	Created by PHJ.
*/

#ifndef _PHS_TRANSFORM_H

#define _PHS_TRANSFORM_H

#include "PHsCommon.h"
#include "PHsMatrix4D.h"
#include "PHsVector4D.h"

#include <utility>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTransformation
	{
		class Transform
		{
		public:
			using Space = enum __Transform_Space
			{
				Local,
				World
			};

		private:
			Matrix4D sTransform;
			Matrix4D sInverseTransform;

		public:
			Transform();
			Transform(Transform &&sNewTransform);
			Transform(const Transform &sNewTransform);
			~Transform() = default;

		public:
			Transform &operator=(Transform &&sNewTransform);
			Transform &operator=(const Transform &sNewTransform);

			Void rotateOrientation(Float nAngle, Vector4D &&sAngleAxis);
			Void rotateOrientation(Float nAngle, const Vector4D &sAngleAxis);
			Void rotateOrientationX(Float nAngleX, Space eRelativeSpace = Space::Local);
			Void rotateOrientationY(Float nAngleY, Space eRelativeSpace = Space::Local);
			Void rotateOrientationZ(Float nAngleZ, Space eRelativeSpace = Space::Local);

			Void setPosition(Float nNewWorldX, Float nNewWorldY, Float nNewWorldZ);
			Void movePosition(Float nDistanceX, Float nDistanceY, Float nDistanceZ, Space eRelativeSpace = Space::Local);

			Vector4D getForward() const;
			Vector4D getBackward() const;
			Vector4D getRightward() const;
			Vector4D getLeftward() const;
			Vector4D getUpward() const;
			Vector4D getDownward() const;
			Vector4D getWorldAxisX() const;
			Vector4D getWorldAxisY() const;
			Vector4D getWorldAxisZ() const;
			Vector4D getWorldPosition() const;

			inline const Matrix4D &transformMatrix() const;
			inline const Matrix4D &transformInverseMatrix() const;
		};

		inline const Matrix4D &Transform::transformMatrix() const
		{
			return this->sTransform;
		}

		inline const Matrix4D &Transform::transformInverseMatrix() const
		{
			return this->sInverseTransform;
		}
	}
}

#endif