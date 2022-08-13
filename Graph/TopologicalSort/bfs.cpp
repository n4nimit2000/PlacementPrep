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

    void topological_sort_using_bfs()
    {
        vll indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto node : edges[i])
            {
                indegree[node]++;
            }
        }

        queue<ll> q;
        for (int node = 0; node < n; node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        cout << "Topological Sort: ";
        while (q.size())
        {
            ll node = q.front();
            cout << node << " ";
            q.pop();

            for (auto child : edges[node])
            {
                indegree[child]--;
                if (indegree[child] == 0)
                {
                    q.push(child);
                }
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

    graph.topological_sort_using_bfs();
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
4 5 2 0 3 1

*/