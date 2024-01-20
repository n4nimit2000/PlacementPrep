#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define pf push_front
#define F(i, a, b) for (ll i = a; i < b; i++)
#define vll vector<ll>
#define inf LLONG_MAX
#define ipair pair<ll, ll>

class DSU
{
private:
    int n;
    vll parent, size;

public:
    DSU(int no_of_nodes)
    {
        n = no_of_nodes;
        size.resize(n, 1);
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    ll find(ll node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionBySize(ll u, ll v)
    {
        ll par_of_u = find(u), par_of_v = find(v);
        if (par_of_u == par_of_v)
            return;

        if (size[par_of_u] < size[par_of_v])
        {
            parent[par_of_u] = par_of_v;
            size[par_of_v] += size[par_of_u];
        }
        else
        {
            parent[par_of_v] = par_of_u;
            size[par_of_u] += size[par_of_v];
        }
    }
};

class Graph
{
    ll n, e, mst_wt;
    vector<vector<ipair>> edges;

public:
    Graph(ll number_of_nodes, ll number_of_edges)
    {
        n = number_of_nodes;
        e = number_of_edges;
        edges.resize(n);
        mst_wt = 0;
    }

    void create_edge(ll u, ll v, ll wt, bool isDirected = false)
    {
        edges[u].pb({v, wt});

        if (!isDirected)
        {
            edges[v].pb({u, wt});
        }
    }

    ll get_mst_weight()
    {
        return mst_wt;
    }

    vector<ipair> kruskals_algorithm()
    {
        vector<ipair> mst_edges;
        vector<vll> ed;

        for (int i = 0; i < n; i++)
        {
            for (auto it : edges[i])
            {
                ed.push_back({it.second, it.first, i});
            }
        }

        sort(ed.begin(), ed.end());
        DSU dsu(n);

        for (auto it : ed)
        {
            ll u = it[1], v = it[2], wt = it[0];
            if (dsu.find(u) != dsu.find(v))
            {
                mst_wt += wt;
                mst_edges.push_back({u, v});
                dsu.unionBySize(u, v);
            }
        }

        return mst_edges;
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

    vector<ipair> mst_edges = graph.kruskals_algorithm();

    cout << "Weight of MST: " << graph.get_mst_weight() << "\n";
    cout << "Edges in MST: ";
    for (auto ed : mst_edges)
    {
        cout << "(" << ed.first << ", " << ed.second << ") ";
    }
}

/*
Kruskal's Algorithm: Create Minimum Spanning Tree (MST) of the given graph
Time Complexity: O(ElogN)

Sample Input:
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

Sample Output:
Weight of MST: 37
Edges in MST: (6, 7) (2, 8) (5, 6) (0, 1) (2, 5) (2, 3) (0, 7) (3, 4)

*/
