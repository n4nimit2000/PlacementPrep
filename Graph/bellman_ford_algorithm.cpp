#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define sbits __builtin_popcount
#define fill(vect, n) fill(vect.begin(), vect.end(), n)
#define pb push_back
#define pf push_front
#define vi vector<int>
#define vll vector<ll>
#define F(i, a, b) for (ll i = a; i < b; i++)
#define Fr(i, a, b) for (ll i = a; i >= b; i--)
#define inf LLONG_MAX
#define ninf -1 * inf
#define maxv(v) *max_element(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define ipair pair<ll, ll>
#define all(vec) vec.begin(), vec.end()
#define mat(DT) vector<vector<DT>>
#define p_q_d(DT) priority_queue<DT>
#define p_q_a(DT) priority_queue<DT, vector<DT>, greater<DT>>
#define ps(x, y) fixed << setprecision(y) << x
#define mod 1000000007

class Graph
{
    ll n, e;
    vector<vll> edges;

public:
    Graph(ll number_of_nodes, ll number_of_edges)
    {
        n = number_of_nodes;
        e = number_of_edges;
    }

    void create_edge(ll u, ll v, ll wt)
    {
        edges.pb({u, v, wt});
    }

    vll bellman_ford(ll src)
    {
        vll distance(n, inf);
        distance[src] = 0;

        // Relax all the edges N-1 times
        for (int i = 0; i < n - 1; i++)
        {
            for (auto edge : edges)
            {
                ll u = edge[0], v = edge[1], wt = edge[2];
                if (distance[u] != inf && distance[u] + wt < distance[v])
                {
                    distance[v] = distance[u] + wt;
                }
            }
        }

        // check for negative weight cycle
        for (auto edge : edges)
        {
            ll u = edge[0], v = edge[1], wt = edge[2];
            if (distance[u] != inf && distance[u] + wt < distance[v])
            {
                cout << "Found negative weight cycle!\n";
                exit(0);
            }
        }

        return distance;
    }
};

int main()
{
    ll n, e;
    cin >> n >> e;

    Graph graph(n, e);

    F(i, 0, e)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;

        graph.create_edge(u, v, wt);
    }

    ll src;
    cin >> src;

    vll distance = graph.bellman_ford(src);

    for (int i = 0; i < distance.size(); i++)
    {
        cout << "Distance of node " << i << " from " << src << " is " << distance[i] << "\n";
    }
}

/*
Bellman Ford Algorithm: Single source shortest path for directed graphs containing negative weight edges.
Time Complexity = O(NE)

Ref: https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=41&ab_channel=takeUforward


Sample Input:
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0

Sample Output:
Distance of node 0 from 0 is 0
Distance of node 1 from 0 is -1
Distance of node 2 from 0 is 2
Distance of node 3 from 0 is -2
Distance of node 4 from 0 is 1


*/