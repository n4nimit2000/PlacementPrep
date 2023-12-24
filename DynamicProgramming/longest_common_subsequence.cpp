#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define vll vector<ll>

/**
 * Time Complexity = O(N^2), Space Complexity = O(N)
 **/
ll getSolutionUsingSpaceOptimizedTabulation(string &a, string &b)
{
    int n = a.size(), m = b.size();

    vll prev(m + 1), cur(m + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                cur[j] = prev[j - 1] + 1;
            else
                cur[j] = max(cur[j - 1], prev[j]);
        }
        prev = cur;
    }

    return cur[m];
}

/**
 * Time Complexity = O(N^2), Space Complexity = O(N^2)
 **/
ll getSolutionUsingTabulation(string &a, string &b)
{
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][m];
}

ll getLCS(string &a, string &b, int n, int m, vector<vll> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n] == b[m])
    {
        return dp[n][m] = getLCS(a, b, n - 1, m - 1, dp) + 1LL;
    }
    else
    {
        return dp[n][m] = max(getLCS(a, b, n - 1, m, dp), getLCS(a, b, n, m - 1, dp));
    }
}

/**
 * Time Complexity = O(N^2), Space Complexity = O(N^2)
 **/
ll getSolutionUsingRecursion(string &a, string &b)
{
    ll n = a.size(), m = b.size();
    vector<vll> dp(n, vll(m, -1));
    return getLCS(a, b, n - 1, m - 1, dp);
}

void solve()
{
    string a, b;
    cin >> a >> b;

    cout << "\n";
    cout << "Solution using recursion: " << getSolutionUsingRecursion(a, b) << "\n";
    cout << "Solution using Bottom up DP: " << getSolutionUsingTabulation(a, b) << "\n";
    cout << "Solution using Bottom up DP with Space optimization: " << getSolutionUsingSpaceOptimizedTabulation(a, b) << "\n";
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

Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.
A common subsequence of two strings is a subsequence that is common to both strings.

Sample Input:
3
abcde ace
abc abc
abc def

Sample Output:
3
3
0

Ref: https://leetcode.com/problems/longest-common-subsequence/description/

Video Solution: https://www.youtube.com/watch?v=NPZn9jBrX8U&ab_channel=takeUforward

*/
