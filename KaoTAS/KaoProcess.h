#ifndef KAOPROCESS_H
#define KAOPROCESS_H

#include "Memory.h";


class KaoProcess
{
public:
	KaoProcess();
	bool WriteDucats(int amount);
	int ReadDucats();

private:

private:
	
	const wchar_t* processName = L"kao2.exe";
	Memory* mem = nullptr;
	uint64_t ModuleBaseAddress = 0;
	uintptr_t localPlayerAddress = 0;

public:

};

#endif // !KAOPROCESS_H