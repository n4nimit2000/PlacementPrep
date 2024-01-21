#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define pb push_back

class MinHeap
{
private:
    vll ar;

    ll parent(ll index)
    {
        return (index - 1) >> 1;
    }

    ll leftChild(ll index)
    {
        return (index << 1) + 1;
    }

    ll rightChild(ll index)
    {
        return (index << 1) + 2;
    }

    void heapify(ll index)
    {
        ll lowest = index;
        if (leftChild(index) < size() && ar[leftChild(index)] < ar[lowest])
        {
            lowest = leftChild(index);
        }
        if (rightChild(index) < size() && ar[rightChild(index)] < ar[lowest])
        {
            lowest = rightChild(index);
        }

        if (lowest != index)
        {
            swap(ar[lowest], ar[index]);
            heapify(lowest);
        }
    }

public:
    bool isEmpty()
    {
        return ar.size() == 0;
    }

    ll size()
    {
        return ar.size();
    }

    // Insert new element in the Heap following Min Heap property
    void insert(ll val)
    {
        ar.push_back(val);

        ll index = size() - 1;
        while (index > 0 && ar[index] < ar[parent(index)])
        {
            swap(ar[index], ar[parent(index)]);
            index = parent(index);
        }
    }

    // Get the min element from the Min Heap
    ll top()
    {
        if (isEmpty())
            return INT_MAX;
        return ar[0];
    }

    // Remove top element from the Heap following the Min Heap property
    void remove()
    {
        if (isEmpty())
            return;

        ll lst_index = size() - 1;
        swap(ar[0], ar[lst_index]);

        ar.pop_back();
        heapify(0);
    }
};

int main()
{

    MinHeap minHeap;

    minHeap.insert(6);
    minHeap.insert(9);
    minHeap.insert(8);
    minHeap.insert(1);
    minHeap.insert(10);
    minHeap.insert(2);

    while (!minHeap.isEmpty())
    {
        cout << minHeap.top() << " ";
        minHeap.remove();
    }

    return 0;
}