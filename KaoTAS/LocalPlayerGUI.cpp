#include "LocalPlayerGUI.h"
#include "imgui.h"
#include "KaoProcess.h"

void LocalPlayerGUI::RenderGUI()
{
	ImGui::Begin(name);

	RenderPositionSection();
	RenderResourcesSection();

	ImGui::End();
}

void LocalPlayerGUI::RenderPositionSection()
{
	ImGui::BeginChild("Position", ImVec2(200, 200), true, ImGuiWindowFlags_NoScrollbar);
	{
		RenderInput<float>("X", &position.x, process->GetPositionAddress().x);
		RenderInput<float>("Y", &position.y, process->GetPositionAddress().y);
		RenderInput<float>("Z", &position.z, process->GetPositionAddress().z);
	}
	ImGui::EndChild();
}

void LocalPlayerGUI::RenderResourcesSection()
{
	ImGui::BeginChild("Resources", ImVec2(200, 80), true, ImGuiWindowFlags_NoScrollbar);
	{
        RenderInput<int>("Ducats", &ducats, process->GetDucatsAddress());
        RenderInput<int>("Crystal", &crystals, process->GetCrystalsAddress());
        RenderInput<int>("Stars", &stars, process->GetStarsAddress());
	}
	ImGui::EndChild();
}

template <typename T>
void LocalPlayerGUI::RenderInput(const char* label, T* value, Address<T> address)
{
    bool modified = false;
    if constexpr (std::is_same_v<T, int>)
    {
        modified = ImGui::InputInt(label, value);
    }
    else if constexpr (std::is_same_v<T, float>)
    {
        modified = ImGui::InputFloat(label, value);
    }

    if (process != nullptr)
    {
        if (modified)
        {
            address.WriteValue(*value);
        }
        else
        {
            *value = address.ReadValue();
        }
    }
}