
/*
	2016.04.23
	Created by PHJ.
*/

#ifndef _PHS_INPUT_MANAGER_CPP

#define _PHS_INPUT_MANAGER_CPP

#include "PHsInputManager.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsInput
	{
		using namespace std;

		Void InputManager::updateInput()
		{
			for(auto &sPair : this->sInputMap)
				this->sLastInput[sPair.first] = sPair.second();
		}

		Void InputManager::unregiterInput(const std::wstring &sKeyName)
		{
			this->sInputMap.erase(sKeyName);
			this->sLastInput.erase(sKeyName);
		}

		Bool InputManager::registerInput(const std::wstring &sKeyName, uInt nVitualKeycode)
		{
			if(this->sInputMap.find(sKeyName) != this->sInputMap.end())
				return false;

			this->sInputMap.insert(
			{
				sKeyName,
				[nVitualKeycode]()
				{
					return GetAsyncKeyState(nVitualKeycode) & 0x8000 ? 1.0f : 0.0f;
				}
			});
			this->sLastInput[sKeyName] = 0.0f;
		}

		Bool InputManager::registerInput(const std::wstring &sKeyName, std::function <Float()> fCustomInputFunction)
		{
			if(this->sInputMap.find(sKeyName) != this->sInputMap.end())
				return false;

			this->sInputMap.insert(
			{
				sKeyName,
				fCustomInputFunction
			});
			this->sLastInput[sKeyName] = 0.0f;

			return true;
		}

		Float InputManager::getInput(const std::wstring &sKeyName, Float nErrorValue) const
		{
			auto iIndex = this->sLastInput.find(sKeyName);

			if(iIndex == this->sLastInput.end())
				return nErrorValue;

			return iIndex->second;
		}
	}
}

#endif