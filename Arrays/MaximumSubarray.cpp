#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
int maxSubArray(vector<int> &nums)
{
    int ans = nums[0];
    int sum = 0;
    for (auto num : nums)
    {
        sum += num;
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;

    cout << maxSubArray(nums) << "\n";
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
Given an integer array nums, find the subarray with the largest sum, and return its sum

Ref: https://leetcode.com/problems/maximum-subarray/description/

*/
