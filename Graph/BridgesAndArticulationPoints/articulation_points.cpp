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
    set<ll> articulation_points;

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

    void print_articulation_points()
    {
        cout << "Articulation points: ";
        for (auto node : articulation_points)
            cout << node << " ";
        cout << "\n";
    }

    void find_articulation_points(int cur, int par)
    {
        vis[cur] = 1;
        time[cur] = low[cur] = timer++;

        int children = 0;

        for (auto neigh : edges[cur])
        {
            if (neigh == par)
                continue;

            if (!vis[neigh])
            {
                find_articulation_points(neigh, cur);

                low[cur] = min(low[cur], low[neigh]);
                if (time[cur] <= low[neigh] && par != -1)
                {
                    articulation_points.insert(cur);
                }
                children++;
            }
            else
            {
                low[cur] = min(low[cur], time[neigh]);
            }
        }

        if (children > 1 && par == -1)
        {
            articulation_points.insert(cur);
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

    graph.find_articulation_points(0, -1);

    graph.print_articulation_points();
}

/*
Articulation points: A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it (and edges through it)
disconnects the graph. Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network
into 2 or more components.
Time Complexity: O(N + E)
Space Complexity: O(N)

Ref: https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=56&ab_channel=takeUforward

Sample Input1:
5 5
1 0
0 2
2 1
0 3
3 4

Sample Output1:
Articulation points: 0 3

Sample Input2:
5 4
0 1
0 2
2 3
3 4

Sample Output2:
Articulation points: 0 2 3

*/