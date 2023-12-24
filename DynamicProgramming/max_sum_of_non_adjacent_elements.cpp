#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define vll vector<ll>

/**
 * Time complexity = O(N), Space Complexity = O(1)
 **/
ll getSolutionWithSpaceOptimization(vll &ar, int n)
{
    ll inc = ar[0], exc = 0;
    for (int i = 1; i < n; i++)
    {
        ll tmp = max(inc, exc);
        inc = exc + ar[i];
        exc = tmp;
    }

    return max(inc, exc);
}

/**
 * Time complexity = O(N), Space Complexity = O(N)
 **/
ll getSolutionUsingDP(vll &ar, int n)
{
    if (n == 1)
        return ar[0];
    if (n == 2)
        return max(ar[0], ar[1]);

    vll dp(n);
    dp[0] = ar[0], dp[1] = max(ar[0], ar[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + ar[i]);
    }

    return dp[n - 1];
}

void solve()
{
    ll n;
    cin >> n;
    vll ar(n);
    for (auto &x : ar)
        cin >> x;

    cout << "\n";
    cout << "Answer using DP: " << getSolutionUsingDP(ar, n) << "\n";
    cout << "Answer with Space Optimization: " << getSolutionWithSpaceOptimization(ar, n) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}

/*

Given an array arr[] of positive numbers, The task is to find the maximum sum of a subsequence such
that no 2 numbers in the sequence should be adjacent in the array.

Sample Input:
3
4
1 2 3 1
5
2 7 9 3 1
8
1 2 3 6 8 2 9 1

Sample Output:
4
12
21

Ref: https://leetcode.com/problems/house-robber/description/

*/
