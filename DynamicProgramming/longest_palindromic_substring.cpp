#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

/**
 * Time Complexity = O(N^2), Space Complexity = O(1)
 **/
string longest_palindromic_substring_without_dp(string s)
{
    ll n = s.size();
    if (n == 0)
    {
        return "";
    }

    ll max_len = 1, start_ind = 0;
    for (int mid = 0; mid < n; mid++)
    {
        ll dis = 1, len = 1, tmp_start = 0;
        // To get odd length palindrome
        while (mid - dis >= 0 && mid + dis < n)
        {
            if (s[mid - dis] == s[mid + dis])
            {
                tmp_start = mid - dis;
                dis++;
                len += 2;

                if (len > max_len)
                {
                    max_len = len;
                    start_ind = tmp_start;
                }
            }
            else
            {
                break;
            }
        }

        dis = 0, len = 0;
        // To get even length palindrome
        while (mid - dis >= 0 && mid + 1 + dis < n)
        {
            if (s[mid - dis] == s[mid + 1 + dis])
            {
                tmp_start = mid - dis;
                dis++;
                len += 2;

                if (len > max_len)
                {
                    max_len = len;
                    start_ind = tmp_start;
                }
            }
            else
            {
                break;
            }
        }
    }

    return s.substr(start_ind, max_len);
}

/**
 * Time Complexity = O(N^2), Space Complexity = O(N^2)
 **/
string longest_palindromic_substring_using_dp(string s)
{
    ll n = s.size();
    if (n == 0)
    {
        return "";
    }

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    ll maxlen = 0, start_index = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = true;
            else if (j == i + 1)
                dp[i][j] = (s[i] == s[j]);
            else
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);

            if (dp[i][j] && (j - i + 1) > maxlen)
            {
                maxlen = j - i + 1;
                start_index = i;
            }
        }
    }

    return s.substr(start_index, maxlen);
}

int main()
{
    string s;
    cin >> s;

    cout << "Longest Palindromic Substring using DP: " << longest_palindromic_substring_using_dp(s) << "\n";
    cout << "Longest Palindromic Substring without DP: " << longest_palindromic_substring_without_dp(s) << "\n";

    return 0;
}

/*
Given a string s, return the longest palindromic substring in s.

Sample Input:
forgeeksskeegfor

Sample Output:
Longest Palindromic Substring: geeksskeeg

Sample Problems:
 - https://leetcode.com/problems/longest-palindromic-substring
 - https://leetcode.com/problems/palindromic-substrings

*/