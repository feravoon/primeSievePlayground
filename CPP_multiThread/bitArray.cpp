#include "bitArray.h"

template <typename T>
bitArray<T>::bitArray(unsigned int sizeArg)
{
    size = sizeArg;
    packedArray = new T[size/sizeof(T)+1];
    unsigned char val = 0b10101010;
    memset(packedArray,val,size/sizeof(T)+1);   
}

template <typename T>
void bitArray<T>::reset()
{
    unsigned char val = 0b10101010;
    memset(packedArray,val,size/sizeof(T)+1); 
}

template <typename T>
unsigned int bitArray<T>::getBit(unsigned int ind)
{
    unsigned int bitIndex = ind%sizeof(T);
    T packedVal = packedArray[ind/sizeof(T)];
    T mask = 1 << bitIndex;
    packedVal &= mask;
    return packedVal>>bitIndex;
}

template <typename T>
void bitArray<T>::setBit(unsigned int ind, unsigned int val)
{
    unsigned int packedIndex = ind/sizeof(T);
    unsigned int bitIndex = ind%sizeof(T);
    T mask = 1 << bitIndex;

    packedArray[packedIndex] &= ~mask;
    packedArray[packedIndex] |= ((T)val) << bitIndex;
}

template <typename T>
unsigned int bitArray<T>::getSize()
{
    return size;
}