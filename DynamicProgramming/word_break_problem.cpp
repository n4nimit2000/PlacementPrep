#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

ll get_number_of_sentences(string &s, unordered_set<string> &dict)
{
    ll n = s.size();
    vll dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        string suf = "";
        for (int j = i - 1; j >= 0; j--)
        {
            suf = s[j] + suf;
            if (dp[j] != 0 && dict.find(suf) != dict.end())
            {
                dp[i] += dp[j];
            }
        }
    }

    return dp[n];
}

int main()
{
    ll m;
    cin >> m;

    unordered_set<string> dictionary;
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    string s;
    cin >> s;

    ll number_of_sentences = get_number_of_sentences(s, dictionary);

    if (number_of_sentences == 0)
    {
        cout << "Not possible to break the string into sentences\n";
    }
    else
    {
        cout << "Number of sentence is " << number_of_sentences << "\n";
    }

    return 0;
}

/*
Given an input string and a dictionary of words, find the number of sentence possible if the input string is
segmented into a space-separated sequence of dictionary words.
Ex:
dictionary = {a, ab, cde, d, de, bc, abcde}
string = abcde
Output: 3   -> abcde = {a + bc + de}, {ab + cde}, {abcde}

Time complexity = O(n^2)  -> n is the length of the string

Sample Input1:
13
mobile samsung sam sung man mango icecream and go i like ice cream
ilikeicecreamandmango

Sample Output1:
Number of sentence is 4

Sample Input2:
7
a ab cde d de bc abcde
abcde

Sample Output2:
Number of sentence is 3

*/