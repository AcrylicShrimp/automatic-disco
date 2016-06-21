
/*
	2016.04.24
	Created by PHJ.
*/

#ifndef _PHS_TRANSFORM_CPP

#define _PHS_TRANSFORM_CPP

#include "PHsTransform.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTransformation
	{
		using namespace std;

		Transform::Transform()
		{
			this->sTransform.identityMatrix();
			this->sInverseTransform.identityMatrix();
		}

		Transform::Transform(Transform &&sNewTransform) :
			sTransform(sNewTransform.sTransform),
			sInverseTransform(sNewTransform.sInverseTransform)
		{
			//Empty.
		}

		Transform::Transform(const Transform &sNewTransform) :
			sTransform(sNewTransform.sTransform),
			sInverseTransform(sNewTransform.sInverseTransform)
		{
			//Empty.
		}

		Transform &Transform::operator=(Transform &&sNewTransform)
		{
			this->sTransform = sNewTransform.sTransform;
			this->sInverseTransform = sNewTransform.sInverseTransform;

			return *this;
		}

		Transform &Transform::operator=(const Transform &sNewTransform)
		{
			this->sTransform = sNewTransform.sTransform;
			this->sInverseTransform = sNewTransform.sInverseTransform;

			return *this;
		}

		Void Transform::rotateOrientation(Float nAngle, Vector4D &&sAngleAxis)
		{
			Matrix4D sRotation;
			sRotation.rotateMatrix(nAngle, sAngleAxis);

			this->sTransform.multiplyMatrix(sRotation);
			sRotation.transposeMatrix(), this->sInverseTransform.multiplyMatrix(sRotation);
		}

		Void Transform::rotateOrientation(Float nAngle, const Vector4D &sAngleAxis)
		{
			Matrix4D sRotation;
			sRotation.rotateMatrix(nAngle, sAngleAxis);

			this->sTransform.multiplyMatrix(sRotation);
			sRotation.transposeMatrix(), this->sInverseTransform.multiplyMatrix(sRotation);
		}

		Void Transform::rotateOrientationX(Float nAngleX, Space eRelativeSpace)
		{
			Matrix4D sRotation;

			if(eRelativeSpace)
			{
				Vector4D sAxisX(
				{
					1.0f, 0.0f, 0.0f, 0.0f
				});

				sAxisX.multiplyMatrix(this->sInverseTransform);
				sAxisX.normalizeVector();
				sRotation.rotateMatrix(nAngleX, sAxisX);
			}
			else
				sRotation.rotateMatrixX(nAngleX);

			this->sTransform.multiplyMatrix(sRotation);
			sRotation.transposeMatrix(), this->sInverseTransform.multiplyMatrix(sRotation);
		}

		Void Transform::rotateOrientationY(Float nAngleY, Space eRelativeSpace)
		{
			Matrix4D sRotation;

			if(eRelativeSpace)
			{
				Vector4D sAxisY(
				{
					0.0f, 1.0f, 0.0f, 0.0f
				});

				sAxisY.multiplyMatrix(this->sInverseTransform);
				sAxisY.normalizeVector();
				sRotation.rotateMatrix(nAngleY, sAxisY);
			}
			else
				sRotation.rotateMatrixY(nAngleY);

			this->sTransform.multiplyMatrix(sRotation);
			sRotation.transposeMatrix(), this->sInverseTransform.multiplyMatrix(sRotation);
		}

		Void Transform::rotateOrientationZ(Float nAngleZ, Space eRelativeSpace)
		{
			Matrix4D sRotation;

			if(eRelativeSpace)
			{
				Vector4D sAxisZ(
				{
					0.0f, 0.0f, 1.0f, 0.0f
				});

				sAxisZ.multiplyMatrix(this->sInverseTransform);
				sAxisZ.normalizeVector();
				sRotation.rotateMatrix(nAngleZ, sAxisZ);
			}
			else
				sRotation.rotateMatrixZ(nAngleZ);

			this->sTransform.multiplyMatrix(sRotation);
			sRotation.transposeMatrix(), this->sInverseTransform.multiplyMatrix(sRotation);
		}

		Void Transform::setPosition(Float nNewWorldX, Float nNewWorldY, Float nNewWorldZ)
		{
			this->sTransform[12] = nNewWorldX;
			this->sTransform[13] = nNewWorldY;
			this->sTransform[14] = nNewWorldZ;

			this->sInverseTransform[12] = -nNewWorldX;
			this->sInverseTransform[13] = -nNewWorldY;
			this->sInverseTransform[14] = -nNewWorldZ;
		}

		Void Transform::movePosition(Float nDistanceX, Float nDistanceY, Float nDistanceZ, Space eRelativeSpace)
		{
			if(eRelativeSpace)
			{
				Vector4D sWorldAxisX = this->getWorldAxisX();
				Vector4D sWorldAxisY = this->getWorldAxisY();
				Vector4D sWorldAxisZ = this->getWorldAxisZ();

				sWorldAxisX.multiplyVector(nDistanceX);
				sWorldAxisY.multiplyVector(nDistanceY);
				sWorldAxisZ.multiplyVector(nDistanceZ);

				nDistanceX = sWorldAxisX[0] + sWorldAxisY[0] + sWorldAxisZ[0];
				nDistanceY = sWorldAxisX[1] + sWorldAxisY[1] + sWorldAxisZ[1];
				nDistanceZ = sWorldAxisX[2] + sWorldAxisY[2] + sWorldAxisZ[2];
			}

			Matrix4D sTranslation;
			Matrix4D sInverseTranslation;

			sTranslation.translateMatrix(nDistanceX, nDistanceY, nDistanceZ);
			sInverseTranslation.translateMatrix(-nDistanceX, -nDistanceY, -nDistanceZ);

			this->sTransform.multiplyMatrix(sTranslation);
			this->sInverseTransform.multiplyMatrix(sInverseTranslation);
		}

		Vector4D Transform::getForward() const
		{
			Vector4D sForward(
			{
				0.0f, 0.0f, 1.0f, 0.0f
			});

			sForward.multiplyMatrix(this->sTransform);
			return sForward;
		}

		Vector4D Transform::getBackward() const
		{
			Vector4D sBackward(
			{
				0.0f, 0.0f, -1.0f, 0.0f
			});

			sBackward.multiplyMatrix(this->sTransform);
			return sBackward;
		}

		Vector4D Transform::getRightward() const
		{
			Vector4D sRightward(
			{
				1.0f, 0.0f, 0.0f, 0.0f
			});

			sRightward.multiplyMatrix(this->sTransform);
			return sRightward;
		}

		Vector4D Transform::getLeftward() const
		{
			Vector4D sLeftward(
			{
				-1.0f, 0.0f, 0.0f, 0.0f
			});

			sLeftward.multiplyMatrix(this->sTransform);
			return sLeftward;
		}

		Vector4D Transform::getUpward() const
		{
			Vector4D sUpward(
			{
				0.0f, 1.0f, 0.0f, 0.0f
			});

			sUpward.multiplyMatrix(this->sTransform);
			return sUpward;
		}

		Vector4D Transform::getDownward() const
		{
			Vector4D sDownward(
			{
				0.0f, -1.0f, 0.0f, 0.0f
			});

			sDownward.multiplyMatrix(this->sTransform);
			return sDownward;
		}

		Vector4D Transform::getWorldAxisX() const
		{
			Vector4D sWorldAxisX(
			{
				1.0f, 0.0f, 0.0f, 0.0f
			});

			sWorldAxisX.multiplyMatrix(this->sInverseTransform);
			return sWorldAxisX;
		}

		Vector4D Transform::getWorldAxisY() const
		{
			Vector4D sWorldAxisY(
			{
				0.0f, 1.0f, 0.0f, 0.0f
			});

			sWorldAxisY.multiplyMatrix(this->sInverseTransform);
			return sWorldAxisY;
		}

		Vector4D Transform::getWorldAxisZ() const
		{
			Vector4D sWorldAxisZ(
			{
				0.0f, 0.0f, 1.0f, 0.0f
			});

			sWorldAxisZ.multiplyMatrix(this->sInverseTransform);
			return sWorldAxisZ;
		}

		Vector4D Transform::getWorldPosition() const
		{
			Vector4D sWorldPosition(
			{
				0.0f, 0.0f, 0.0f, 1.0f
			});

			sWorldPosition.multiplyMatrix(this->sTransform);
			return sWorldPosition;
		}
	}
}

#endif