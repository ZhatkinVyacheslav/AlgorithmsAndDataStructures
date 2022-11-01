#include <iostream>
#include <stack>

using namespace std;

void menu() {
    cout << "\n\n1. Put an element in satck";
    cout << "\n2. Pick up an item";
    cout << "\n3. Print stack";
    cout << "\n4. Clear stack";
    cout << "\n5. Exit";
}

int main()
{
    stack<int> mainstack;
    int mode;
    cout << "\t\t\tWelcome to menu Stack :)";

    do {
        menu();
        cout << "\n\nInput number mode: ";
        cin >> mode;
        
        switch (mode)
        {
        case 1:
        {
            int newelement;
            cout << "\n\nInput new element: ";
            cin >> newelement;
            mainstack.push(newelement);
            break;
        }

        case 2:
        {
            int pickupelement;
            pickupelement = mainstack.top();
            mainstack.pop();
            cout << "\n\nElement " << pickupelement << " was deleted";
            break;
        }

        case 3:
        {
            size_t size = mainstack.size();
            int* swapmass = new int[size];
            cout << "|   |";
            for (int i = 0; i < size; i++)
            {
                swapmass[i] = mainstack.top();
                cout << "\n| " << mainstack.top() << " |";
                mainstack.pop();
            }
            cout << "\n-----";

            for (int i = size - 1; i >= 0; i--)
            {
                mainstack.push(swapmass[i]);            
            }

            break;
        }

        case 4:
        {
            while (!mainstack.empty()) { mainstack.pop(); }
            cout << "\n\nStack is clear";
            break;
        }

        case 5:
        {
            cout << "Good bye :)";
            break;
        }
        default:
            break;
        }
    } while (mode != 5);

    return 0;
}

