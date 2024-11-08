#ifndef LOCALPLAYERGUI_H
#define LOCALPLAYERGUI_H

#include "KaoProcess.h"
#include "BaseGUI.h"
#include "Vector3.h"
#include "memory"

class LocalPlayerGUI : public BaseGUI
{
public:
    LocalPlayerGUI() : BaseGUI("LocalPlayer\0") {}
    void RenderGUI() override;

private:

    void RenderPositionSection();
    void RenderResourcesSection();

    template <typename T>
    void RenderInput(const char* label, T* value, Address<T> address);

private:
    
    std::unique_ptr<KaoProcess> process = std::make_unique<KaoProcess>();

    int ducats = 0;
    int crystals = 0;
    int stars = 0;

    Vector3<float> position{};    
};

#endif 