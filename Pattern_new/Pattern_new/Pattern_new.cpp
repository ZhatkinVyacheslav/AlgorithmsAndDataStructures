#include <iostream>
#include <ostream>

template <typename T> class Coordinates;
 
template <typename T>
std::ostream & operator << (std::ostream &os, const Coordinates<T> &);
 
template <typename T>
class Coordinates
{
public:
    T x;
    T y;

    Coordinates()
    {
        x = 0;
        y = 0;
    }

    Coordinates(T x1, T y1)
    {
        x = x1;
        y = y1;
    }

    Coordinates operator +(const Coordinates& right)
    {
        Coordinates coord;

        coord.x = this->x + right.x;
        coord.y = this->y + right.y;

        return coord;
    }

    Coordinates operator =(const Coordinates& right)
    {
        if (this == &right)
        {
            return *this;
        }

        x = right.x;
        y = right.y;

        return *this;
    }
    
    friend std::ostream& operator<< <T>(std::ostream& os, const Coordinates<T> &v);
};
 
 
template <typename T>
std::ostream & operator << (std::ostream &os, const Coordinates<T> &dt)
{
    os << "(" << dt.x << ';' << dt.y << ")";

    return os;
}
 
int main()
{
    Coordinates<int>b(5, 6), c(4, 6);
    std::cout << "\nC" << c << "\nB" << b;

    b = b + c;

    std::cout << "\nCoord Summ" << b;

    return 0;
}

