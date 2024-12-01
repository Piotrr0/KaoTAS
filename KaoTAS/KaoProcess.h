#ifndef KAOPROCESS_H
#define KAOPROCESS_H

#include "Memory.h"
#include "Vector3.h"
#include "Address.h"

struct GameMemoryAddresses
{
	Address<int> ModuleBaseAddress;
	Address<int> kao2GameletAddress;
	Address<int> localPlayerAddress;

	Address<int> ducatsAddress;
	Address<int> crystalsAddress;
	Address<int> starsAddress;
	Vector3<Address<float>> positionAddress;
};

class KaoProcess
{
public:
	KaoProcess();

private:

	void ReadGameAddresses(GameMemoryAddresses& MemoryAddresses);

private:
	
	const wchar_t* processName = L"kao2.exe";
	std::unique_ptr<Memory> mem = std::make_unique<Memory>(processName);
	GameMemoryAddresses MemoryAddresses;
public:

	inline const GameMemoryAddresses& GetGameMemoryAddresses() const { return MemoryAddresses; }

};

#endif // !KAOPROCESS_H