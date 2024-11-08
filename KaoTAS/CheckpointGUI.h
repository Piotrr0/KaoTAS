#ifndef CHECKPOINTGUI_H
#define CHECKPOINTGUI_H

#include "Vector3.h"
#include "BaseGUI.h"
#include <stdlib.h>
#include <vector>

#include "KaoProcess.h"

struct Checkpoint 
{
    Vector3<Address<float>> positionAddress;
    Vector3<float> savedPosition;

    Checkpoint(Vector3<Address<float>> positionAddress) :
        positionAddress(positionAddress)
    {
        FetchPosition();
    }

    void FetchPosition() 
    {
        savedPosition.x = positionAddress.x.ReadValue();
        savedPosition.y = positionAddress.y.ReadValue();
        savedPosition.z = positionAddress.z.ReadValue();
    }

    void LoadPosition() 
    {
        positionAddress.x.WriteValue(savedPosition.x);
        positionAddress.y.WriteValue(savedPosition.y);
        positionAddress.z.WriteValue(savedPosition.z);
    }
};

class CheckpointGUI : public BaseGUI
{
public:
	CheckpointGUI() : BaseGUI("Checkpoints\0") {};
	void RenderGUI();

private:

	void CheckpointKeyBinds();
	void LoadCheckpoint();
	void FetchCheckpoint();

	void RenderCheckpointList();

private:

	std::unique_ptr<KaoProcess> process = std::make_unique<KaoProcess>();
    std::vector<Checkpoint> checkpoints;

public:

};
#endif // !CHECKPOINTGUI