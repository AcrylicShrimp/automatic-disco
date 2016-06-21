
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _CUSTOM_RUN_CPP

#define _CUSTOM_RUN_CPP

/*
	TODO : Place your code here
*/

#include "CustomRun.h"

namespace Custom
{
	using namespace std;

	CustomRun CustomRun::sCustomRun;

	Void CustomRun::createFrame()
	{
		FrameManager::getManager().createFrame(1024u, 768u, 32u, 32u, this->bFullscr, L"Custom test", L"Custom test");

		glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
		glClearDepth(1.0f);

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

		glDepthFunc(GL_LEQUAL);
		glFrontFace(GL_CCW);

		/*
			Load OpenGL resources.
		*/
		this->sMesh.loadMesh(L"C:/Users/Administrator/Desktop/Develop/Res/PHs/plane.pm");
		this->sMesh.initializeVideoBufferSlot(0u, maxValue <uInt>(), 1u, maxValue <uInt>());

		this->sShader.initializeShader();
		this->sShader.createShader(L"C:/Users/Administrator/Documents/Visual Studio 2015/Projects/PHs/PHs/model_view.vs", L"", L"C:/Users/Administrator/Documents/Visual Studio 2015/Projects/PHs/PHs/model_view.fs");

		Int vSampler[]
		{
			0u
		};

		Shader::activeShader(this->sShader);
		Shader::setUniformSampler("uniform_diffuse", 1u, vSampler);

		FrameManager::getManager().framemanagerFrame().setVisible(true);
	}

	Void CustomRun::destroyFrame()
	{
		/*
			Unload OpenGL resources.
		*/
		this->sShader.deleteShader();
		this->sShader.finalizeShader();

		this->sMesh.finalizeVideoBufferSlot();
		this->sMesh.unloadMesh();

		FrameManager::getManager().framemanagerFrame().setVisible(false);
		FrameManager::getManager().destroyFrame();
	}

	Void CustomRun::resetMousePosition()
	{
		RECT sRect;
		GetWindowRect(FrameManager::getManager().framemanagerFrame().frameWnd(), &sRect);
		SetCursorPos(this->nLastMousePosX = (sRect.left + sRect.right) / 2, this->nLastMousePosY = (sRect.bottom + sRect.top) / 2);
	}

	Void CustomRun::entryInitialize()
	{
		InputManager &sInputMgr = InputManager::getManager();

		sInputMgr.registerInput(L"Exit", VK_ESCAPE);
		sInputMgr.registerInput(L"Forward", 'W');
		sInputMgr.registerInput(L"Backward", 'S');
		sInputMgr.registerInput(L"Leftward", 'A');
		sInputMgr.registerInput(L"Rightward", 'D');
		sInputMgr.registerInput(L"Speedup", VK_SHIFT);
		sInputMgr.registerInput(L"Grab", VK_LBUTTON);
		sInputMgr.registerInput(L"Ungrab", VK_MENU);

		sInputMgr.registerInput(L"MouseX", [&]()
		{
			POINT sPoint;
			GetCursorPos(&sPoint);

			return static_cast <Float>(sPoint.x - this->nLastMousePosX);
		});
		sInputMgr.registerInput(L"MouseY", [&]()
		{
			POINT sPoint;
			GetCursorPos(&sPoint);

			return static_cast <Float>(sPoint.y - this->nLastMousePosY);
		});

		TextureManager &sTextureMgr = TextureManager::getManager();

		sTextureMgr.eMinTexelFilter = TexTexelFilter::Texel_Linear;
		sTextureMgr.eMinMipmapFilter = TexMipmapFilter::Mipmap_Linear;
		sTextureMgr.eMagTexelFilter = TexTexelFilter::Texel_Linear;
		sTextureMgr.eSWrappingMode = TexWrappingMode::Wrap_Repeat;
		sTextureMgr.eTWrappingMode = TexWrappingMode::Wrap_Repeat;
		sTextureMgr.nAnistropicMode = 16.0f;

		Event <FrameCloseEventArg>::registerEventHandler(this);
		Event <FrameSizeEventArg>::registerEventHandler(this);

		this->createFrame();
	}

