#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define inf LLONG_MAX
#define ninf -1 * inf

/**
 * Time Complexity = O(N), Space Complexity = O(1)
 **/
ll getMaxProductSubarray(vll &nums)
{
    ll prefix = 1LL, suffix = 1LL;
    ll ans = ninf;
    ll n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1LL;
        if (suffix == 0)
            suffix = 1LL;

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        ans = max({ans, prefix, suffix});
    }

    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vll nums(n);
    for (auto &x : nums)
    {
        cin >> x;
    }

    cout << getMaxProductSubarray(nums) << "\n";
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

Given an integer array nums, find a subarray that has the largest product, and return the product.

Sample Input:
5
4
2 3 -2 4
3
-2 0 -1
3
0 3 -1
8
-2 7 -1 0 9 2 -1 2
10
8 1 1 0 9 -2 1 -1 0 100

Sample Output:
6
0
3
18
100


Ref: https://leetcode.com/problems/maximum-product-subarray/description/

Video: https://www.youtube.com/watch?v=hnswaLJvr6g&ab_channel=takeUforward


*/
