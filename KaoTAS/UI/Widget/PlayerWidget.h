#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include "Widget.h"

class PlayerWidget : public Widget
{
public:
	virtual void DrawWidget() override;
	virtual void OnWidgetControllerSet() override;

private:
	void RenderPositionSection();
	void RenderResourcesSection();

};
#endif // !PLAYERWIDGET_H

