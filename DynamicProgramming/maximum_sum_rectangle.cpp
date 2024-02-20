#include <bits/stdc++.h>

using namespace std;

// Time Complexity = O(R*R*C), Space Complexity = O(C)
int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int res = INT_MIN;

    for (int r1 = 0; r1 < R; r1++)
    {
        vector<int> ar(C);
        for (int r2 = r1; r2 < R; r2++)
        {
            for (int c = 0; c < C; c++)
            {
                ar[c] += M[r2][c];
            }
            int sum = 0;
            for (int c = 0; c < C; c++)
            {
                if (sum < 0)
                {
                    sum = 0;
                }
                sum += ar[c];
                res = max(res, sum);
            }
        }
    }

    return res;
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> M(R, vector<int>(C));
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> M[r][c];
        }
    }

    cout << "Maximum sum Rectangle value: " << maximumSumRectangle(R, C, M);
    return 0;
}

/*
Problem link: https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Sample Input:
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

Sample Output:
Maximum sum Rectangle value: 29


Variations of this Problem:
 - Largest Rectangular Sub-matrix whose sum is 0
 - Largest area rectangular sub-matrix with equal number of 1's and 0's (convert 0's to -1's, then it's same as the previous problem)

*/