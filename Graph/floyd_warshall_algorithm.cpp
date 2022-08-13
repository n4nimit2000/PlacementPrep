#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define pb push_back
#define F(i, a, b) for (ll i = a; i < b; i++)
#define inf LLONG_MAX

int main()
{
    ll n, e;
    cin >> n >> e;

    vector<vll> dist(n, vll(n, inf));

    F(i, 0, e)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;

        dist[u][v] = wt;
    }

    F(i, 0, n)
    dist[i][i] = 0;

    F(k, 0, n)
    {
        F(i, 0, n)
        {
            F(j, 0, n)
            {
                if (dist[i][k] != inf && dist[k][j] != inf)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Check for negative weight cycle
    F(i, 0, n)
    {
        if (dist[i][i] < 0)
        {
            cout << "Negative weight cycle!\n";
            return 0;
        }
    }

    F(i, 0, n)
    {
        F(j, 0, n)
        {
            if (dist[i][j] != inf)
                cout << dist[i][j] << " ";
            else
                cout << "INF ";
        }
        cout << "\n";
    }
}

/*
Floyd Warshall Algorithm: All pair shortest path algorithm.
Works with negative edges and can detect negative cycles with one extra step.
Time Complexity: O(N^3)
Space Complexity: O(N^2)

Sample Input:
4 4
0 1 5
1 2 3
2 3 1
0 3 10

Sample Output:
0 5 8 9 
INF 0 3 4
INF INF 0 1
INF INF INF 0

*/