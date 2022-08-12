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

int solve_josephus_problem(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return ((solve_josephus_problem(n - 1, k) + (k - 1)) % n) + 1;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int last_person_remaining = solve_josephus_problem(n, k);

    cout << "Last person remaining is " << last_person_remaining << "\n";
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
Given the total number of persons N and a number K which indicates that (K-1) persons are skipped and
Kth person is killed in circle.
Find the position in the initial circle so that you are the last one remaining.
Time Complexity = O(N)
Space Complexity = O(N) [recursive stack]

Sample Input:
7 3

Sample Output:
4
*/
