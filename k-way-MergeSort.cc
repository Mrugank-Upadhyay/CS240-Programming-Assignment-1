#include <utility>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath.h>
using namespace std;

void print(std::vector<int> const &a)
{
    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << " ";
    cout << endl;
}

vector<vector<int>> split(const vector<int> &A, int k)
{
    int len = A.size();
    int s = int(std::ceil(len / k));
    vector<vector<int>> T;
    for (int i = 0; i < len;)
    {
        if (i + s >= len)
        {
            vector<int> SubArray;
            for (int j = i; j < len; j++)
            {
                SubArray[j - i] = A[j];
            }
            T.push_back(SubArray);
        }

        else
        {
            vector<int> SubArray;
            for (int j = i; j < i + s - 1; j++)
            {
                SubArray[j - i] = A[j];
            }
            T.push_back(SubArray);
        }

        i += s;
    }

    return T;
}

//-------------------------------------------------//
// k-way merge implemented as in the assignment    //
// if all Aj's are sorted, the output must be      //
// sorted as well                                  //
//-------------------------------------------------//
vector<int> kWayMerge(const vector<vector<int>> &Aj)
{
}

void kWayMergeSort(vector<int> &A, int k)
{
    int len = A.size();
    if (len == 1)
    {
        return;
    }

    auto T = split(A, k);
    for (auto subArray : T)
    {
        kWayMergeSort(subArray, k);
    }

    kWayMerge(T);
}

#ifndef TESTING
int main()
{
    string line;
    getline(cin, line);
    std::vector<int> A;
    int k = atoi(line.c_str());

    while (true)
    {
        string line;
        if (!getline(cin, line))
            break;
        int a = atoi(line.c_str());
        A.push_back(a);
    }

    print(A);
    kWayMergeSort(A, k);
    print(A);
}
#endif