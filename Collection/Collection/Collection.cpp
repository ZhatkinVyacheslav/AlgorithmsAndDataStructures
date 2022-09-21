#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));
    vector <int> firstvector(20, 0);

    cout << "vector = {";
    for (int i = 0; i < firstvector.size(); i++)
    {
        firstvector[i] = -100 + rand() % 201;
        cout <<" " << firstvector[i] << " ";
    }

    int max = *max_element(firstvector.begin(), firstvector.end());
    int min = *min_element(firstvector.begin(), firstvector.end());

    cout << "}\n\nmax = " << max << "\nmin = " << min << "\n";

    sort(firstvector.begin(), firstvector.end());
    cout << "\nsort vector: ";
    for (int i = 0; i < 20; i++) {
        cout << firstvector[i] << " ";
    }

  
    cout << "\n\nInserted 4 elements: ";
    for (int i = 0; i < 4; i++) {
        int randnum = -100 + rand() % 201;
        firstvector.push_back(randnum);
    }

    for (int i = 0; i < firstvector.size(); i++) {
        cout << firstvector[i] << " ";
    }

    sort(firstvector.begin(), firstvector.end());
    for (int i = 0; i < firstvector.size(); i++) {
        if (firstvector[i] < 10) { firstvector[i] = 0; }
    }
    cout << "\n\n(elements < 10) = 0: ";
    for (int i = 0; i < firstvector.size(); i++) {
        cout << firstvector[i] << " ";
    }

    cout << "\n\nelements > 20: ";
    for (int i = 0; i < firstvector.size(); i++) {
        if (firstvector[i] > 20) { cout << firstvector[i] << " "; }
    }


    cout << "\n\neven numbers * 3: ";
    for (int i = 0; i < firstvector.size(); i++) {
        if ((firstvector[i] % 2) == 0) { firstvector[i] = firstvector[i] * 3; }
        cout << firstvector[i] << " ";
    }

    cout << "\n\nShufle vector: ";
    std::random_shuffle(firstvector.begin(), firstvector.end());
    for (int i = 0; i < firstvector.size(); i++) {
        cout << firstvector[i] << " ";
    }
    
    for (int i = 0; i < firstvector.size(); i++) {
        if (firstvector[i] > 50) { firstvector.erase(firstvector.begin() + i);  }
    }
    cout << "\n\nelements > 50 deleted: ";
    for (int i = 0; i < firstvector.size(); i++) {
        cout << firstvector[i] << " ";
    }

    cout << "vector size = " << firstvector.size();
    

    return 0;
}
