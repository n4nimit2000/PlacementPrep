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

int get_gcd(int a, int b)
{
    if (b == 0)
        return a;

    return get_gcd(b, a % b);
}

void solve()
{
    int a, b;
    cin >> a >> b;

    int gcd = get_gcd(a, b);

    cout << "The GCD of " << a << " and " << b << " is " << gcd << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}

/*
Find the GCD of two numbers.
Time complexity = O(log(max(a,b)))

Sample Input:
18 24

Sample Output:
6


*/
