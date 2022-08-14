#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<int> table;
void preprocess(string pat)
{
    int i = 0, j = -1;
    table.push_back(-1);

    while (i < pat.size())
    {
        while (j >= 0 && pat[i] != pat[j])
        {
            j = table[j];
        }
        i++, j++;

        table.push_back(j);
    }
}

int kmp_algorithm(string pat, string s)
{
    preprocess(pat);

    int i = 0, j = 0, ans = 0;
    while (i < s.size())
    {
        while (j >= 0 && s[i] != pat[j])
        {
            j = table[j];
        }
        i++, j++;

        if (j == pat.size())
        {
            ans++;
            j = table[j];
        }
    }

    return ans;
}

int main()
{
    string s, pat;
    cin >> s >> pat;

    int ans = kmp_algorithm(pat, s);
    cout << ans << "\n";
    return 0;
}

/*
Given a string 's' and a pattern 'pat', write a function that counts all the occurences of 'pat' in 's'.
We do a preprocessing where we create LPS(Longest Prefix with is also a Suffix) table.
Time complexity = O(N)  -> N is length of 's'
Space complexity = O(M)

Sample Input:
AABAACAADAABAABA
AABA

Sample Output:
3

*/