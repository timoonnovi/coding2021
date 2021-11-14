// 9-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

template<typename T>
void merge(std::vector<T>& v, int left, int right)
{
    if (left == right)
        return;
    if (right - left == 1)
    {
        if (v[left] > v[right])
            std::swap(v[left], v[right]);
        return;
    }

    int mid = (left + right) / 2;

    merge(v, left, mid);
    merge(v, mid + 1, right);

    std::vector <T> res;

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
    std::cout << "Input number of array elements:\n";
    int n;
    std::cin >> n;
    std::vector<std::string> v;
    v.resize(n);
    std::cout << "Input an array:\n";
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }

    merge(v, 0, v.size() - 1);

    std::cout << "Sorted array:\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << ' ';
    }

    std::cout << '\n';

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
