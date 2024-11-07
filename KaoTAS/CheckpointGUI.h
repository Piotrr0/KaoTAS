#ifndef CHECKPOINTGUI_H
#define CHECKPOINTGUI_H

#include "Vector3.h"
#include <stdlib.h>
#include <vector>

#include "KaoProcess.h"

class CheckpointGUI
{
public:
	CheckpointGUI();
	void RenderCheckpointGUI();

private:

	void RenderCheckpointList();

private:

	KaoProcess* kaoProcess = nullptr;
	std::vector<Vector3<float>> checkpoints;



public:

};
#endif // !CHECKPOINTGUI

