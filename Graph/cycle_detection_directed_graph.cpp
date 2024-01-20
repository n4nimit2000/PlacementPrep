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

    bool check_contains_cycle(ll node, vector<bool> &visited, vector<bool> &pathVisited)
    {
        visited[node] = pathVisited[node] = true;

        for (auto neigh : edges[node])
        {
            if (pathVisited[neigh])
                return true;
            else if (!visited[neigh])
            {
                if (check_contains_cycle(neigh, visited, pathVisited))
                    return true;
            }
        }

        pathVisited[node] = false;

        return false;
    }
};

void contains_cycle(Graph &graph)
{
    int n = graph.get_number_of_nodes();
    vector<bool> visited(n, false), pathVisited(n, false);

    for (int node = 0; node < n; node++)
    {
        if (!visited[node])
        {
            if (graph.check_contains_cycle(node, visited, pathVisited))
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

Ref: https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=19&ab_channel=takeUforward

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