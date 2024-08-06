#pragma once
template <typename T>
class bitArray
{
    private:
        unsigned int size;
        T* packedArray;

    public:
        unsigned char getBit(unsigned int ind);
        void setBit(unsigned int ind);
        void clearBit(unsigned int ind);
        bitArray(unsigned int size);
        ~bitArray();
        unsigned int getSize();
        void reset();
};