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


/**
 * Module to find:
 * 1. If a number 'x' between 1 to N is prime or not - stored in 'sieve[x]'
 * 2. Smallest prime factor of a number 'x' between 1 to N - stored in 'pf[x]'
 * 3. List of prime numbers between 1 to N - stored in 'prime[]'
 **/
const int N = 1000010;
vi sieve(N, 1), pf(N), prime;
void soe()
{
    sieve[0] = sieve[1] = 0;

    for (int i = 1; i < N; i++)
        pf[i] = i;

    for (int i = 4; i < N; i += 2)
        pf[i] = 2, sieve[i] = 0;

    for (int i = 3; i * i < N; i += 2)
    {
        if (sieve[i])
            for (int j = i * i; j < N; j += i)
            {
                if (pf[j] == j)
                    pf[j] = i;
                sieve[j] = 0;
            }
    }
    for (int i = 1; i < N; i++)
        if (sieve[i])
            prime.push_back(i);
}


/**
 * Module to compute (x to the power y)%mod
**/
ll ppow(ll x, ll y)
{
    ll res = 1;
    x = (x + mod) % mod;
    while (y)
    {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

/**
 * Module to check if a given number n is prime or not
**/
bool isprime(ll n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

/**
 * Module to compute (nCr)%mod
**/
ll nCr(ll n, ll r)
{
    if (n < r)
        return 0;
    if (n == r || r == 0)
        return 1;
    ll num = 1, den = 1;
    r = min(r, n - r);
    for (ll i = 1; i <= r; i++)
    {
        num = (num * (n - i + 1)) % mod;
        den = (den * i) % mod;
    }
    den = ppow(den, mod - 2);
    ll ans = (num * den) % mod;
    return ans;
}

/**
 * Module to compute LCA (Lowest Common Ancestor) in Trees using Binary Lifting technique
**/
vector<vector<ll>> lca;
vector<ll> lvl;
ll maxN = 0;
void dfs(int cur, int par, int dep = 0)
{
    lvl[cur] = dep;
    lca[cur][0] = par;
    for (ll child : ed[cur])
    {
        if (child != par)
            dfs(child, cur, dep + 1);
    }
}

void makeTable(ll n)
{
    maxN = 20;
    lca.resize(n + 1, vector<ll>(maxN + 1, -1));
    lvl.resize(n + 1);
    dfs(1, -1);

    for (ll j = 1; j <= maxN; j++)
    {
        for (ll i = 1; i < n; i++)
        {
            if (lca[i][j - 1] != -1)
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
    }
}

ll getLCA(ll a, ll b)
{
    if (lvl[a] > lvl[b])
        swap(a, b);
    ll d = lvl[b] - lvl[a];

    while (d)
    {
        ll i = (int)(log2(d));
        b = lca[b][i];
        d -= (1 << i);
    }
    if (a == b)
        return a;

    for (ll i = maxN; i >= 0; i--)
    {
        if (lca[a][i] != lca[b][i])
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}

/**
 * Start your code here!
**/
void solve()
{
    cout<<"Hello World!";
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



*/
