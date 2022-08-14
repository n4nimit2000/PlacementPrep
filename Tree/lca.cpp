#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define pb push_back

vector<vll> ed, lca;
vll lvl;
ll maxN = 0;

void dfs(ll cur, ll par, ll depth = 0)
{
    lvl[cur] = depth;
    lca[cur][0] = par;

    for (auto child : ed[cur])
    {
        if (child != par)
        {
            dfs(child, cur, depth + 1);
        }
    }
}

void make_table(ll n)
{
    dfs(0, 0);

    for (int j = 1; j <= maxN; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (lca[i][j - 1] != -1)
            {
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
            }
        }
    }
}

ll get_lca(ll u, ll v)
{
    if (lvl[u] > lvl[v])
        swap(u, v);

    ll distance = lvl[v] - lvl[u];
    while (distance)
    {
        ll i = (int)(log2(distance));
        v = lca[v][i];
        distance -= (1 << i);
    }

    if (u == v)
        return u;

    for (int i = maxN; i >= 0; i--)
    {
        if (lca[u][i] != lca[v][i])
        {
            u = lca[u][i];
            v = lca[v][i];
        }
    }

    return lca[u][0];
}

int main()
{
    ll n;
    cin >> n;

    ed.resize(n);
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    lvl.resize(n);

    maxN = (ll)(log2(n + 1));
    lca.resize(n, vll(maxN + 1, -1));

    make_table(n);

    ll q;
    cin >> q;

    while (q--)
    {
        ll u, v;
        cin >> u >> v;

        cout << "LCA of " << u << " and " << v << " is " << get_lca(u, v) << "\n";
    }
    return 0;
}

/*
Time complexity:
Preprocessing = O(NlogN) -> make_table
get_lca = O(logN)


Sample Input:
13
0 1
0 2
0 3
2 4
2 5
2 6
5 7
5 8
6 9
6 10
9 11
9 12
8
2 5
3 8
1 0
7 4
9 4
7 12
11 12
11 10

Sample Output:
LCA of 2 and 5 is 2
LCA of 3 and 8 is 0
LCA of 1 and 0 is 0
LCA of 7 and 4 is 2
LCA of 9 and 4 is 2
LCA of 7 and 12 is 2
LCA of 11 and 12 is 9
LCA of 11 and 10 is 6

*/