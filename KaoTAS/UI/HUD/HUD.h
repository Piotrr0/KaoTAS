#ifndef HUD_H
#define HUD_H

#include <memory>
#include "../UI/Widget/PlayerWidget.h"
#include "../UI/WidgetController/PlayerWidgetController.h"
#include "../../KaoProcess.h"

class PlayerWidget;

class HUD
{
public:
	HUD();
	PlayerWidgetController* GetPlayerWidgetController(const GameMemoryAddresses& MemoryAddresses);

	void RenderOverlay() const;

protected:
	void InitOverlay();

private:
	std::unique_ptr<KaoProcess> kaoProcess = std::make_unique<KaoProcess>();
	std::unique_ptr<PlayerWidget> playerWidget = std::make_unique<PlayerWidget>();
	std::unique_ptr<PlayerWidgetController> playerWidgetController = nullptr;

};
#endif // !HUD_H