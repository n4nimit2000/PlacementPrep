#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define pb push_back
#define F(i, a, b) for (ll i = a; i < b; i++)

class Graph
{
    ll n, e;
    vector<vll> edges;

public:
    Graph(ll number_of_nodes, ll number_of_edges)
    {
        n = number_of_nodes;
        e = number_of_edges;
        edges.resize(n);
    }

    ll get_number_of_nodes()
    {
        return n;
    }

    void create_edge(ll u, ll v, bool isDirected = false)
    {
        edges[u].pb(v);

        if (!isDirected)
        {
            edges[v].pb(u);
        }
    }

    bool check_contains_cycle(ll node, vector<bool> &visited, vector<bool> &stack)
    {
        visited[node] = stack[node] = true;

        for (auto neigh : edges[node])
        {
            if (stack[neigh])
                return true;
            else if (!visited[neigh])
            {
                if (check_contains_cycle(neigh, visited, stack))
                    return true;
            }
        }

        stack[node] = false;

        return false;
    }
};

void contains_cycle(Graph &graph)
{
    int n = graph.get_number_of_nodes();
    vector<bool> visited(n, false), stack(n, false);

    for (int node = 0; node < n; node++)
    {
        if (!visited[node])
        {
            if (graph.check_contains_cycle(node, visited, stack))
            {
                cout << "Contains cycle\n";
                return;
            }
        }
    }

    cout << "Does not contain cycle\n";
}

int main()
{
    ll n, e;
    cin >> n >> e;

    Graph graph(n, e);

    F(i, 0, e)
    {
        ll u, v;
        cin >> u >> v;

        graph.create_edge(u, v, true);
    }

    contains_cycle(graph);
}

/*
Check if the given directed graph contains a cycle.

Sample Input:
4 5
0 1
1 2
0 2
2 3
2 0

Sample Output:
Contains cycle

*/