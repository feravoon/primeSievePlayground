#include "bitArray.h"

template <typename T>
bitArray<T>::bitArray(unsigned int sizeArg) // Constructor
{
    size = sizeArg;
    packedArray = new T[(size/8)/sizeof(T)+1];
    unsigned char val = 0b10101010;
    memset(packedArray,val,size/8 + sizeof(T));   
}

template <typename T>
bitArray<T>::~bitArray() // Destructor
{
    delete[] packedArray;
}

template <typename T>
void bitArray<T>::reset()
{
    unsigned char val = 0b10101010;
    memset(packedArray,val,size/8 + sizeof(T)); 
}

template <typename T>
unsigned char bitArray<T>::getBit(unsigned int ind)
{
    unsigned int packedIndex = ind/(sizeof(T)*8);
    unsigned int bitIndex = ind%(sizeof(T)*8);
    T mask = 1 << bitIndex;

    return (packedArray[packedIndex] & mask) >> bitIndex;
}

template <typename T>
void bitArray<T>::setBit(unsigned int ind)
{
    unsigned int packedIndex = ind/(sizeof(T)*8);
    unsigned int bitIndex = ind%(sizeof(T)*8);
    T mask = 1 << bitIndex;

    packedArray[packedIndex] = (packedArray[packedIndex] & ~mask) | mask;
}

template <typename T>
void bitArray<T>::clearBit(unsigned int ind)
{
    unsigned int packedIndex = ind/(sizeof(T)*8);
    unsigned int bitIndex = ind%(sizeof(T)*8);
    T mask = 1 << bitIndex;

    packedArray[packedIndex] = packedArray[packedIndex] & ~mask;
}

template <typename T>
unsigned int bitArray<T>::getSize()
{
    return size;
}