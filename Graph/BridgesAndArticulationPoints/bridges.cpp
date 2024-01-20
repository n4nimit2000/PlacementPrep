#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define pb push_back
#define ipair pair<ll, ll>
#define F(i, a, b) for (ll i = a; i < b; i++)

class Graph
{
    ll n, e;
    vector<vll> edges;

    vll time, low, vis;
    ll timer = 1;
    vector<ipair> bridges;

public:
    Graph(ll number_of_nodes, ll number_of_edges)
    {
        n = number_of_nodes;
        e = number_of_edges;
        edges.resize(n);
        time.resize(n);
        low.resize(n);
        vis.resize(n);
    }

    void create_edge(ll u, ll v, bool isDirected = false)
    {
        edges[u].pb(v);

        if (!isDirected)
        {
            edges[v].pb(u);
        }
    }

    void print_bridges()
    {
        cout << "Bridges: ";
        for (auto it : bridges)
        {
            cout << "{" << it.first << ", " << it.second << "} ";
        }
        cout << "\n";
    }

    void find_bridges(int cur, int par)
    {
        vis[cur] = 1;
        time[cur] = low[cur] = timer++;

        for (auto neigh : edges[cur])
        {
            if (neigh == par)
                continue;

            if (!vis[neigh])
            {
                find_bridges(neigh, cur);
            }

            low[cur] = min(low[cur], low[neigh]);
            if (time[cur] < low[neigh])
            {
                bridges.push_back({cur, neigh});
            }
        }
    }
};

int main()
{
    ll n, e;
    cin >> n >> e;

    Graph graph(n, e);

    F(i, 0, e)
    {
        ll u, v;
        cin >> u >> v;

        graph.create_edge(u, v);
    }

    graph.find_bridges(0, -1);

    graph.print_bridges();
}

/*
Bridges: An edge in an undirected connected graph is a bridge if removing it disconnects the graph.
Time Complexity: O(N + E)
Space Complexity: O(N)

Ref: https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=55&ab_channel=takeUforward

Sample Input1:
5 5
1 0
0 2
2 1
0 3
3 4

Sample Output1:
Bridges: {3, 4} {0, 3}

Sample Input2:
5 4
0 1
0 2
2 3
3 4

Sample Output2:
Bridges: {0, 1} {3, 4} {2, 3} {0, 2}


Sample Problems:
 - https://leetcode.com/problems/critical-connections-in-a-network

*/