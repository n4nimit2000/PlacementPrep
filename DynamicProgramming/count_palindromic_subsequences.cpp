#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

ll helper(ll i, ll j, string &s, vector<vll> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = helper(i + 1, j, s, dp) + helper(i, j - 1, s, dp) + 1;
    else
        return dp[i][j] = helper(i + 1, j, s, dp) + helper(i, j - 1, s, dp) - helper(i + 1, j - 1, s, dp);
}

ll get_number_of_palindromic_subsequences(string s)
{
    ll n = s.size();
    vector<vll> dp(n, vll(n, -1));

    return helper(0, n - 1, s, dp);
}

int main()
{
    string s;
    cin >> s;

    ll number_of_palindromic_subsequences = get_number_of_palindromic_subsequences(s);

    cout << "Number of palindromic subsequeces is " << number_of_palindromic_subsequences << "\n";

    return 0;
}

/*
Find the number of palindromic subsequences (need not necessarily be distinct) that can be formed in a given string.
Ex:
string = aab
Outpu: 4  -> [a, a, aa, b]

Time complexity = O(N^2)
Space complexity = O(N^2)


Sample Input:
abcb

Sample Output:
Number of palindromic subsequeces is 6
*/