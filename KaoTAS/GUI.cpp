#include "GUI.h"
#include "LocalPlayerGUI.h"
#include "imgui.h"

GUI::GUI()
{
	playerGUI = new LocalPlayerGUI();
}

void GUI::RenderUI()
{
	playerGUI->RenderLocalPlayerGUI();
}
