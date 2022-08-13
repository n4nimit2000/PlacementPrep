#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define sbits __builtin_popcount
#define fill(vect, n) fill(vect.begin(), vect.end(), n)
#define pb push_back
#define pf push_front
#define vi vector<int>
#define vll vector<ll>
#define F(i, a, b) for (ll i = a; i < b; i++)
#define Fr(i, a, b) for (ll i = a; i >= b; i--)
#define inf LLONG_MAX
#define ninf -1 * inf
#define maxv(v) *max_element(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define ipair pair<ll, ll>
#define all(vec) vec.begin(), vec.end()
#define mat(DT) vector<vector<DT>>
#define p_q_d(DT) priority_queue<DT>
#define p_q_a(DT) priority_queue<DT, vector<DT>, greater<DT>>
#define ps(x, y) fixed << setprecision(y) << x
#define mod 1000000007

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

    void dfs(ll node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (auto neigh : edges[node])
        {
            if (!visited[neigh])
            {
                dfs(neigh, visited);
            }
        }
    }

    void bfs(ll source, vector<bool> &visited)
    {
        queue<ll> q;
        q.push(source);
        visited[source] = true;

        while (q.size())
        {
            ll node = q.front();
            q.pop();

            cout << node << " ";

            for (auto child : edges[node])
            {
                if (!visited[child])
                {
                    visited[child] = true;
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

        graph.create_edge(u, v);
    }

    vector<bool> visited(n, false);

    graph.bfs(0, visited);
}

/*
Basic Graph template

Sample Input 1:
4 3
0 1
1 2
2 3

Sample Input 2:
5 6
0 2
0 4
2 3
2 1
3 4
1 4

*/