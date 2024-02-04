#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

// Time Complexity = O(N^3), Space Complexity = O(N^2)
int getMinCost(int start, int end, vi &ar, vector<vector<int>> &dp)
{
    if (start >= end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];

    int ans = INT_MAX;
    for (int k = start; k < end; k++)
    {
        int cost = ar[start - 1] * ar[k] * ar[end];
        ans = min(ans, getMinCost(start, k, ar, dp) + getMinCost(k + 1, end, ar, dp) + cost);
    }

    return dp[start][end] = ans;
}

int matrixMultiplication(vi &ar, int &n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return getMinCost(1, n - 1, ar, dp);
}

int main()
{
    int n;
    cin >> n;
    vi ar(n);
    for (auto &x : ar)
        cin >> x;

    cout << matrixMultiplication(ar, n);
    return 0;
}

/*

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Sample Input:
5
40 20 30 10 30

Sample Output:
26000

Ref: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

Video Tutorial: https://www.youtube.com/watch?v=vRVfmbCFW7Y&t=2859s&ab_channel=takeUforward

*/