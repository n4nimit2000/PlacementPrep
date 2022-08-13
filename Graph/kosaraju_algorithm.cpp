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

    void dfs(ll node, vector<bool> &visited, vll &stack)
    {
        visited[node] = true;
        for (auto neigh : edges[node])
        {
            if (!visited[neigh])
            {
                dfs(neigh, visited, stack);
            }
        }

        stack.pb(node);
    }

    void dfs2(vector<vll> &rev_edges, ll node, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto neigh : rev_edges[node])
        {
            if (!visited[neigh])
            {
                dfs2(rev_edges, neigh, visited);
            }
        }

        cout << node << " ";
    }

    void kosaraju_algorithm()
    {
        vector<bool> visited(n, false);
        vll stack;

        for (int node = 0; node < n; node++)
        {
            if (!visited[node])
            {
                dfs(node, visited, stack);
            }
        }

        vector<vll> rev_edges(n);
        for (int node = 0; node < n; node++)
        {
            for (auto neigh : edges[node])
            {
                rev_edges[neigh].pb(node);
            }
        }

        visited.clear();
        visited.resize(n, false);

        char component = 'A';
        for (int i = stack.size() - 1; i >= 0; i--)
        {
            int node = stack[i];
            if (!visited[node])
            {
                cout << "Component " << component << " -> ";
                dfs2(rev_edges, node, visited);

                component++;
                cout << "\n";
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

        graph.create_edge(u, v, true);
    }

    graph.kosaraju_algorithm();
}

/*
Find all strongly connected components (Kosaraju Algorithm).
A directed graph is strongly connected if there is a path between all pairs of vertices.
Time Complexity = O(N + E)

Sample Input:
5 5
1 0
0 2
2 1
0 3
3 4

Sample Output:
0 1 2
3
4

*/