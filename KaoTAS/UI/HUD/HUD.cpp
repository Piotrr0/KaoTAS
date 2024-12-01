#include "HUD.h"
#include <memory>

HUD::HUD()
{
    InitOverlay();
}

PlayerWidgetController* HUD::GetPlayerWidgetController(const GameMemoryAddresses& MemoryAddresses) 
{
    if (playerWidgetController == nullptr) 
    {
        playerWidgetController = std::make_unique<PlayerWidgetController>();
        playerWidgetController->SetWidgetControllerAddresses(MemoryAddresses);
    }
    return playerWidgetController.get();
}

void HUD::RenderOverlay() const
{
    playerWidget->DrawWidget();
}

void HUD::InitOverlay()
{
    if (playerWidget)
    {
        GameMemoryAddresses memoryAddress = kaoProcess->GetGameMemoryAddresses();
        playerWidget->SetWidgetController(GetPlayerWidgetController(memoryAddress));
    }
}