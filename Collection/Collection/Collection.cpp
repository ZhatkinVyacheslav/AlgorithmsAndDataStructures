#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool IsOdd(int i)
{
    return (i < 10 );
}

bool IsEvenNum(int i)
{
    return ((i % 2) == 0);
}

int Multiply3(int i)
{
    return (i * 3);
}

int main()
{
    srand(time(0));
    vector <int> firstvector(20, 0);

    cout << "vector = {";
    for (int i = 0; i < firstvector.size(); i++)
    {
        firstvector[i] = -100 + rand() % 201;
        cout << " " << firstvector[i] << " ";
    }

    int max = *max_element(firstvector.begin(), firstvector.end());
    int min = *min_element(firstvector.begin(), firstvector.end());

    cout << "}\n\nmax = " << max << "\nmin = " << min << "\n";

    sort(firstvector.begin(), firstvector.end());
    cout << "\nsort vector: ";
    for (auto a : firstvector) {
        cout << a << " ";
    }


    cout << "\n\nInserted 4 elements: ";
    for (int i = 0; i < 4; i++) {
        int randnum = -100 + rand() % 201;
        firstvector.push_back(randnum);
    }

    for (auto a : firstvector) {
        cout << a << " ";
    }


    cout << "\n\n(elements < 10) = 0: ";
    replace_if(firstvector.begin(), firstvector.end(), IsOdd, 0);
    for (auto a : firstvector) {
        cout << a << " ";
    }

    cout << "\n\nelements > 20: ";
    for_each(firstvector.begin(), firstvector.end(), [](int a)
        {
            if (a > 20) { cout << a << " "; }
        });

    cout << "\n\neven numbers * 3: ";
    for_each(firstvector.begin(), firstvector.end(), [](int& a) {
        if ((a % 2) == 0) 
        { 
            a = a * 3;
            cout << a << " ";
        }
        else
        {
            cout << a; 
        }
        });

    cout << "\n\nShufle vector: ";
    random_shuffle(firstvector.begin(), firstvector.end());
    for (auto a : firstvector) {
        cout << a << " ";
    }

    cout << "\n\nelements > 50 deleted: ";
    for (int i = 0; i < firstvector.size(); i++) {
        if (firstvector[i] > 50) { firstvector.erase(firstvector.begin() + i); }
        cout << firstvector[i] << " ";
    }


    cout << "vector size = " << firstvector.size();

    if ((firstvector.size() % 2) == 0) {
        cout << "\nRevers vector: ";
        for (vector<int>::reverse_iterator iter = firstvector.rbegin(); iter != firstvector.rend(); ++iter)
        {
            cout << *iter << " ";
        }
    }
    else {
        cout << "\n\nDeleted last element: ";
        firstvector.pop_back();
        for (auto a : firstvector) {
            cout << a << " ";
        }
    }

    firstvector.clear();
    if (firstvector.empty())
    {
        cout << "\n\nVector is empty\n\n\t\t\t*The End*\n\n";
    }
    else { cout << "\n\nVector is not empty :(, programm worked not correct"; }

    return 0;
}
