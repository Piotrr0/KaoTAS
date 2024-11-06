#ifndef OFFSETS_H
#define OFFSETS_H

#include <cstdint>

namespace Offset
{
	constexpr uintptr_t ducats = 0x734DC8; // + ModuleBaseAddress
	constexpr uintptr_t crystals = 0x734DCC; // + ModuleBaseAddress
	constexpr uintptr_t stars = 0x734DD0; // + ModuleBaseAddress

	constexpr uintptr_t kao2Gamelet = 0x0073E0F8; // + ModuleBaseAddress
	constexpr uintptr_t localPlayer = 0x38C; // + kao2Gamelet

	constexpr uintptr_t X = 0x58; // + localPlayer
	constexpr uintptr_t Y = 0x5C; // + localPlayer
	constexpr uintptr_t Z = 0x60; // + localPlayer
}

#endif