#ifndef MEMORY_H
#define MEMORY_H

#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <iostream>

class Memory
{
private:
    std::uintptr_t processId = 0;
    void* processHandle = nullptr;

public:
    Memory(const wchar_t* processName) noexcept;

    ~Memory();

    bool IsValid() const noexcept;

    const std::uintptr_t GetModuleAddress(const wchar_t* moduleName) const noexcept;

    template <typename T>
    constexpr const T Read(const std::uintptr_t& address) const noexcept
    {
        if (!processHandle)
        {
            return T();
        }

        T value = {};
        bool success = ::ReadProcessMemory(processHandle, reinterpret_cast<const void*>(address), &value, sizeof(T), NULL);
        if (!success)
        {
            std::cerr << "Failed to read memory at address: " << std::hex << address << ". Error: " << ::GetLastError() << "\n";
        }

        return value;
    }

    template <typename T>
    constexpr bool Write(const std::uintptr_t& address, const T& value) const noexcept
    {
        if (!processHandle)
        {
            return false;
        }

        bool success = ::WriteProcessMemory(processHandle, reinterpret_cast<void*>(address), &value, sizeof(T), NULL);
        if (!success)
        {
            std::cerr << "Failed to write memory at address: " << std::hex << address << ". Error: " << ::GetLastError() << "\n";
        }

        return success;
    }
};

#endif