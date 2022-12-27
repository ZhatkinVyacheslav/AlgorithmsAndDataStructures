#pragma once

#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_

#include <iostream>
#include <bit>

using elem_type = unsigned char;

class TBitField {
private:
    size_t  bitLen;                      // длина битового пол€ (максимальное допустимое значение эл-та мн-ва, универс)
    size_t  memLen;                      // кол-во элементов, необходимое дл€ хранени€ битового пол€
    elem_type* pMem;                     // пам€ть дл€ представлени€ битового пол€

    // служебные пол€
    size_t bitsInElem = std::numeric_limits<elem_type>::digits;
    size_t shiftSize = std::bit_width(bitsInElem - 1);

    // служебные методы
    size_t GetMemIndex(size_t pos) const noexcept {        // индекс в pћем дл€ бита pos
        return pos >> shiftSize;
    }

    elem_type GetMemMask(size_t pos) const noexcept {      // битова€ маска дл€ бита pos
        return 1 << (pos & (bitsInElem - 1));
    }

public:
    // об€зательный классический функционал
    TBitField(size_t _BitLen) {                            // конструктор специального вида
        bitLen = _BitLen;
        memLen = (bitLen + bitsInElem - 1) >> shiftSize;
        pMem = new elem_type[memLen];
        memset(pMem, 0, memLen * sizeof(elem_type));
    };
    TBitField(const TBitField& bf) {
        bitLen = bf.bitLen;
        memLen = bf.memLen;
        pMem = new elem_type[memLen];
        memcpy(pMem, bf.pMem, memLen * sizeof(elem_type));
    };                                                  // конструктор копировани€
    TBitField(TBitField&& bf) noexcept {
        pMem = nullptr;
        swap(*this, bf);
    };                                                  // move-конструктор (перемещение содержимого bf в this)
    ~TBitField() {
        delete[] pMem;
    };                                                  // деструктор


    TBitField& operator=(const TBitField& bf) {         // операци€ =
        if (this != &bf) {
            TBitField temp(bf);
            swap(*this, temp);
        }
        return *this;
    };

    TBitField& operator=(TBitField&& bf) noexcept {
        if (this != &bf) {
            swap(*this, bf);
        }
        return *this;
    };                                                  // операци€ = (move)

    size_t size() const noexcept { return bitLen; }     // получить длину (к-во битов)

    bool operator==(const TBitField& bf) const noexcept {
        if (bitLen != bf.bitLen)
            return false;
        for (int i = 0; i < memLen; i++) {
            if (pMem[i] != bf.pMem[i])
                return false;
        }
        return true;
    };
    bool operator!=(const TBitField& bf) const noexcept {
        return !(*this == bf);
    };

    bool test(size_t i) const {                         // получить значение бита i
        if (i >= bitLen)
            throw std::out_of_range("Exception Type: bit position is Out of Range.");
        return pMem[GetMemIndex(i)] & GetMemMask(i);
    };
    void set(size_t i) {
        if (i >= bitLen)
            throw std::out_of_range("Exception Type: bit position is Out of Range.");
        pMem[GetMemIndex(i)] |= GetMemMask(i);
    };                                                  // установить бит i
    void reset(size_t i) {
        if (i >= bitLen)
            throw std::out_of_range("Exception Type: bit position is Out of Range.");
        pMem[GetMemIndex(i)] &= ~GetMemMask(i);
    };                                                  // очистить бит i

    TBitField  operator|(const TBitField& bf) {
        TBitField temp(*this);
        if (bitLen != bf.bitLen)
            throw std::length_error("TBitFields objects have different sizes.");
        for (size_t i = 0; i < bf.memLen; i++) {
            temp.pMem[i] |= bf.pMem[i];
        }
        return temp;
    };                                                  // ќпераци€ "или"
    TBitField  operator&(const TBitField& bf) {
        int lenght = bitLen;
        if (bf.bitLen > lenght)
            lenght = bf.bitLen;

        TBitField temp(lenght);
        for (int i = 0; i < memLen; i++)
            temp.pMem[i] = pMem[i];
        for (int i = 0; i < bf.memLen; i++)
            temp.pMem[i] &= bf.pMem[i];
        return temp;
    };                                                   // ќпераци€ "и"
    TBitField  operator~(void) {
        TBitField tmp(bitLen);
        for (int i = 0; i < bitLen; i++) {
            if (test(i) == 0) {
                tmp.set(i);
            }
            else {
                tmp.reset(i);
            }
        }
        return tmp;
    };                                                  // ќпераци€ "отрицание"


    // ввод/вывод
    friend void swap(TBitField& lhs, TBitField& rhs) noexcept {
        std::swap(lhs.bitLen, rhs.bitLen);
        std::swap(lhs.memLen, rhs.memLen);
        std::swap(lhs.pMem, rhs.pMem);
    };
    friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf) {
        size_t lenght = bf.size();
        for (size_t i = 0; i < lenght; i++) {
            if (bf.test(i))
                ostr << '1';
            else
                ostr << '0';
        }
        return ostr;
    }
};

#endif  // INCLUDE_BITFIELD_H_