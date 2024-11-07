#include "KaoProcess.h"
#include <iostream>
#include "Offsets.h"

KaoProcess::KaoProcess()
{
	mem = new Memory({ processName });
	if (mem == nullptr)
	{
		std::cerr << "mem is nullptr.\n";
		return;
	}

	ModuleBaseAddress = mem->GetModuleAddress(processName);
	if (ModuleBaseAddress == 0)
	{
		std::cerr << "Failed to get module base address.\n";
		return;
	}
	ReadGameAddresses();
}

void KaoProcess::ReadGameAddresses()
{
	kao2GameletAddress = mem->Read<int>(ModuleBaseAddress + Offset::kao2Gamelet);
	localPlayerAddress = mem->Read<int>(kao2GameletAddress + Offset::localPlayer);

	positionAddress = Vector3<uintptr_t>
		(
			(localPlayerAddress + Offset::X),
			(localPlayerAddress + Offset::Y),
			(localPlayerAddress + Offset::Z)
		);

	ducatsAddress = ModuleBaseAddress + Offset::ducats;
	crystalsAddress = ModuleBaseAddress + Offset::crystals;
	starsAddress = ModuleBaseAddress + Offset::stars;
}

void KaoProcess::WritePosition(Vector3<float> position)
{
	WriteToKaoMemory<float>(GetPositionAddress().x, position.x);
	WriteToKaoMemory<float>(GetPositionAddress().y, position.y);
	WriteToKaoMemory<float>(GetPositionAddress().z, position.z);
}

Vector3<float> KaoProcess::ReadPosition()
{
	Vector3<float> position;
	position = Vector3<float>
	(
		ReadFromKaoMemory<float>(GetPositionAddress().x),
		ReadFromKaoMemory<float>(GetPositionAddress().y),
		ReadFromKaoMemory<float>(GetPositionAddress().z)
	);

	return position;
}
