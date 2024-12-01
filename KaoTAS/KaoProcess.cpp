#include "KaoProcess.h"
#include <iostream>
#include "Offsets.h"

KaoProcess::KaoProcess()
{
    MemoryAddresses.ModuleBaseAddress = Address<int>(mem->GetModuleAddress(processName));
	ReadGameAddresses(MemoryAddresses);
}

void KaoProcess::ReadGameAddresses(GameMemoryAddresses& MemoryAddresses)
{
    MemoryAddresses.kao2GameletAddress.SetAddress(Address<int>(MemoryAddresses.ModuleBaseAddress.GetAddress() + Offset::kao2Gamelet).ReadValue());
    MemoryAddresses.localPlayerAddress.SetAddress(Address<int>(MemoryAddresses.kao2GameletAddress.GetAddress() + Offset::localPlayer).ReadValue());

    MemoryAddresses.positionAddress = Vector3<Address<float>>(
        Address<float>(MemoryAddresses.localPlayerAddress.GetAddress() + Offset::X),
        Address<float>(MemoryAddresses.localPlayerAddress.GetAddress() + Offset::Y),
        Address<float>(MemoryAddresses.localPlayerAddress.GetAddress() + Offset::Z)
    );

    MemoryAddresses.ducatsAddress = Address<int>(MemoryAddresses.ModuleBaseAddress.GetAddress() + Offset::ducats);
    MemoryAddresses.crystalsAddress = Address<int>(MemoryAddresses.ModuleBaseAddress.GetAddress() + Offset::crystals);
    MemoryAddresses.starsAddress = Address<int>(MemoryAddresses.ModuleBaseAddress.GetAddress() + Offset::stars);
}