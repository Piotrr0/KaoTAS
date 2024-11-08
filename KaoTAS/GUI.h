#ifndef MAINGUI_H
#define MAINGUI_H

#include <memory>
#include "LocalPlayerGUI.h"
#include "CheckpointGUI.h"

class GUI
{
public:
	GUI();

	void RenderUI();

private:

private:

	std::unique_ptr<LocalPlayerGUI> playerGUI = std::make_unique<LocalPlayerGUI>();
	std::unique_ptr<CheckpointGUI> checkpointGUI = std::make_unique<CheckpointGUI>();
	
public:

};

#endif // !MAINGUI.H