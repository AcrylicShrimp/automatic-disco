
/*
	2016.04.23
	Created by PHJ.
*/

#ifndef _PHS_INPUT_MANAGER_H

#define _PHS_INPUT_MANAGER_H

#include "PHsCommon.h"
#include "PHsManagerBase.h"

#include <functional>
#include <string>
#include <unordered_map>

#include <Windows.h>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsInput
	{
		class InputManager final : public ManagerBase <InputManager>
		{
		public:
			friend ManagerBase <InputManager>;

		private:
			std::unordered_map <std::wstring, std::function <Float()>> sInputMap;
			std::unordered_map <std::wstring, Float> sLastInput;

		private:
			InputManager() = default;
			InputManager(InputManager &&sNewInputManager) = delete;
			InputManager(const InputManager &sNewInputManager) = delete;
			~InputManager() = default;

		public:
			InputManager &operator=(InputManager &&sNewInputManager) = delete;
			InputManager &operator=(const InputManager &sNewInputManager) = delete;

			Void updateInput();
			Void unregiterInput(const std::wstring &sKeyName);
			Bool registerInput(const std::wstring &sKeyName, uInt nVitualKeycode);
			Bool registerInput(const std::wstring &sKeyName, std::function <Float()> fCustomInputFunction);
			Float getInput(const std::wstring &sKeyName, Float nErrorValue = 0.0f) const;
		};
	}
}

#endif