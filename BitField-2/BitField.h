#pragma once
#include <iostream>
#include <stdint.h>

class BitField {
private:
    size_t _sizeBit;
    uint16_t* _mem;
    size_t _memSize;

    size_t GetMemIndex(size_t n) const;  //вернуть индекс по которому лежит данный бит
    uint16_t GetMask(size_t n) const;
public:
    BitField(size_t len);
    BitField(const BitField& tmp);
    BitField& operator=(const BitField& tmp);
    
    size_t GetLength() const;
    void SetBit(size_t n);  //устанавливает в бит значение 1
    void ClrBit(size_t n);  //значение 0
    uint8_t GetBit(size_t n) const; ////возвращает значение бита


    BitField operator|(const BitField& tmp);
    BitField operator&(const BitField& tmp);
    BitField operator^(const BitField& tmp);
    bool operator==(const BitField& tmp) const;
    BitField operator~();

    ~BitField(){
        delete [] _mem;
        _mem = nullptr;
    }
};