#include "GUI.h"
#include "LocalPlayerGUI.h"
#include "imgui.h"

GUI::GUI()
{
	playerGUI = new LocalPlayerGUI();
	checkpointGUI = new CheckpointGUI();
}

void GUI::RenderUI()
{
	playerGUI->RenderLocalPlayerGUI();
	checkpointGUI->RenderCheckpointGUI();
}
