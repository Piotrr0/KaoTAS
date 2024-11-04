#include "Memory.h"

#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <iostream>

Memory::Memory(const wchar_t* processName) noexcept
{
    ::PROCESSENTRY32 entry = { };
    entry.dwSize = sizeof(::PROCESSENTRY32);

    const auto processSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (processSnapshot == INVALID_HANDLE_VALUE)
        return;

    bool foundProcess = false;
    while (::Process32Next(processSnapshot, &entry))
    {
        if (!_wcsicmp(processName, entry.szExeFile))
        {
            processId = entry.th32ProcessID;
            processHandle = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

            if (!processHandle)
            {
                std::cerr << "Failed to open process.\n";
                processId = 0;
            }
            foundProcess = true;
            break;
        }
    }

    if (processSnapshot)
        ::CloseHandle(processSnapshot);
}

Memory::~Memory()
{
    if (processHandle)
        ::CloseHandle(processHandle);
}

bool Memory::IsValid() const noexcept
{
    return processHandle != nullptr;
}

const std::uintptr_t Memory::GetModuleAddress(const wchar_t* moduleName) const noexcept
{
    if (!processHandle)
        return 0;


    ::MODULEENTRY32 entry = {};
    entry.dwSize = sizeof(::MODULEENTRY32);

    const auto moduleSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);
    if (moduleSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    std::uintptr_t moduleBaseAddress = 0;
    bool foundModule = false;

    while (::Module32Next(moduleSnapshot, &entry))
    {
        if (!_wcsicmp(moduleName, entry.szModule))
        {
            moduleBaseAddress = reinterpret_cast<std::uintptr_t>(entry.modBaseAddr);
            foundModule = true;
            break;
        }
    }

    if (moduleSnapshot)
        ::CloseHandle(moduleSnapshot);

    return moduleBaseAddress;
}
