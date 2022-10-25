#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> 
#include <ctime>
using namespace std;

int main()
{
    cout << "\n\t\t\t\t\tWelcome in the program :)";
    list<int> numbers = {};

                //Init List
    for (int i = 1; i < 5; i++)
    {
        numbers.push_back(i);
    }
    cout << "\n\nList: ";
    for (int i : numbers) { cout << i << " "; }

                //first number
    cout << "\n\nfirst number = " << numbers.front();
    
                //List with 2 new elements:
    numbers.push_front(6);
    numbers.push_front(7);
    cout << "\n\nList with 2 new elements: ";
    for (int i : numbers) { cout << i << " "; }

                 //List after deleted 4th element:
    list<int>::iterator itr = numbers.begin();
    advance(itr, 3);
    numbers.erase(itr);
    cout << "\n\nList after deleted 4th element: ";
    for (int i : numbers) { cout << i << " "; }

                //List with 3 pasted in rand position:
    srand(time(NULL));    
    for (int i = 0; i < 3; i++)
    {
        list<int>::iterator itr1 = numbers.begin();
        int rundpos = rand() % (numbers.size() + 1);
        advance(itr1, rundpos);
        numbers.insert(itr1, 9);
    }
    cout << "\n\nList with 3 pasted in rand position: ";
    for (int i : numbers) { cout << i << " "; }

                //Deleted last element:
    numbers.pop_back();
    cout << "\n\nDeleted last element: ";
    for (int i : numbers) { cout << i << " "; }

                //Deleted first element:
    numbers.pop_front();
    cout << "\n\nDeleted last element: ";
    for (int i : numbers) { cout << i << " "; }

                //List with 2 pasted in middle position:
    int possition = (numbers.size() - 2) / 2;
    list<int>::iterator itr2 = numbers.begin();
    advance(itr2, possition);
    numbers.insert(itr2, 2, 8);
    cout << "\n\nList with 2 pasted in middle position: ";
    for (int i : numbers) { cout << i << " "; }
    
                //Deleted Similar element: 
    

                //Clear list
    numbers.clear();
    if (numbers.empty()) { cout << "\n\n\n All is OK, Good bye ;)"; }
    else
    {
        cout << "All is not OK :(";
    }

    
}

