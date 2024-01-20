#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define pf push_front
#define F(i, a, b) for (ll i = a; i < b; i++)
#define vll vector<ll>
#define inf LLONG_MAX
#define ipair pair<ll, ll>

class Edge
{
public:
    ll cur, par, wt;

    Edge(ll cur_node, ll par_node, ll weight)
    {
        cur = cur_node;
        par = par_node;
        wt = weight;
    }
};

class Compare
{
public:
    bool operator()(Edge ed1, Edge ed2)
    {
        return ed1.wt > ed2.wt;
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

    vector<ipair> prims_algorithm(ll src)
    {
        vll visited(n);
        vector<ipair> mst_edges;

        priority_queue<Edge, vector<Edge>, Compare> pq;
        pq.push(Edge(src, -1, 0));

        while (!pq.empty())
        {
            Edge cur_edge = pq.top();
            pq.pop();

            ll cur_node = cur_edge.cur;
            ll par_node = cur_edge.par;
            ll wt = cur_edge.wt;
            if (visited[cur_node])
                continue;

            // Create MST
            if (par_node != -1)
                mst_edges.push_back({cur_node, par_node});
            mst_wt += wt;
            visited[cur_node] = 1;

            for (auto neigh : edges[cur_node])
            {
                ll neigh_node = neigh.first, ed_weight = neigh.second;
                if (!visited[neigh_node])
                {
                    pq.push(Edge(neigh_node, cur_node, ed_weight));
                }
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

    vector<ipair> mst_edges = graph.prims_algorithm(0);

    cout << "Weight of MST: " << graph.get_mst_weight() << "\n";
    cout << "Edges in MST: ";
    for (auto ed : mst_edges)
    {
        cout << "(" << ed.first << ", " << ed.second << ") ";
    }
}

/*
Prim's Algorithm: Create Minimum Spanning Tree (MST) of the given graph
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
Edges in MST: (1, 0) (7, 0) (6, 7) (5, 6) (2, 5) (8, 2) (3, 2) (4, 3)

*/
