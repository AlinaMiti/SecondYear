#include "BitField.h"
#include <vector>
#pragma once

class Set {
private:
    BitField _bitField;
    size_t _maxPower;
public:
    Set(size_t mp) : _bitField(mp){}
    Set(const Set& set);
    Set(const BitField& bf);
    operator BitField();  //static_cast

    size_t GetMaxPower(){
        return _maxPower;
    }
    void InsertElem(uint64_t elem);
    void DeleteElem(uint64_t elem);
    bool IsMember(uint64_t elem); //есть ли он в множестве

    bool operator==(const Set& tmp); // пофиг на размер
    Set& operator=(const Set& tmp);
    Set operator+(const Set& tmp); //объединение двух множеств
    Set operator+(uint64_t tmp);
    Set operator-(uint64_t tmp);
    Set operator*(const Set& tmp); //пересечение
    Set operator~();

    std::vector<uint64_t> GetPrimary();

    friend std::istream& operator>>(std::istream& istr, Set& set);
    friend std::istream& operator<<(std::istream& istr, const Set& set);
};