#include "KaoProcess.h"
#include <iostream>
#include "Addresses.h"

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
	localPlayerAddress = mem->Read<std::uintptr_t>(ModuleBaseAddress + Address::localPlayer);
}

bool KaoProcess::WriteDucats(int amount)
{
	if (localPlayerAddress != 0)
	{
		const auto coinAddress = localPlayerAddress + Address::ducatsOffset;
		if (mem->Write<int>(coinAddress, amount))
		{
			std::cout << "Successfully wrote " << amount << " coins to memory.\n";
			return true;
		}
	}
	return false;
}

int KaoProcess::ReadDucats()
{
	if (localPlayerAddress != 0)
	{
		const auto ducatsAddress = localPlayerAddress + Address::ducatsOffset;
		int ducats = mem->Read<int>(ducatsAddress);
		return ducats;
	}
}