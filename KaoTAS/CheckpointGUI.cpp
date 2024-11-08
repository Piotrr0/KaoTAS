#include "CheckpointGUI.h"
#include "imgui.h"
#include <string>
#include "KeyBinds.h"

void CheckpointGUI::RenderGUI()
{
	ImGui::Begin("Checkpoints");
	if (ImGui::Button("Fetch position"))
	{
		FetchCheckpoint();
	}

	if (ImGui::Button("Load checkpoint"))
	{
		LoadCheckpoint();
	}

	CheckpointKeyBinds();
	RenderCheckpointList();
	ImGui::End();
}

void CheckpointGUI::CheckpointKeyBinds()
{
	if (ImGui::IsKeyPressed(KeyBinds::AddCheckpoint))
	{
		FetchCheckpoint();
	}
	if (ImGui::IsKeyPressed(KeyBinds::LoadLastCheckpoint))
	{
		LoadCheckpoint();
	}
}

void CheckpointGUI::LoadCheckpoint()
{
	if (!checkpoints.empty())
	{
		checkpoints.back().LoadPosition();
	}
}

void CheckpointGUI::FetchCheckpoint()
{
	if (process)
	{
		Checkpoint checkpoint(process->GetPositionAddress());
		checkpoints.push_back(checkpoint);
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
				ImGui::Text("X: %f", checkpoints[i].savedPosition.x);
				ImGui::Text("Y: %f", checkpoints[i].savedPosition.y);
				ImGui::Text("Z: %f", checkpoints[i].savedPosition.z);
			}
			ImGui::EndChild();
		}
	}
	ImGui::EndChild();
}