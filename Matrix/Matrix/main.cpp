#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void menu() 
{
    cout << "\n------------------------------------------\n";
    cout << "1 - Set the matrix \n2 - Sum \n3 - Subtraction \n4 - Multiplication on vector \n5 - Multiplication on other matrix \n6 - Transpose \n7 - exit";
    cout << "\n------------------------------------------\n";
}

void PrintVector(vector <vector <int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "\n";
        for (int j = 0; j < vec.size(); j++) { cout << vec[i][j] << " "; }
    }
}

vector <vector <int>> VectorSet( int size)
{
    vector <vector <int>> vec;
    cout << "\nInput elements for new matrix:\n";

    for (int i = 0; i < size; i++)
    {
        vector<int> myvector(size, 0);
        for (int j = 0; j < size; j++)
        {
            if (i <= j) 
            {
               int newenum;
               cin >> newenum;
               myvector[j] = newenum;
            } 
        }
        vec.push_back(myvector);
    }
    return vec;
}

vector <int> VectorSet2(int size)
{
    vector <int> vec(size, 0);
    cout << "\nInput elements for new vector:\n";
    for (int i = 0; i < size; i++)
    {
        int newenum;
        cin >> newenum;
        vec[i] = newenum;
    }
    return vec;
}

vector <vector <int>> Question(vector <vector <int>>& mat_main, vector <vector <int>>& mat_res)
{
    int question;
    cout << "\n\nDo you want to make the result mareix the main one?\n1 - yes\nOther number - no\n";
    cin >> question;
    if (question == 1) { return mat_res; }
    else { return mat_main; }    
}

int main()
{
    int size;
    int mode = 0;
    vector <vector <int>> matrix1;

    cout << " Input size for matrix: ";
    cin >> size;	

    for (int i = 0; i < size; i++)
    {
        vector<int> myvector(size, 0);
        for (int j = 0; j < size; j++) { if (i <= j) { myvector[j] = j + 1; } }
        matrix1.push_back(myvector);
    }
  
    do 
    {
        cout << "\nMain Triangular matrix ";
        PrintVector(matrix1);

        menu();
        cout << "Input mode: ";
        cin >> mode;

        switch (mode)
        {
        case 1:
        {
            int newsize;
            cout << "\nInput size for your new matrix";
            cin >> newsize;
            matrix1 = VectorSet(newsize);
            cout << "\nYour new matrix";
            PrintVector(matrix1);
            break;
        }

        case 2:
        {
            vector <vector <int>> matrix2;
            vector <vector <int>> matrix_result(matrix1.size(), vector <int>(matrix1.size(), 0));
            cout << "\nCreate a new mtrix wth which you will compare the existing one";
            matrix2 = VectorSet(matrix1.size());

            for (int i = 0; i < matrix1[1].size(); i++)
            {
                for (int j = 0; j < matrix1[1].size(); j++) {
                    matrix_result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }

            cout << "\nMatrix - result";
            PrintVector(matrix_result);

            matrix1 = Question(matrix1, matrix_result);

            break;
        }

        case 3:
        {
            vector <vector <int>> matrix2;
            vector <vector <int>> matrix_result(matrix1.size(), vector <int>(matrix1.size(), 0));
            cout << "\nCreate a new mtrix wth which you will subtract from main matrix";
            matrix2 = VectorSet(matrix1.size());

            for (int i = 0; i < matrix1[1].size(); i++)
            {
                for (int j = 0; j < matrix1[1].size(); j++) {
                    matrix_result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }

            cout << "\nMatrix - result";
            PrintVector(matrix_result);
            matrix1 = Question(matrix1, matrix_result);
            break;
        }

        case 4:
        {
            vector <int> vector1;
            vector <vector <int>> matrix_result(matrix1.size(), vector <int>(matrix1.size(), 0));
            cout << "\nCreate a vector which main matrix will be multuplied";
            vector1 = VectorSet2(matrix1.size());
            
            for (int i = 0; i < matrix1.size(); i++)
            {
                for (int j = 0; j < matrix1.size(); j++) {
                    matrix_result[i][j] = matrix1[i][j] * vector1[i];
                }
            }
            cout << "\nMatrix - result";
            PrintVector(matrix_result);
            matrix1 = Question(matrix1, matrix_result);
            break;
        }

        case 5:
        {
            vector <vector <int>> matrix2;
            vector <vector <int>> matrix_result(matrix1.size(), vector <int> (matrix1.size(), 0));
            cout << "\nCreate a new matrix which main matrix will be multuplied";
            matrix2 = VectorSet(matrix1.size());          

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    for (int k = 0; k < size; k++)
                        matrix_result[i][j] += matrix1[i][j] * matrix2[k][j];
            }
            cout << "\nMatrix - result";
            PrintVector(matrix_result);
            matrix1 = Question(matrix1, matrix_result);
            break;
        }

        case 6:
        {
            vector <vector <int>> matrix2 = matrix1;
            for (int i = 0; i < matrix1.size(); i++)
            {
                for (int j = 0; j < matrix1.size(); j++) {
                    matrix1[j][i] = matrix2[i][j];
                }
            }
            cout << "\nMatrix - result";
            PrintVector(matrix1);
            break;
        }

        case 7:
        {
            cout << "\n\n\t\t\tGood bye! see you :)";
            break;
        }

        default:
            cout << "\n\nERROR! There is no such mode\n\n";
            break;
        }
    } while (mode != 7);



	return 0;
}