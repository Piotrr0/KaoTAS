#ifndef KAOPROCESS_H
#define KAOPROCESS_H

#include "Memory.h"


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

	uint64_t ModuleBaseAddress = 0;
	uintptr_t localPlayerAddress = 0;
	uintptr_t ducatsAddress = 0;

public:
	inline uintptr_t GetLocalPlayerAddress() const { return localPlayerAddress; }
	inline uintptr_t GetDucatsAddress() const { return ducatsAddress; }

};

#endif // !KAOPROCESS_H