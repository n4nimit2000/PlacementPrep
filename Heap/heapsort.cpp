#include <bits/stdc++.h>

using namespace std;

class MaxHeap
{
private:
    void heapify(vector<int> &ar, int idx, int N)
    {
        int lft = (idx << 1) + 1;
        int rgt = lft + 1;

        int largest = idx;
        if (lft < N && ar[lft] > ar[largest])
        {
            largest = lft;
        }
        if (rgt < N && ar[rgt] > ar[largest])
        {
            largest = rgt;
        }

        if (largest != idx)
        {
            swap(ar[idx], ar[largest]);
            heapify(ar, largest, N);
        }
    }

    void convertArrayIntoHeap(vector<int> &ar)
    {
        int n = ar.size();
        for (int i = (n >> 1); i >= 0; i--)
        {
            heapify(ar, i, n);
        }
    }

public:
    void heapSort(vector<int> &ar)
    {
        convertArrayIntoHeap(ar);

        int n = ar.size();
        for (int i = n - 1; i >= 0; i--)
        {
            swap(ar[0], ar[i]);

            heapify(ar, 0, i);
        }
    }
};

int main()
{
    vector<int> ar = {3, 4, 2, 5, 1, 0, 9, 8};

    MaxHeap maxHeap;
    maxHeap.heapSort(ar);

    cout << "Sorted Array: ";
    for (int x : ar)
    {
        cout << x << " ";
    }
}