#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

int main()
{
    ll friends, transactions;
    cin >> friends >> transactions;

    // Array to store the net amount that each person will need to give at the end
    vll net(friends, 0);

    for (int i = 0; i < transactions; i++)
    {
        ll x, y, amt;
        cin >> x >> y >> amt; // 'x' has given amount 'amt' to 'y'

        net[x] -= amt;
        net[y] += amt;
    }

    multiset<ll> m;
    for (int i = 0; i < friends; i++)
    {
        if (net[i] != 0)
        {
            m.insert(net[i]);
        }
    }

    ll cash_flow = 0;

    // Pop out two person (left & right) and try to settle them
    while (m.size())
    {
        auto low = m.begin();
        auto high = m.end();
        high--;

        ll debit = *low;
        ll credit = *high;

        // erase from the multiset
        m.erase(low);
        m.erase(high);

        // settlement
        ll settlement_amt = min(-debit, credit);

        // settlement amount from donor to acceptor
        debit += settlement_amt;
        credit -= settlement_amt;

        if (debit != 0)
            m.insert(debit);
        if (credit != 0)
            m.insert(credit);

        cash_flow++;
    }

    cout << "Minimum number of transactions needed for settlement is " << cash_flow << "\n";
    return 0;
}

/*
Given a number of friends who have to give or take some amount of money from one another. Minimize the
cash flow among all the friends.
Time complexity: O(NlogN)  -> N is the number of friends

Sample Input:
3 3
0 1 100
1 2 50
2 0 30

Sample Output:
Minimum number of transactions needed for settlement is 2

*/