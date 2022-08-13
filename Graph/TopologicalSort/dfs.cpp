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

    void dfs(ll node, vector<bool> &visited, list<int> &sorted_list)
    {
        visited[node] = true;

        for (auto child : edges[node])
        {
            if (!visited[child])
            {
                dfs(child, visited, sorted_list);
            }
        }

        sorted_list.push_front(node);
    }
};

void topological_sort_using_dfs(Graph &graph)
{
    int n = graph.get_number_of_nodes();
    vector<bool> visited(n, false);
    list<int> sorted_list;

    for (int node = 0; node < n; node++)
    {
        if (!visited[node])
        {
            graph.dfs(node, visited, sorted_list);
        }
    }

    cout << "Topological sort: ";
    for (auto node : sorted_list)
    {
        cout << node << " ";
    }
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

    topological_sort_using_dfs(graph);
}

/*
Performing topological sort on a graph using DFS.
Time Complexity = O(N + E)
Space Complexity = O(N)

Sample Input:
6 6
5 2
5 0
4 0
4 1
2 3
3 1

Sample Output:
5 4 2 3 1 0

*/