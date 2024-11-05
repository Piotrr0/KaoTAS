#ifndef LOCALPLAYERGUI_H
#define LOCALPLAYERGUI_H

#include "KaoProcess.h"

class LocalPlayerGUI
{
public:
	LocalPlayerGUI();
	void RenderLocalPlayerGUI();
private:

private:

	KaoProcess* kaoProcess = nullptr;

	const char* name = "LocalPlayer";
	int* ducats = nullptr;

public:
};

#endif