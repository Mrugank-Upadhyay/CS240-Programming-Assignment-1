#include <utility>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
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
    int s = int(std::ceil(double(len) / double(k)));
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

int ArgMin(vector<pair<vector<int>, int>> &M)
{
    int min = 0;
    int len = M.size();
    for (int i = 0; i < len; i++)
    {
        if (M[i].first <)
    }
}

//-------------------------------------------------//
// k-way merge implemented as in the assignment    //
// if all Aj's are sorted, the output must be      //
// sorted as well                                  //
//-------------------------------------------------//
vector<int> kWayMerge(const vector<vector<int>> &Aj)
{
    int k = Aj.size();
    vector<int> I = vector<int>(k, 0);
    // Holds the lengths of each sub array
    vector<int> N;
    // combined size of all sub arrays: n = n1 + ... + nk
    int n = 0;
    for (auto subArray : Aj)
    {
        int size = subArray.size();
        n += size;
        N.push_back(size);
    }
    // Array of length n
    vector<vector<int>> A = vector<vector<int>>(n);

    for (int i = 0; i < n; i++)
    {
        vector<pair<vector<int>, int>> M;
        for (int j = 0; j < k; j++)
        {
            if (I[j] != N[j])
            {
                M.push_back(pair<vector<int>, int>(Aj[I[j]], j));
            }
        }

        int l = ArgMin(M);
        int j = M[l].second;
        A[i] = Aj[I[j]];
        I[j]++;
    }
}

void kWayMergeSort(vector<int> &A, int k)
{
    int len = A.size();
    if (len == 1)
    {
        return;
    }

    // We first split our main array into k parts
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