#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define inf LLONG_MAX

ll print_solution(vll &ar, ll n)
{
    ll pos = 0;

    if (ar[n] == 1)
        pos = 1;
    else
        pos = print_solution(ar, ar[n] - 1) + 1;

    cout << "Line number " << pos << " -> from word number " << ar[n] << " to " << n << "\n";

    return pos;
}

void word_wrap_problem(vll &l, ll n, ll m)
{
    /*
    To calculate the number of extra spaces in each line.
    extra[i][j] represents the number of extra spaces, if we place words from the word number i to j in a single line.
    */
    vector<vll> extra(n + 1, vll(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        extra[i][i] = m - l[i - 1];
        for (int j = i + 1; j <= n; j++)
        {
            extra[i][j] = extra[i][j - 1] - l[j - 1] - 1;
        }
    }

    /*
    The value of cost[i][j] indicates the cost of putting words from word number i to j in a single line.
    */
    vector<vll> cost(n + 1, vll(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (extra[i][j] < 0)
            {
                // Not possible to find the words i to j in a line
                cost[i][j] = inf;
            }
            else if (j == n)
            {
                // Since its the last word, no cost involved
                cost[i][j] = 0;
            }
            else
            {
                cost[i][j] = extra[i][j] * extra[i][j];
            }
        }
    }

    /*
    Calculating the minimum cost and minimum cost arrangement.
    Value of dp[i] indicates the optimized cost to arrange words from word number 1 to i
    */
    vll dp(n + 1);
    vll line(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = inf;
        for (int j = 1; j <= i; j++)
        {
            if (dp[j - 1] != inf && cost[j][i] != inf && dp[j - 1] + cost[j][i] < dp[i])
            {
                dp[i] = dp[j - 1] + cost[j][i];
                line[i] = j;
            }
        }
    }

    // Printing optimal solution using recursion
    print_solution(line, n);
}

int main()
{
    ll n; // number of words
    cin >> n;

    vll l(n); // length of each word
    for (int i = 0; i < n; i++)
        cin >> l[i];

    ll m; // length of a single line
    cin >> m;

    word_wrap_problem(l, n, m);

    return 0;
}

/*
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width).
Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each
word is smaller than the line width.
The extra spaces includes spaces put at the end of every line except the last one.
The problem is to minimize the following total cost.
 Cost of a line = (Number of extra spaces in the line)^2
 Total Cost = Sum of costs for all lines

Time complexity = O(n^2)
Space complexity = O(n^2)

Input:
n -> number of words
m -> length of a line
l[] -> length of each word


Sample Input:
4
3 2 2 5
6

Sample Output:


*/