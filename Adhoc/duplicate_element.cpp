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

ll get_duplicate_element(vll &ar, int number_of_elements)
{
    int slow = ar[0], fast = ar[0];

    do
    {
        slow = ar[slow];
        fast = ar[ar[fast]];
    } while (slow != fast);

    fast = ar[0];
    while (slow != fast)
    {
        slow = ar[slow];
        fast = ar[fast];
    }

    return fast;
}

void solve()
{
    int number_of_elements;
    cin >> number_of_elements;
    vll ar(number_of_elements);
    F(i, 0, number_of_elements)
    {
        cin >> ar[i];
    }

    int duplicate_element = get_duplicate_element(ar, number_of_elements);
    cout << "Duplicate element is " << duplicate_element;
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
Given an array of integers containing (N+1) integers where each integer is in the range [1,N] inclusive.
There is only one duplicate element. Find this element.
Time complexity = O(N)
Space complexity = O(1)

Sample Input:
8
1 3 4 2 4 7 6 5
8
2 3 1 4 5 1 7 1

Sample Output:
4
1

*/
