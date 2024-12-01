#ifndef WIDGET_H
#define WIDGET_H

#include "../WidgetController/WidgetController.h"
#include "memory"


class Widget 
{
public:
	void SetWidgetController(WidgetController* inWidgetController);
	virtual void OnWidgetControllerSet() = 0;
	virtual void DrawWidget();

protected:

	std::unique_ptr<WidgetController> widgetController = nullptr;

};

#endif // !WIDGETH