	Void CustomRun::entryFinalize()
	{
		this->destroyFrame();

		Event <FrameCloseEventArg>::unregisterEventHandler(this);
		Event <FrameSizeEventArg>::unregisterEventHandler(this);
	}

	Void CustomRun::entryFrame()
	{
		InputManager &sInputMgr = InputManager::getManager();
		Float nElapsed = static_cast <Float>(static_cast <Double>(this->sTimeLine.timelineElapsed()) / 1000000000.0);

		if(sInputMgr.getInput(L"Exit"))
			Entry::stopEntry();

		{
			Vector4D sMoveVector;
			sMoveVector.zeroVector();

			if(sInputMgr.getInput(L"Forward") && !sInputMgr.getInput(L"Backward"))
				sMoveVector[2] = -1.0f;
			else if(sInputMgr.getInput(L"Backward") && !sInputMgr.getInput(L"Forward"))
				sMoveVector[2] = 1.0f;

			if(sInputMgr.getInput(L"Leftward") && !sInputMgr.getInput(L"Rightward"))
				sMoveVector[0] = -1.0f;
			else if(sInputMgr.getInput(L"Rightward") && !sInputMgr.getInput(L"Leftward"))
				sMoveVector[0] = 1.0f;

			sMoveVector.normalizeVector();

			if(sInputMgr.getInput(L"Speedup"))
				sMoveVector.multiplyVector(30.0f * nElapsed);
			else
				sMoveVector.multiplyVector(5.0f * nElapsed);

			this->sCamera.movePosition(sMoveVector[0], 0.0f, sMoveVector[2]);
		}

		{
			if(this->bMouseGrab)
			{
				if(sInputMgr.getInput(L"Ungrab"))
				{
					this->bMouseGrab = false;
					ShowCursor(true);
				}
				else
				{
					this->sCamera.rotateOrientationX(sInputMgr.getInput(L"MouseY") * nElapsed * -90.0_Deg * 0.15f, Transform::Space::Local);
					this->sCamera.rotateOrientationY(sInputMgr.getInput(L"MouseX") * nElapsed * -90.0_Deg * 0.15f, Transform::Space::World);
					
					this->resetMousePosition();
				}
			}
			else if(sInputMgr.getInput(L"Grab"))
			{
				this->bMouseGrab = true;
				ShowCursor(false);

				this->resetMousePosition();
			}
		}

		Shader::activeShader(this->sShader);
		Shader::setUniformMatrix44("uniform_view", 1u, this->sCamera.transformInverseMatrix());
		Shader::setUniformMatrix44("uniform_proj", 1u, this->sProjection);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			for(const SubMesh &sSubMesh : this->sMesh.meshSubMeshVector())
			{
				VideoBufferSlot::activeVideoBufferSlot(sSubMesh.sSubMeshVideoBufferSlot);

				if(sSubMesh.pSubMeshMaterialPointer && sSubMesh.pSubMeshMaterialPointer->pDiffuseTexture)
				{
					Texture::activeTextureSlot(0u);
					Texture2D::activeTexture(*sSubMesh.pSubMeshMaterialPointer->pDiffuseTexture);
				}

				VideoBuffer::activeVideoBuffer(sSubMesh.sSubMeshIndexBuffer);
				OpenGLExt::glDrawElementsInstanced(GL_TRIANGLES, sSubMesh.nSubMeshIndexCount, GL_UNSIGNED_INT, reinterpret_cast <Void *>(0u), 1u);
			}
		}
		SwapBuffers(FrameManager::getManager().framemanagerFrame().frameDC());
		OpenGLExt::wglSwapIntervalEXT(1);
	}

	Void CustomRun::onEvent(const FrameCloseEventArg &sEventArg)
	{
		Entry::stopEntry();
	}

	Void CustomRun::onEvent(const FrameSizeEventArg &sEventArg)
	{
		glViewport(0, 0, sEventArg.nFrameWidth, sEventArg.nFrameHeight);

		const Float nAspect = static_cast <Float>(sEventArg.nFrameWidth) / static_cast <Float>(sEventArg.nFrameHeight);
		this->sProjection.perspectiveMatrix(nAspect, 90.0_Deg, 1.0f, 100.0f);

		if(this->bMouseGrab)
			this->resetMousePosition();
	}
}

#endif