#ifndef LOCALPLAYERGUI_H
#define LOCALPLAYERGUI_H

#include "KaoProcess.h"

class LocalPlayerGUI
{
public:
	LocalPlayerGUI();
	void RenderLocalPlayerGUI();

private:

	template <typename T>
	void RenderInput(const char* label, T* value, uintptr_t address);

private:

	KaoProcess* kaoProcess = nullptr;

	const char* name = "LocalPlayer";

	int ducats = 0;
	int crystals = 0;
	int stars = 0;

public:
};

#endif