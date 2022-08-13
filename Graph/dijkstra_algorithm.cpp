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
    vector<vector<ipair>> edges;

public:
    Graph(ll number_of_nodes, ll number_of_edges)
    {
        n = number_of_nodes;
        e = number_of_edges;
        edges.resize(n);
    }

    void create_edge(ll u, ll v, ll wt, bool isDirected = false)
    {
        edges[u].pb({v, wt});

        if (!isDirected)
        {
            edges[v].pb({u, wt});
        }
    }

    vll dijkstra(ll src)
    {
        vll distance(n, inf);
        distance[src] = 0;

        priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
        pq.push({0, src}); //{distance from source, node}

        while (pq.size())
        {
            ipair data = pq.top();
            pq.pop();

            ll node = data.second;
            ll distance_till_node = data.first;

            for (auto neigh : edges[node])
            {

                if (distance[neigh.first] > distance_till_node + neigh.second)
                {
                    distance[neigh.first] = distance_till_node + neigh.second;
                    pq.push({distance[neigh.first], neigh.first});
                }
            }
        }

        return distance;
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

    ll src;
    cin >> src;

    vll distance = graph.dijkstra(src);
    for (int i = 0; i < n; i++)
    {
        cout << "Distance of node " << i << " from node " << src << " is " << distance[i] << "\n";
    }
}

/*
Dijstra Algorithm: Single Source Shortest Path for positive weight graph.
Time Complexity: O(ElogN)

Application - Digital mapping service in Google maps, IP routing to find the open shortest path first.

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
0

Sample Output:
Distance of node 0 from node 0 is 0
Distance of node 1 from node 0 is 4
Distance of node 2 from node 0 is 12
Distance of node 3 from node 0 is 19
Distance of node 4 from node 0 is 21
Distance of node 5 from node 0 is 11
Distance of node 6 from node 0 is 9
Distance of node 7 from node 0 is 8
Distance of node 8 from node 0 is 14

*/
