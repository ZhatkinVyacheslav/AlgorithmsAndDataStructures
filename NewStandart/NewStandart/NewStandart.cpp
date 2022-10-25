#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void menu()
{
    cout << "modes:\n1) Input data\n2) Output data\n3) Search data\n 4) Exit\n";
}

int main()
{
    int mode;
    enum Type {Private, Public, Protected};

    vector <pair <Type, float>> vec = {
        {Private,5.5},{Public,7.35},{Protected,8.63}
    };
    
    do {
        cout << "Input mode: ";
        cin >> mode;

        switch (mode)
        {
        case 1:
        {

            Type newtype;
            int numbertype;
            float number;
            
            cout << "\nInput your number: ";
            cin >> number;
            do
            {
                cout << "\nInput your Type and number\nType:";
                cin >> numbertype;
                switch (numbertype)
                {
                case 0:
                {
                    newtype = Type::Private;
                    break;
                }
                case 1:
                {
                    newtype = Type::Public;
                    break;
                }
                case 2:
                {
                    newtype = Type::Protected;
                    break;
                }
                default:
                    cout << "Error! Try Again";
                    break;
                }
            } while ((numbertype < 0) && (numbertype > 2));
            pair <Type, float>  newpair{ newtype, number };
            vec.push_back(newpair);
            break;
        }
        case 2:
        {
            cout << "\nVector {";
            for (const auto &j : vec) {
                cout << j.first << ", " << j.second << " ; ";
            }
            cout << "}\n"; 
            break;
        }
        case 3:
        {

            float findnumber;
            int ind, i = 0;
            cout << "\nInput number which you need find:";
            cin >> findnumber;

            for_each(vec.begin(), vec.end(), [&](pair <Type, float> &a)
                {
                    if (a.second == findnumber)
                    {
                        if (a.first == 2) { a.first = 0; }
                    }
                    else { i++; }
                }
            );

            break;
        }
        case 4:
        {
            cout << "Good bye! Have a nice day!";
            break;
        }
        }
    } while (mode != 4);

    return 0;
}

