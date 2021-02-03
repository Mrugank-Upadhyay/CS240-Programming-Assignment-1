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

// Split function to split the array A as evenly as possible
vector<vector<int>> split(const vector<int> &A, int k)
{
    // Vector to output the list of subarrays
    vector<vector<int>> T;
    int n = A.size();
    int q = n / k;
    int r = n % k;
    int idx = 0;
    // Loop through the first A0 to A_r-1 arrays to be of size q+1
    for (int i = 0; i < r; i++) {
        vector<int> Ai = vector<int>(q + 1, 0);
        for (int j = 0; j <= q; j++) {
            Ai[j] = A[idx];
            idx++;
        }
        T.push_back(Ai);
    }

    // Loop through the remaining to be of size q
    for (int i = r; i < k; i++) {
        vector<int> Ai = vector<int>(q, 0);
        for (int j = 0; j < q; j++) {
            Ai[j] = A[idx];
            idx++;
        }
        T.push_back(Ai);
    }
    return T;
}

int ArgMin(vector<pair<int, int>> &M)
{
    int l = 0;
    int len = M.size();
    for (int i = 0; i < len; i++)
    {
        if (M[i].first < M[l].first) {
            l = i;
        }
    }

    return l;
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
    for (int i = 0; i < k; i++)
    {
        int size = Aj[i].size();
        n += size;
        N.push_back(size);
    }
    // Array of length n
    vector<int> A = vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> M;
        for (int j = 0; j < k; j++)
        {
            if (I[j] < N[j])
            {
                M.push_back(pair<int, int>(Aj[j][I[j]], j));
            }
        }

        int l = ArgMin(M);
        int j = M[l].second;
        A[i] = Aj[j][I[j]];
        I[j] = I[j] + 1;
    }

    return A;
}

void kWayMergeSort(vector<int> &A, int k)
{
    int len = A.size();
    if (len <= 1)
    {
        return;
    }

    // We first split our main array into k parts
    auto T = split(A, k);
    len = T.size();
    for (int i = 0; i < len; i++)
    {
        kWayMergeSort(T[i], k);
    }

    A = kWayMerge(T);
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