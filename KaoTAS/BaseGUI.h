#ifndef BASE_GUI_H
#define BASE_GUI_H

class BaseGUI
{
public:
	BaseGUI(const char* name);
	virtual ~BaseGUI() = default;

	virtual void RenderGUI() = 0;

protected:
	const char* name;

};
#endif // !BASE_GUI

