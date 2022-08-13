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

    vll disc, low;
    ll timer = 1;
    set<ll> articulation_points;
    vector<ipair> bridges;

public:
    Graph(ll number_of_nodes, ll number_of_edges)
    {
        n = number_of_nodes;
        e = number_of_edges;
        edges.resize(n);
        disc.resize(n);
        low.resize(n);
    }

    void create_edge(ll u, ll v, bool isDirected = false)
    {
        edges[u].pb(v);

        if (!isDirected)
        {
            edges[v].pb(u);
        }
    }

    void print_bridges_and_articulation_points()
    {
        cout << "Articulation points: ";
        for (auto node : articulation_points)
            cout << node << " ";
        cout << "\n";

        cout << "Bridges: ";
        for (auto it : bridges)
        {
            cout << "{" << it.first << ", " << it.second << "} ";
        }
        cout << "\n";
    }

    void find_bridges_and_articulation_points(ll cur, ll par)
    {
        disc[cur] = low[cur] = timer++;
        int no_child = 0;

        for (auto child : edges[cur])
        {
            // Not visited
            if (disc[child] == 0)
            {
                find_bridges_and_articulation_points(child, cur);
                no_child++;
                low[cur] = min(low[cur], low[child]);

                // Articulation point
                if (par != -1 && low[child] >= disc[cur])
                {
                    articulation_points.insert(cur);
                }

                // Bridge
                if (low[child] > disc[cur])
                {
                    bridges.pb({cur, child});
                }
            }
            else if (child != par)
            {
                // Backedge
                low[cur] = min(low[cur], disc[child]);
            }
        }

        // For root node
        if (par == -1 && no_child >= 2)
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

    graph.find_bridges_and_articulation_points(0, -1);

    graph.print_bridges_and_articulation_points();
}

/*
Articulation points: A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it (and edges through it)
disconnects the graph. Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network
into 2 or more components.
Bridges: An edge in an undirected connected graph is a bridge if removing it disconnects the graph.
Time Complexity: O(N + E)
Space Complexity: O(N)

Sample Input1:
5 5
1 0
0 2
2 1
0 3
3 4

Sample Output1:
Articulation points: 0 3
Bridges: {3, 4} {0, 3}

Sample Input2:
5 4
0 1
0 2
2 3
3 4

Sample Output2:
Articulation points: 0 2 3
Bridges: {0, 1} {3, 4} {2, 3} {0, 2}

*/