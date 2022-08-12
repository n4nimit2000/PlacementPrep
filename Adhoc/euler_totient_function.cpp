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

ll euler_totient_function(ll n)
{
    ll count = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count = count - (count / i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }

    if (n > 1)
    {
        count = count - (count / n);
    }
    return count;
}

void solve()
{
    ll n;
    cin >> n;

    ll count_of_numbers_coprime_with_n = euler_totient_function(n);
    cout << "The count of numbers which are smaller than " << n << " and are co-prime with " << n << " is " << count_of_numbers_coprime_with_n << "\n";
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
To find the count of numbers which are smaller than N and are co-prime with N.
Two numbers are called co-prime if their GCD = 1
Time complexity = O(sqrt(N))
Space complexity = O(1)


Sample Input:
12

Sample Output:
4 {1,5,7,11}


*/
