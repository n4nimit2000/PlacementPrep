#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define inf LLONG_MAX

ll n = 4;
ll dist[10][10] = {{0, 20, 42, 25}, {20, 0, 30, 34}, {42, 30, 0, 10}, {25, 34, 10, 0}};

ll visited_all = (1 << n) - 1;

ll travelling_salesman_problem(ll mask, ll position, vector<vll> &dp)
{
    if (mask == visited_all)
    {
        return dist[position][0];
    }

    if (dp[mask][position] != -1)
    {
        return dp[mask][position];
    }

    ll ans = inf;
    for (ll city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0) // Not yet visited
        {
            ll cur = dist[position][city] + travelling_salesman_problem(mask | (1 << city), city, dp);
            ans = min(cur, ans);
        }
    }

    return dp[mask][position] = ans;
}

int main()
{
    vector<vll> dp((1 << n), vll(n, -1));

    ll min_weight_hamiltonian_path = travelling_salesman_problem(1, 0, dp);

    cout << "Minimum weight hamiltonian path costs " << min_weight_hamiltonian_path << "\n";

    return 0;
}

/*
Given a set of cities and the distance between every pair of cities, the problem is to find the
shortest possible route that visits every city exactly once and returns to the starting point.
Note the difference between Hamiltonian Cycle and TSP. The Hamiltonian cycle problem is to find
if there exists a tour that visits every city exactly once.

Time complexity = O((n^2) * (2^n))

*/