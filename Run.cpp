
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _RUN_CPP

#define _RUN_CPP

/*
	TODO : Place your code here
*/

#include "PHsCommon.h"
#include "PHsEntry.h"
#include "PHsFrameManager.h"
#include "PHsInputManager.h"
#include "PHsTextureManager.h"

#include <Windows.h>

using namespace PHs;

Int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, Int nShowCmd)
{
	/*
		Initialization
	*/
	FrameManager::initializeManager();
	InputManager::initializeManager();
	TextureManager::initializeManager();

	Entry *pEntry = Entry::pEntry;

	if(pEntry)
		pEntry->entryInitialize();

	/*
		Looping
	*/
	MSG sMsg;

	while(Entry::entryRunning())
	{
		if(PeekMessage(&sMsg, nullptr, 0u, 0u, PM_REMOVE))
		{
			if(sMsg.message == WM_QUIT)
				Entry::stopEntry();
			else
			{
				TranslateMessage(&sMsg);
				DispatchMessage(&sMsg);
			}
		}
		else
		{
			//Update input
			InputManager::getManager().updateInput();

			pEntry->entryFrame();
		}
	}

	/*
		Finalization
	*/
	if(pEntry)
		pEntry->entryFinalize();

	TextureManager::finalizeManager();
	InputManager::finalizeManager();
	FrameManager::finalizeManager();

	return 0;
}

#endif