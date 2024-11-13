#include "Set.h"
#include "BitField.h"
#include <vector>
#include <math.h>

Set::Set(size_t mp) : _bitField(mp) {
    _maxPower = mp;
}
    

Set::Set(const Set& set) : _bitField(set._bitField),  _maxPower(set._maxPower){    
}
   
Set::Set(const BitField& bf) : _bitField(bf),  _maxPower(bf.GetLength()){
   
}

void Set::InsElem(uint64_t elem){
    // if (elem >= _maxPower) 
    //     throw std::out_of_range("44Element out of range!");
    _bitField.SetBit(elem);
}

void Set::DelElem(uint64_t elem){
    // if (elem >= _maxPower) 
    //     throw std::out_of_range("44Element out of range!");
    _bitField.ClrBit(elem);
}

bool Set::IsMember(uint64_t elem) const{
    // if (elem >= _maxPower) 
    //     throw std::out_of_range("55Element out of range!");
    return _bitField.GetBit(elem);
}

std::vector<uint64_t> Set::GetPrimary(){
    // std::vector<uint64_t> prost;
    // Set copy(*this);
    // size_t size = copy.GetMaxPower();
    // prost.push_back(1);
    // prost.push_back(2);

    // for(size_t i = 3; i < size; i+= 2){
    //     if(copy._bitField.GetBit(i)){
    //         prost.push_back(i);
    //         for(size_t p = i*i; p < size; p += i){
    //             copy._bitField.ClrBit(p);
    //         }
    //     }
    // }
    // return prost;

    std::vector<uint64_t> prost;
    Set copy(*this);
    size_t size_copy = copy.GetMaxPower();
    prost.push_back(1);
    for (size_t i = 2; i < size_copy; ++i) {
        if (copy.IsMember(i) == true) {
            prost.push_back(i);
            for (size_t j = i * i; j < size_copy; j += i) {
                copy.DelElem(j);
            }
        }
    }
    return prost;
}

size_t Set::GetMaxPower(void) const{
    return _maxPower;
}


bool Set::operator==(const Set& s) const{
    return _bitField == s._bitField;
}

bool Set::operator!=(const Set& s) const{
    if (_bitField == s._bitField)
        return false;
    return true;
}

Set& Set::operator=(const Set& tmp){
    //_maxPower = tmp._maxPower;
    _maxPower = tmp.GetMaxPower();
    _bitField = tmp._bitField;
    return *this;
}

Set Set::operator+(const Set& tmp){
    return _bitField | tmp._bitField;
}

Set Set::operator+(const uint64_t elem){
    Set s(*this);
    s.InsElem(elem);
    return s;
}

Set Set::operator-(const uint64_t elem){
    Set s(*this);
    s.DelElem(elem);
    return s;
}

Set Set::operator*(const Set& tmp){
    return _bitField & tmp._bitField;
}

Set Set::operator~(){
    return Set(~_bitField);
}

