#include <iostream>
#include "Memory.h"
#include "Addresses.h"

using namespace Address;

int main()
{
	Memory mem{ L"kao2.exe" };
	const auto ModuleBaseAddress = mem.GetModuleAddress(L"kao2.exe");

	std::cout << std::hex << ModuleBaseAddress << std::endl;

	const auto localPlayerAdress = mem.Read<std::uintptr_t>(ModuleBaseAddress + localPlayer);
	std::cout << std::hex << localPlayerAdress << std::endl;
	const auto coinAdress = localPlayerAdress + coins;

	mem.Write<int>(coinAdress, 51);
}

