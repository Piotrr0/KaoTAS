#include "LocalPlayerGUI.h"
#include "imgui.h"
#include "KaoProcess.h"

LocalPlayerGUI::LocalPlayerGUI()
{
	kaoProcess = new KaoProcess();
	ducats = new int{};
}

void LocalPlayerGUI::RenderLocalPlayerGUI()
{
	if (kaoProcess)
	{
		ImGui::Begin(name);
		if (ImGui::InputInt("Ducats", ducats))
		{
			kaoProcess->WriteDucats(*ducats);
		}
		else
		{
			*ducats = kaoProcess->ReadDucats();
		}

		ImGui::Text("Crystal");
		ImGui::Text("Star");

		ImGui::End();
	}
}