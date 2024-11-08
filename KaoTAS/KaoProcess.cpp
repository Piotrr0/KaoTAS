#include "KaoProcess.h"
#include <iostream>
#include "Offsets.h"

KaoProcess::KaoProcess()
{
    ModuleBaseAddress = Address<int>(mem->GetModuleAddress(processName));
	ReadGameAddresses();
}

void KaoProcess::ReadGameAddresses()
{
    kao2GameletAddress.SetAddress(Address<int>(ModuleBaseAddress.GetAddress() + Offset::kao2Gamelet).ReadValue());
    localPlayerAddress.SetAddress(Address<int>(kao2GameletAddress.GetAddress() + Offset::localPlayer).ReadValue());

    positionAddress = Vector3<Address<float>>(
        Address<float>(localPlayerAddress.GetAddress() + Offset::X),
        Address<float>(localPlayerAddress.GetAddress() + Offset::Y),
        Address<float>(localPlayerAddress.GetAddress() + Offset::Z)
    );

    ducatsAddress = Address<int>(ModuleBaseAddress.GetAddress() + Offset::ducats);
    crystalsAddress = Address<int>(ModuleBaseAddress.GetAddress() + Offset::crystals);
    starsAddress = Address<int>(ModuleBaseAddress.GetAddress() + Offset::stars);
}