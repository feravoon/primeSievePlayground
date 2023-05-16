#pragma once
template <typename T>
class bitArray
{
    private:
        unsigned int size;
        T* packedArray;

    public:
        unsigned int getBit(unsigned int ind);
        void setBit(unsigned int ind, unsigned int val);
        bitArray(unsigned int size);
        unsigned int getSize();
        void reset();
};