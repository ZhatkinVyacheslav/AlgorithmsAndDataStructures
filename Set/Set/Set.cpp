#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

void menu() {
    cout << "\n\n-------------------------------------------------------------";
    cout << "\n1. Set a set of A";
    cout << "\n2. Set a set of B";
    cout << "\n3. Find the intersection of sets";
    cout << "\n4. Find the union of sets";
    cout << "\n5. find the difference of sets A-B";
    cout << "\n6. Find the complement of the set";
    cout << "\n7. Exit";
    cout << "\n-------------------------------------------------------------\n";
}

set <int> SetOfSet()
{
    set <int> Set;
    int size;
    cout << "\nInput how many elements there will be: ";
    cin >> size;
    int element;
    cout << "\nInput your elements: ";
    for (int i = 0; i < size; i++) {
        cin >> element;
        Set.insert(element);
    }
    return Set;
}

void DifferenceOfSets(set <int> Set1, set <int> Set2) {
    vector<int> result;
    set_difference(
        Set1.begin(), Set1.end(),
        Set2.begin(), Set2.end(),
        back_inserter(result));

    cout << "\n-------------------------------------------------------------\n";
    cout << "Set result { ";
    for (const auto& i : result)  cout << i << ' ';
    cout << "}";
    cout << "\n-------------------------------------------------------------\n";
}


void ComplementOfSet(set <int> Universe, set <int> Set) {
    int flag = 0;
    for (auto a : Set)
    {
        int flag2 = 0;
        for (auto n : Universe)
        {
            if (a == n) flag2 = 1;
        }
        if (flag2 == 0) flag = 1;
    }

    if (flag == 1) cout << "The set goes beyond the boundaries of the universe";
    else {
        DifferenceOfSets(Universe, Set);
    }
}

int main()
{
    set <int> A;
    set <int> B;
    int mode;
    cout << "\t\t\tWelcome to menu Stack :)";
    
    do {
        menu();
        cout << "\n\nInput number mode: ";
        cin >> mode;

        switch (mode)
        {
        case 1: {
            A.clear();
            A = SetOfSet();
            break;
        }

        case 2: {
            B.clear();
            B = SetOfSet();
            break;
        }

        case 3: {
            vector<int> result;
            set_intersection(
                A.begin(), A.end(),
                B.begin(), B.end(),
                std::back_inserter(result));

            cout << "\n-------------------------------------------------------------\n";
            cout << "Set result { ";
            for (const auto& i : result)  cout << i << ' ';
            cout << "}";
            cout << "\n-------------------------------------------------------------\n";
            
            break;
        }

        case 4: {
            vector<int> result;
            set_union(
                A.begin(), A.end(),
                B.begin(), B.end(),
                back_inserter(result));

            cout << "\n\n-------------------------------------------------------------\n";
            cout << "Set result { ";
            for (const auto& i : result)  cout << i << ' ';
            cout << "}";
            cout << "\n-------------------------------------------------------------\n";

            break;
        }

        case 5: {
            DifferenceOfSets(A, B);

            break;
        }

        case 6: {

            set <int> U;
            cout << "\nSet a set of Universe\n";
            U = SetOfSet();

            cout << "\nFor which set: ";
            char mode1;
            cin >> mode1;
            switch (mode1)
            {
                case 'A':
                {
                    ComplementOfSet(U, A);
                    break;
                }

                case 'B':
                {
                    ComplementOfSet(U, B);
                    break;
                }
            default:
                cout << "\nThis set no one";
                break;
            }
            break;
        }

        case 7: {
            cout << "\n\n\n\n\t\t\t\t\tGood Bye! Good luck! :)\n\n";
            cout << "\n-----------------------------------------------------------------------------------------\n";
            break;
        }

        default:
            break;
        }


    } while (mode != 7);

    return 0;
}

