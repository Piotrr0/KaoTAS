#ifndef KAOPROCESS_H
#define KAOPROCESS_H

#include "Memory.h"
#include "Vector3.h"

class KaoProcess
{
public:
	KaoProcess();

	template <typename T>
	bool WriteToKaoMemory(const uintptr_t& address, T amount)
	{
		if (mem == nullptr || address == 0) return false;
		if (mem->Write<T>(address, amount))
		{
			return true;
		}
		return false;
	}

	template <typename T>
	T ReadFromKaoMemory(const uintptr_t& address)
	{
		if (mem == nullptr || address == 0) return{};
		T data = mem->Read<T>(address);
		return data;
	}

private:

	void ReadGameAddresses();

private:
	
	const wchar_t* processName = L"kao2.exe";
	Memory* mem = nullptr;

	uintptr_t ModuleBaseAddress = 0;

	uintptr_t kao2GameletAddress = 0;
	uintptr_t localPlayerAddress = 0;

	Vector3<uintptr_t> positionAddress;
	uintptr_t ducatsAddress = 0;
	uintptr_t crystalsAddress = 0;
	uintptr_t starsAddress = 0;


public:
	inline uintptr_t GetDucatsAddress() const { return ducatsAddress; }
	inline uintptr_t GetCrystalsAddress() const { return crystalsAddress; }
	inline uintptr_t GetStarsAddress() const { return starsAddress; }
	inline Vector3<uintptr_t> GetPositionAddress() const { return positionAddress; }

};

#endif // !KAOPROCESS_H