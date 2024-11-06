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
	ducatsAddress = ModuleBaseAddress + Offset::ducats;
	crystalsAddress = ModuleBaseAddress + Offset::crystals;
	starsAddress = ModuleBaseAddress + Offset::stars;
}