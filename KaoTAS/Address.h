#ifndef ADDRESS_H
#define ADDRESS_H

#include <cstdint>
#include <memory>
#include <exception>

#include "Memory.h"

template <typename T>
class Address {
public:
    explicit Address(uintptr_t address);
    Address() = default;

    Address(const Address& other);
    Address& operator=(const Address& other);

    T ReadValue();
    bool WriteValue(T value);

private:
    std::shared_ptr<Memory> mem = std::make_shared<Memory>(L"kao2.exe");
    uintptr_t address = 0;

public:
    inline uintptr_t GetAddress() const { return address; }
    inline void SetAddress(uintptr_t address) { this->address = address; }
};

template <typename T>
Address<T>::Address(uintptr_t address) : address(address)
{

}

// Copy constructor
template <typename T>
Address<T>::Address(const Address& other)
    : address(other.address), mem(other.mem)
{
}

// Assignment operator
template <typename T>
Address<T>& Address<T>::operator=(const Address<T>& other)
{
    if (this != &other)
    {
        address = other.address;
        mem = other.mem;
    }
    return *this;
}

template <typename T>
T Address<T>::ReadValue()
{
    return mem->Read<T>(address);
}

template <typename T>
bool Address<T>::WriteValue(T value)
{
    if (mem->Write<T>(address, value))
    {
        return true;
    }
    return false;
}
#endif