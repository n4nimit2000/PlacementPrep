#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

class DSU
{
private:
    vll parent, size;
    ll noOfComponents;

public:
    DSU(ll n)
    {
        // Creating vector of size (n + 1) to handle 1-based indexing
        parent = vll(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

        size = vll(n + 1, 1);

        noOfComponents = n;
    }

    ll find(ll node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionBySize(ll u, ll v)
    {
        ll parOfU = find(u), parOfV = find(v);
        if (parOfU == parOfV)
            return;

        if (size[parOfU] > size[parOfV])
        {
            parent[parOfV] = parOfU;
            size[parOfU] += size[parOfV];
        }
        else
        {
            parent[parOfU] = parOfV;
            size[parOfV] += size[parOfU];
        }

        noOfComponents--;
    }

    ll getNoOfComponents()
    {
        return noOfComponents;
    }
};

int main()
{
    DSU dsu(5);

    dsu.unionBySize(1, 5);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(1, 3);

    cout << "Number of Components in graph: " << dsu.getNoOfComponents() << "\n";

    return 0;
}

/*



*/
