#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

ll friends_pairing(ll n)
{
    vll dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (ll i = 2; i <= n; i++)
    {
        ll no_of_ways_ith_person_is_single = dp[i - 1];
        ll no_of_ways_ith_person_pairs_up = (i - 1) * dp[i - 2]; // since there are (i-1) possibilities to pair up and remaining people left for pairing is (i-2)
        dp[i] = no_of_ways_ith_person_is_single + no_of_ways_ith_person_pairs_up;
    }

    return dp[n];
}

int main()
{
    ll n;
    cin >> n;

    ll ans = friends_pairing(n);
    cout << ans << "\n";

    return 0;
}

/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only
once. Find out the total number of ways in which friends can remain single or can be paired up.

Ex: N=3, then pairs can be:
[{1}, {2}, {3}], [{1,2}, {3}], [{1,3}, {2}], [{1}, {2,3}] -> 4

Sample Input1:
4

Sample Output1:
10


*/