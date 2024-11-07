#ifndef MAINGUI_H
#define MAINGUI_H

#include "LocalPlayerGUI.h"
#include "CheckpointGUI.h"

class GUI
{
public:
	GUI();

	void RenderUI();

private:

private:

	LocalPlayerGUI* playerGUI = nullptr;
	CheckpointGUI* checkpointGUI = nullptr;

public:

};

#endif // !MAINGUI.H
