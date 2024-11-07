#include "LocalPlayerGUI.h"
#include "imgui.h"
#include "KaoProcess.h"

LocalPlayerGUI::LocalPlayerGUI()
{
	kaoProcess = new KaoProcess();
}

void LocalPlayerGUI::RenderLocalPlayerGUI()
{
	if (kaoProcess)
	{
		ImGui::Begin(name);

		ImGui::Text("Position");
		ImGui::BeginChild("Position", ImVec2(200, 200), true, ImGuiWindowFlags_NoScrollbar);
		{
			RenderInput<float>("X", &positionX, kaoProcess->GetPositionAddress().x);
			RenderInput<float>("Y", &positionY, kaoProcess->GetPositionAddress().y);
			RenderInput<float>("Z", &positionZ, kaoProcess->GetPositionAddress().z);
		}
		ImGui::EndChild();

		// Resources Section
		ImGui::Text("Resources");
		ImGui::BeginChild("Resources", ImVec2(200, 80), true, ImGuiWindowFlags_NoScrollbar);
		{
			RenderInput<int>("Ducats", &ducats, kaoProcess->GetDucatsAddress());
			RenderInput<int>("Crystal", &crystals, kaoProcess->GetCrystalsAddress());
			RenderInput<int>("Stars", &stars, kaoProcess->GetStarsAddress());
		}
		ImGui::EndChild();

		ImGui::End();
	}
}

template <typename T>
void LocalPlayerGUI::RenderInput(const char* label, T* value, uintptr_t address)
{
	if (kaoProcess == nullptr) return;

	bool modified = false;
	if constexpr (std::is_same_v<T, int>)
	{
		modified = ImGui::InputInt(label, value);
	}
	else if constexpr (std::is_same_v<T, float>)
	{
		modified = ImGui::InputFloat(label, value);
	}

	if (modified)
	{
		kaoProcess->WriteToKaoMemory<T>(address, *value);
	}
	else
	{
		*value = kaoProcess->ReadFromKaoMemory<T>(address);
	}
}