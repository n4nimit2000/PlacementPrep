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
 * Time Compelxity = O(N^2), Space Complexity = O(N)
 **/
ll getSolutionUsingDP(vll &nums)
{
    int n = nums.size();
    if (n == 1)
        return 1;
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int tmp = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                tmp = max(tmp, dp[j] + 1);
            }
        }
        dp[i] = tmp;
        ans = max(ans, dp[i]);
    }

    return ans;
}

int getLowerBound(vector<int> &ar, int &cur)
{
    int n = ar.size();
    int low = 0, high = n - 1, lowerBoundIndex = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (ar[mid] < cur)
        {
            low = mid + 1;
        }
        else
        {
            lowerBoundIndex = mid;
            high = mid - 1;
        }
    }
    return lowerBoundIndex;
}

/**
 * Time complexity = O(NlogN), Space Complexity = O(N).
 * Ref: https://www.youtube.com/watch?v=on2hvxBXJH4&ab_channel=takeUforward
 **/
ll getSolutionUsingBinarySearch(vll &nums)
{
    int n = nums.size();
    if (n == 1)
        return 1;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        int cur = nums[i];
        int lowerBoundIndex = getLowerBound(ar, cur); // NOTE: You can also use the inbuilt lower_bound function here
        if (lowerBoundIndex == -1)
        {
            ar.push_back(cur);
        }
        else
        {
            ar[lowerBoundIndex] = cur;
        }
    }

    return ar.size();
}

int lengthOfLIS(vll &nums)
{
    cout << "Answer using DP:\n"
         << getSolutionUsingDP(nums) << "\n";
    cout << "Answer using Binary Search:\n"
         << getSolutionUsingBinarySearch(nums) << "\n";
}

void solve()
{
    ll n;
    cin >> n;
    vll nums(n);
    for (auto &num : nums)
    {
        cin >> num;
    }
    cout << lengthOfLIS(nums);
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

Given an integer array nums, return the length of the longest strictly increasing
subsequence.

Sample Input:
3
8
10 9 2 5 3 7 101 18
6
0 1 0 3 2 3
5
7 7 7 7 7

Sample Output:
4
4
1

Ref: https://leetcode.com/problems/longest-increasing-subsequence/description/


*/
