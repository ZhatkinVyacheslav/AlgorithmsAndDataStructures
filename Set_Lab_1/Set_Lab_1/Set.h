#pragma once
#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include <iostream>
#include "bitfield.h"

class TSet {
private:
    size_t maxPower;                       // ������������ �������� ���������
    TBitField bitField;                    // ������� ���� ��� �������� ������������������� �������
public:
    TSet(int mp) : maxPower(mp), bitField(mp) {};
    TSet(const TSet& s) : maxPower(s.maxPower), bitField(s.bitField) {};                   // ����������� �����������
    operator TBitField() {
        TBitField tmp(bitField);
        return tmp;
    };                                     // �������������� ���� � �������� ����

    size_t GetMaxPower(void) const noexcept { return maxPower; }

    void InsElem(size_t Elem) {
        if (Elem >= maxPower)
            throw std::out_of_range("Element is not contained in max power of Set");
        bitField.set(Elem);
    };                                     // �������� ������� � ���������

    void DelElem(size_t Elem) {
        if (Elem >= maxPower)
            throw std::out_of_range("Element is not contained in max power of Set");
        bitField.reset(Elem);
    };                                     // ������� ������� �� ���������

    bool IsMember(size_t Elem) const { return bitField.test(Elem); };     // ��������� ������� �������� � ���������

    TSet operator+ (const int Elem) {
        InsElem(Elem);
        return *this;
    };                                     // ����������� � ���������

    TSet operator- (const int Elem) {
        DelElem(Elem);
        return *this;
    };                                     // �������� � ���������

    TSet operator+ (const TSet& s) {
        if (maxPower != s.maxPower)
            throw std::length_error("TSet objects have different size");
        TSet temp(s);
        temp.bitField = bitField | s.bitField;
        return temp;
    };                                     // �����������

    TSet operator* (const TSet& s) {
        if (this->maxPower >= s.maxPower)
        {
            TSet temp(this->maxPower);
            temp.bitField = this->bitField & s.bitField;
            return temp;
        }
        else
        {
            TSet temp(s.maxPower);
            temp.bitField = this->bitField & s.bitField;
            return temp;
        }
    };                                     // �����������

    TSet operator~ (void) {
        bitField = ~bitField;
        return *this;
    };                                     // ����������

    int operator== (const TSet& s) const { return bitField == s.bitField; };
    int operator!= (const TSet& s) const { return !(*this == s); };
    TSet& operator=(const TSet& s) {
        if (this != &s) {
            this->maxPower = s.maxPower;
            this->bitField = s.bitField;
        }
        return *this;
    };

    friend std::istream& operator>>(std::istream& in, TSet& bf) {
        std::string inpt;
        for (int i = 0; i < bf.GetMaxPower(); i++)
        {
            std::cout << i << " The element is included in the set?" << std::endl;
            in >> inpt;
            if (inpt == "+") {
                bf.InsElem(i);
            }
            else if (inpt == "-") {
                bf.DelElem(i);
            }
            else {
                throw ("You can only answer: '+' or  '-'");
            }
            std::cout << std::endl;
        }
    };
    friend std::ostream& operator<<(std::ostream& out, const TSet& bf) {
        size_t size = bf.GetMaxPower();
        for (size_t i = 0; i < size; i++) {
            if (bf.IsMember(i)) {
                out << i << " ";
            }
        }
        return out;
    };
};

#endif  // INCLUDE_SET_H_