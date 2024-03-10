#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define inf LLONG_MAX
#define vll vector<ll>

class SegmentTree
{
private:
    vll tree;
    ll N;

public:
    SegmentTree(ll n, ll defaultValue)
    {
        N = (4 * n) + 5;
        tree = vll(N, defaultValue);
    }

    void build(vll &ar, ll ind, ll start, ll end)
    {
        if (start == end)
        {
            tree[ind] = ar[start];
            return;
        }

        ll mid = (start + end) >> 1;
        ll lftInd = (ind << 1) | 1;
        ll rgtInd = lftInd + 1;

        build(ar, lftInd, start, mid);
        build(ar, rgtInd, mid + 1, end);

        tree[ind] = min(tree[lftInd], tree[rgtInd]);
    }

    ll query(ll ind, ll start, ll end, ll l, ll r)
    {
        if (r < start || end < l)
        {
            return inf;
        }
        if (l <= start && end <= r)
        {
            return tree[ind];
        }

        ll mid = (start + end) >> 1;
        ll lftInd = (ind << 1) | 1;
        ll rgtInd = lftInd + 1;

        ll lftRes = query(lftInd, start, mid, l, r);
        ll rgtRes = query(rgtInd, mid + 1, end, l, r);

        ll res = min(lftRes, rgtRes);

        return res;
    }

    void update(ll ind, ll start, ll end, ll &idx, ll &val)
    {
        if (start == end)
        {
            tree[ind] = val;
            return;
        }

        ll mid = (start + end) >> 1;
        ll lftInd = (ind << 1) | 1;
        ll rgtInd = lftInd + 1;

        if (start <= idx && idx <= mid)
            update(lftInd, start, mid, idx, val);
        else
            update(rgtInd, mid + 1, end, idx, val);

        tree[ind] = min(tree[lftInd], tree[rgtInd]);
    }

    void display()
    {
        for (auto &x : tree)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;

    vll ar(n);
    for (auto &x : ar)
        cin >> x;

    SegmentTree st(n, inf);

    st.build(ar, 0, 0, n - 1);

    while (q--)
    {
        char ch;
        cin >> ch;

        if (ch == 'q')
        {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            cout << st.query(0, 0, n - 1, l, r) << "\n";
        }
        else
        {
            ll idx, val;
            cin >> idx >> val;
            idx--;
            st.update(0, 0, n - 1, idx, val);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}

/*

Range Minimum Query

Problem link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/

Sample Input:
1
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

Sample Output:
1
1
2
1

*/
