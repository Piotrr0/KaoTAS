#include "PlayerWidget.h"
#include "imgui.h"

void PlayerWidget::DrawWidget()
{
	ImGui::Begin("test");

	RenderPositionSection();
	RenderResourcesSection();

	ImGui::End();
}

void PlayerWidget::OnWidgetControllerSet()
{

}

void PlayerWidget::RenderPositionSection()
{
	ImGui::BeginChild("Position", ImVec2(200, 200), true, ImGuiWindowFlags_NoScrollbar);
	{
	}
	ImGui::EndChild();
}

void PlayerWidget::RenderResourcesSection()
{
	ImGui::BeginChild("Resources", ImVec2(200, 80), true, ImGuiWindowFlags_NoScrollbar);
	{
	}
	ImGui::EndChild();
}
