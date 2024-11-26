#include "BitField.h"

// BitField::BitField(size_t len) : _sizeBit(len) {
//     //_memSize = (len + (sizeof(uint16_t) * 8 - 1)) / (sizeof(uint16_t) * 8);
//         _memSize = (len + (sizeof(uint16_t) * 8 - 1)) / (sizeof(uint16_t) * 8); //Исправленное вычисление memsize
//         _mem = new uint16_t[_memSize](); //Инициализация памяти нулями
        
//     }


// BitField::BitField(size_t len) : _sizeBit(len){
//     //_sizeBit = len;
//     //_memSize = (len / (8 * sizeof(uint16_t))) + (len % (8 * sizeof(uint16_t)) != 0);
//     _memSize = (len + (sizeof(uint16_t) * 8 - 1)) / (sizeof(uint16_t) * 8);
//     _mem = new uint16_t[_memSize];
//     for (size_t i = 0; i < _memSize; ++i)
//         _mem[i] = 0;
// }

BitField::BitField(size_t len) {
    _sizeBit = len;
    _memSize = (len / (8 * sizeof(uint16_t))) + (len % (8 * sizeof(uint16_t)) != 0);
    _mem = new uint16_t[_memSize];
    std::memset(_mem,0, _memSize);
    // for (size_t i = 0; i < _memSize; ++i)
    //     _mem[i] = 0;
}

BitField::BitField(const BitField& tmp) {
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = new uint16_t[_memSize];
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = tmp._mem[i];
}

BitField& BitField::operator=(const BitField& tmp){
    if (_sizeBit != tmp._sizeBit){
        delete [] _mem;
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        _mem = new uint16_t[_memSize];
    }
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = tmp._mem[i];
    return *this;
}

size_t BitField::GetLength() const{
    return _sizeBit;
}

uint16_t BitField::GetMask(size_t n) const {
    // return 1 << (n % 16);
    return 1 << (n % (8 * sizeof(uint16_t)));
}

void BitField::SetBit(size_t n) {
    if (n >= _sizeBit)
        throw "Bit out of range!";
    _mem[GetMemIndex(n)] |= GetMask(n);
}

size_t BitField::GetMemIndex(size_t n) const {
    if (n >= _sizeBit)
        throw "Bit out of range!";
    
    return n/(sizeof(uint16_t) * 8);
}

uint8_t BitField::GetBit(size_t n) const {
    if (n >= _sizeBit)
        throw "hggh";
    return ((_mem[GetMemIndex(n)] & GetMask(n)) != 0);
}

void BitField::ClrBit(size_t n){
    // uint16_t mask = GetMask(n);
    // mask = ~mask;
    // _mem[GetMemIndex(n)] &= mask;
    _mem[GetMemIndex(n)] &= (~GetMask(n));
} 

BitField BitField::operator|(const BitField& tmp){
    // if (_sizeBit != tmp._sizeBit) 
    //     throw "error";
    BitField result = BitField(*this);
        for(size_t i = 0; i < _memSize; i++){
            result._mem[i] = _mem[i] | tmp._mem[i];
        }
        return result;

}

BitField BitField::operator&(const BitField& tmp){
    // if (_sizeBit != tmp._sizeBit) 
    //     throw "error";
    BitField result = BitField(*this);
        for(size_t i = 0; i < _memSize; i++)
            result._mem[i] &= tmp._mem[i];
            
        return result;
}

BitField BitField::operator^(const BitField& tmp){
    // if (_sizeBit != tmp._sizeBit) 
    //     throw "error";
    BitField result = BitField(*this);
        for(size_t i = 0; i < _memSize; i++)
            result._mem[i] ^= tmp._mem[i];
            
        return result;
}

bool BitField::operator==(const BitField& tmp) const{
    // if (_sizeBit != tmp._sizeBit)
    //     return false;
    for (size_t i = 0; i < _memSize; i++){  
        if (_mem[i] != tmp._mem[i])
            return false;
    }
    return true;
}

BitField BitField::operator~(){
    BitField copy = BitField(*this);
    for (size_t i = 0; i < _sizeBit; i++){
        if (GetBit(i))
            copy.ClrBit(i);
        else 
            copy.SetBit(i);
    }
    return copy;
}


BitField BitField::operator<<(const size_t n) const {
    BitField result(_sizeBit); 

    if (n >= _sizeBit) { 
        return result; 
    }

    for (size_t i = 0; i < _memSize; ++i) {
        if (i + n / (sizeof(uint16_t) * 8) < _memSize) {
            result._mem[i + n / (sizeof(uint16_t) * 8)] |= (_mem[i] >> (n % (sizeof(uint16_t) * 8)));
        }
    }
    return result;
}

BitField BitField::operator>>(const size_t n) const {
    BitField result(_sizeBit); 

    if (n >= _sizeBit) { 
        return result; 
    }

    for (size_t i = 0; i < _memSize; ++i) {
        if (i + n / (sizeof(uint16_t) * 8) < _memSize) {
            result._mem[i + n / (sizeof(uint16_t) * 8)] |= (_mem[i] << (n % (sizeof(uint16_t) * 8)));
        }
    }
    return result;
}



// BitField BitField::operator<<(size_t n) const{
//     BitField result = BitField(*this);

//     if (n >= _memSize) {  
//         for (size_t i = 0; i < _memSize; ++i) {
//             result._mem[i] = 0;
//         }
//         return result;
//     }

//     if(n < _memSize){
//     for (size_t i = 0; i < _memSize; i++){
//         if (i + n <= _memSize)
//             result._mem[i] = _mem[i+n];
        
//         else
//             result._mem[i] = 0;
        
//     }
//     }
//     return result;
// }