#include "CheckpointGUI.h"
#include "imgui.h"
#include <string>

CheckpointGUI::CheckpointGUI()
{
	kaoProcess = new KaoProcess();
}

void CheckpointGUI::RenderCheckpointGUI()
{
	if (kaoProcess)
	{
		ImGui::Begin("Checkpoints");
		if (ImGui::Button("Fetch position"))
		{
			checkpoints.push_back(kaoProcess->ReadPosition());
		}

		if (ImGui::Button("Load cheackpoint"))
		{
			if (!checkpoints.empty())
			{
				kaoProcess->WritePosition(checkpoints.back());
			}
		}

		RenderCheckpointList();
		ImGui::End();
	}
}

void CheckpointGUI::RenderCheckpointList()
{
	ImGui::Text("Checkpoint List");
	ImGui::BeginChild("Checkpoint List", ImVec2(125, 125 * checkpoints.size()), true, ImGuiWindowFlags_NoScrollbar);
	{
		for (int i = 0; i < checkpoints.size(); i++)
		{
			std::string childID = "Checkpoint " + std::to_string(i);

			ImGui::Text(childID.c_str());
			ImGui::BeginChild(childID.c_str(), ImVec2(100, 100), true, ImGuiWindowFlags_NoScrollbar);
			{
				ImGui::Text("X: %f", checkpoints[i].x);
				ImGui::Text("Y: %f", checkpoints[i].y);
				ImGui::Text("Z: %f", checkpoints[i].z);
			}
			ImGui::EndChild();
		}
	}
	ImGui::EndChild();
}
