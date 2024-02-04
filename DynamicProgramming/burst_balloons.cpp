#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

// Time Complexity = O(N^3), Space Complexity = O(N^2)
int recur(int start, int end, vector<int> &nums, vector<vector<int>> &dp)
{
    if (start > end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];

    int ans = 0;
    for (int i = start; i <= end; i++)
    {
        int cur = nums[i];
        int lft = start - 1 < 0 ? 1 : nums[start - 1];
        int rgt = end + 1 >= nums.size() ? 1 : nums[end + 1];
        int cost = lft * cur * rgt;
        ans = max(ans, recur(start, i - 1, nums, dp) + recur(i + 1, end, nums, dp) + cost);
    }

    return dp[start][end] = ans;
}

int getMaximumCoins(vector<int> &ar, int &n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return recur(0, n - 1, ar, dp);
}

int main()
{
    int n;
    cin >> n;
    vi ar(n);
    for (auto &x : ar)
    {
        cin >> x;
    }

    cout << getMaximumCoins(ar, n);
    return 0;
}

/*

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Sample Input:
4
3 1 5 8
Sample Output:
167

Ref: https://leetcode.com/problems/burst-balloons/description/

Video Tutorial: https://www.youtube.com/watch?v=Yz4LlDSlkns&ab_channel=takeUforward

*/