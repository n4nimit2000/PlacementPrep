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

ll get_kth_smallest_element(vll &ar, int start, int end, int k)
{
    // Quick Select Algorithm
    srand(time(0));
    k = k - 1;

    while (start <= end)
    {
        int number_of_elements = end - start + 1;
        int random = start + (rand() % number_of_elements);
        swap(ar[random], ar[end]);
        int j = start, pivot = ar[end];
        for (int i = start; i < end; i++)
        {
            if (ar[i] < pivot)
            {
                swap(ar[i], ar[j]);
                j++;
            }
        }
        swap(ar[j], ar[end]);

        if (j == k)
            return ar[j];
        if (j > k)
            end = j - 1;
        else
            start = j + 1;
    }

    return -1;
}

void solve()
{
    int number_of_elements, k;
    cin >> number_of_elements >> k;
    vll ar(number_of_elements);
    F(i, 0, number_of_elements)
    {
        cin >> ar[i];
    }

    int start = 0, end = number_of_elements - 1;
    int kth_smallest_element = get_kth_smallest_element(ar, start, end, k);
    if (kth_smallest_element == -1)
        cout << "Kth smallest element does not exist\n";
    else
        cout << "Kth smallest element is " << kth_smallest_element;
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
Program to find the Kth smallest element in an array.
Time complexity = O(N)
Space complexity = O(1)

Sample Input:
8 6
9 3 1 5 3 12 4 10

Sample Output:
9

*/
