#ifndef OFFSETS_H
#define OFFSETS_H

#include <cstdint>

namespace Offset
{
    constexpr uintptr_t ducats = 0x734DC8; // + ModuleBaseAddress
    constexpr uintptr_t crystals = 0x734DCC; // + ModuleBaseAddress
    constexpr uintptr_t stars = 0x734DD0; // + ModuleBaseAddress
}

#endif