// 3-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

vector <int> v;

void merge(int left = 0, int right = v.size()-1)
{
    if (left == right)
        return;
    if (right - left == 1)
    {
        if (v[left] > v[right])
            swap(v[left], v[right]);
        return;
    }
    
    int mid = (left + right) / 2;

    merge(left, mid);
    merge(mid + 1, right);

    vector <int> res;

    int it1 = left;
    int it2 = mid + 1;

    while ((it1 <= mid) || (it2 <= right))
    {
        if (it1 > mid)
        {
            res.push_back(v[it2]);
            it2++;
            continue;
        }
        if (it2 > right)
        {
            res.push_back(v[it1]);
            it1++;
            continue;
        }

        if (v[it1] < v[it2])
        {
            res.push_back(v[it1]);
            it1++;
            continue;
        }
        else
        {
            res.push_back(v[it2]);
            it2++;
            continue;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        v[left + i] = res[i];
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите массив через пробелы:\n";
    string s;
    getline(cin, s);

    s += ' ';

    while (s.length() > 0)
    {
        string tmp = s.substr(0, s.find(' '));
        s.erase(0, s.find(' ') + 1);
        v.push_back(stoi(tmp));
    }

    int n = v.size();

    merge();

    cout << "Отсортированный массив:\n";

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }

    cout << '\n';

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
