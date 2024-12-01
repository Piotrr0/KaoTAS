#ifndef WIDGETCONTROLLER_H
#define WIDGETCONTROLLER_H

#include "../../KaoProcess.h"


class WidgetController
{
public:
	void SetWidgetControllerAddresses(const GameMemoryAddresses& MemoryAddresses);

protected:

	GameMemoryAddresses MemoryAddresses;
};

#endif // !WIDGETCONTROLLER_H