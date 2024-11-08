#ifndef KAOPROCESS_H
#define KAOPROCESS_H

#include "Memory.h"
#include "Vector3.h"
#include "Address.h"

class KaoProcess
{
public:
	KaoProcess();

private:

	void ReadGameAddresses();

private:
	
	const wchar_t* processName = L"kao2.exe";
	std::unique_ptr<Memory> mem = std::make_unique<Memory>(processName);

	Address<int> ModuleBaseAddress;
	Address<int> kao2GameletAddress;
	Address<int> localPlayerAddress;

	Address<int> ducatsAddress;
	Address<int> crystalsAddress;
	Address<int> starsAddress;
	Vector3<Address<float>> positionAddress;

public:
	inline Address<int> GetDucatsAddress() const { return ducatsAddress; }
	inline Address<int> GetCrystalsAddress() const { return crystalsAddress; }
	inline Address<int> GetStarsAddress() const { return starsAddress; }
	inline Vector3<Address<float>> GetPositionAddress() const { return positionAddress; }
};

#endif // !KAOPROCESS_H