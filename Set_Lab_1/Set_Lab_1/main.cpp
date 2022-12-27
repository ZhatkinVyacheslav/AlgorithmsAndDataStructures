#include "Set.h";
#include "bitfield.h"
#include <sstream>
#include <iostream>
#include <iomanip>


int main() {

    std::cout << "\t\tThe Sieve of Eratosthenes\n\n";
    std::cout << ">Input the upper bound: ";
    int max;
    std::cin >> max;

    TSet Mainset(max + 1);                            
    for (int i = 2; i <= max; i++) Mainset.InsElem(i);
 
    for (int i = 2; i * i <= max; i++)
    {
        if (Mainset.IsMember(i))
        {
            for (int j = 2 * i; j <= max; j += i)
            {
                 if (Mainset.IsMember(j)) Mainset.DelElem(j);
            }
        }
    }

    std::cout << "\n>Sets of non-multiple numbers : " << Mainset;

    std::cout << "\n>Prime numbers : ";  
    int count = 0;
    int koef = 1;
    for (int i = 2; i <= max; i++)
        if (Mainset.IsMember(i))
        {
            count++;
            std::cout << std::setw(3) << i << " ";
            if (koef++ % 10 == 0)
                std::cout << " ";
        }

    std::cout << "\nNumber of prime numbers: " << count;
}