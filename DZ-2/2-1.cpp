// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    cout << "Введите вектор через пробелы:\n" ;
    
    // Собственно вектор v
    vector <double> v;
    string tmp;
    
    getline(cin, tmp);
    tmp += ' ';

    cout << endl;

    while (tmp.length() > 0)
    {
        string str = tmp.substr(0, tmp.find(' '));
        tmp.erase(0, tmp.find(' ') + 1);
        double tmp_num = stod(str);
        v.push_back(tmp_num);
    }

    // Размерность базиса n
    int n = v.size();

    // Тензор P = квадратная матрица со стороной n
    vector <vector <double> > P(n);

    cout << "Введите тензор в виде матрицы:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double tmp;
            cin >> tmp;
            P[i].push_back(tmp);
        }
    }

    cout << endl;

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << P[i][j] << ' ';
        }
        cout << endl;
    }*/

    // Новый вектор = результат произведения P * v
    vector <double> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i] += P[i][j] * v[j];
        }
    }

    cout << "Результат операции:\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
