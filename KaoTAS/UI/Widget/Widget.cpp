#include "Widget.h"
#include "../WidgetController/WidgetController.h"

void Widget::SetWidgetController(WidgetController* inWidgetController)
{
    widgetController.reset(inWidgetController);
    OnWidgetControllerSet();
}

void Widget::DrawWidget()
{
    if (widgetController == nullptr) return;
}