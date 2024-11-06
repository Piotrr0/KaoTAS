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