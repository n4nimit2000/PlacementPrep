#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define pb push_back
#define ipair pair<ll, ll>
#define F(i, a, b) for (ll i = a; i < b; i++)
#define inf LLONG_MAX

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

    void create_edge(ll u, ll v, bool isDirected = false)
    {
        edges[u].pb(v);

        if (!isDirected)
        {
            edges[v].pb(u);
        }
    }

    void bfs(ll src, ll &ans)
    {
        vll dis(n, inf);
        queue<int> q;
        q.push(src);

        dis[src] = 0;

        while (q.size())
        {
            ll cur = q.front();
            q.pop();

            for (auto neigh : edges[cur])
            {
                if (dis[neigh] == inf)
                {
                    // Not yet visited
                    dis[neigh] = dis[cur] + 1;
                    q.push(neigh);
                }
                else if (dis[neigh] >= dis[cur])
                {
                    // Encountered a backedge
                    ans = min(ans, dis[neigh] + dis[cur] + 1);
                }
            }
        }
    }

    void find_shortest_cycle()
    {
        ll ans = n + 1;

        F(i, 0, n)
        {
            bfs(i, ans);
        }

        if (ans == n + 1)
            cout << "No cycle\n";
        else
            cout << "Length of the shortest cycle: " << ans;
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

    graph.find_shortest_cycle();
}

/*
Shortest cycle in undirected graph
Run a BFS from all the nodes to find the length of all the cycles present in the graph.
Time Complexity: O(N * (N + E))  -> for each node we run a BFS
Space Complexity: O(N^2)  -> for edges (worst case)

Sample Input1:
7 8
0 6
0 5
5 1
1 6
2 6
2 3
4 3
4 1

Sample Output1:
Length of the shortest cycle: 4

Sample Input2:
7 9
0 6
0 5
5 1
1 6
2 6
2 3
4 3
4 1
1 2

Sample Output2:
Length of the shortest cycle: 3

*/