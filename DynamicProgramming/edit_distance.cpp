#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int recur(int n, int m, string &a, string &b, vector<vector<int>> &dp)
{
    if (n < 0)
        return m + 1;
    if (m < 0)
        return n + 1;
    if (dp[n][m] != -1)
        return dp[n][m];

    int res = INT_MAX;
    if (a[n] == b[m])
    {
        res = recur(n - 1, m - 1, a, b, dp);
    }
    else
    {
        res = min({res,
                   recur(n, m - 1, a, b, dp) + 1,       // insert in a
                   recur(n - 1, m, a, b, dp) + 1,       // delete from a
                   recur(n - 1, m - 1, a, b, dp) + 1}); // replace in a
    }

    return dp[n][m] = res;
}

// Time Complexity = O(N * M), Space Complexity = O(N * M)
int solveUsingRecursion(string word1, string word2)
{
    int n = word1.size(), m = word2.size();
    vector<vi> dp(n, vi(m, -1));
    return recur(n - 1, m - 1, word1, word2, dp);
}

// Time Complexity = O(N * M), Space Complexity = O(N * M)
int solveUsingBottomUpDP(string word1, string word2)
{
    int n = word1.size(), m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[0][j] = j;
                continue;
            }
            if (j == 0)
            {
                dp[i][0] = i;
                continue;
            }

            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    return dp[n][m];
}

// Time Complexity = O(N * M), Space Complexity = O(M)
int solveUsingBottomUpDPSpaceOptimized(string word1, string word2)
{
    int n = word1.size(), m = word2.size();

    vector<int> prev(m + 1), cur(m + 1);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                cur[j] = j;
                continue;
            }
            if (j == 0)
            {
                cur[0] = i;
                continue;
            }

            if (word1[i - 1] == word2[j - 1])
            {
                cur[j] = prev[j - 1];
            }
            else
            {
                cur[j] = min({prev[j], cur[j - 1], prev[j - 1]}) + 1;
            }
        }
        prev = cur;
    }

    return cur[m];
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    cout << "Solved using Recursion: " << solveUsingRecursion(word1, word2) << "\n";
    cout << "Solved using Bottom up DP: " << solveUsingBottomUpDP(word1, word2) << "\n";
    cout << "Solved using Bottom up DP (space optimized): " << solveUsingBottomUpDPSpaceOptimized(word1, word2) << "\n";

    return 0;
}

/*

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character

Sample Input:
horse
ros

Sample Output:
3


Ref: https://leetcode.com/problems/edit-distance/description/

*/