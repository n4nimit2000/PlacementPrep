#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

string longest_palindromic_substring(string s)
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

    cout << "Longest Palindromic Substring: " << longest_palindromic_substring(s) << "\n";

    return 0;
}

/*
Given a string s, return the longest palindromic substring in s.
Time complexity = O(n^2)
Space complexity = O(n^2)

Sample Input:
forgeeksskeegfor

Sample Output:
Longest Palindromic Substring: geeksskeeg

*/