#include "GUI.h"
#include "LocalPlayerGUI.h"
#include "imgui.h"

GUI::GUI()
{

}

void GUI::RenderUI()
{
	playerGUI->RenderGUI();
	checkpointGUI->RenderGUI();
}