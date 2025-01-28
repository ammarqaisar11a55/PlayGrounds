#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <functional>
#include <numeric>
#include <string>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

//*************************************Heaps****************************************/

void PrintVector(vector<auto> a)
{
    cout << endl;
    cout << "[";

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
        if (i != a.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
    cout << endl;
}

class MaxHeap
{
public:
    int *Heap;
    int CurrentSize;
    int MaxSize;

    MaxHeap(int size)
    {
        MaxSize = size + 1;
        CurrentSize = 0;
        Heap = new int[size + 1];
    }

    ~MaxHeap()
    {
        delete[] Heap;
    }

    void InsertionInHeap(int val)
    {
        if (CurrentSize + 1 >= MaxSize)
        {
            cout << "Function abort : Heap is Full." << endl;
        }
        else
        {
            CurrentSize++;
            int index = CurrentSize;
            Heap[index] = val;

            while (index > 1)
            {
                int parent = index / 2;

                if (Heap[parent] < Heap[index])
                {
                    swap(Heap[parent], Heap[index]);
                    index = parent;
                }
                else
                {
                    // Element is at correct position
                    return;
                }
            }
        }
    }

    void DeletionFromHeap()
    {
        if (CurrentSize == 0)
        {
            cout << "Function Abort: Heap is empty!" << endl;
            return;
        }

        if (CurrentSize == 1)
        {
            CurrentSize--;
            return;
        }

        Heap[1] = Heap[CurrentSize];
        CurrentSize--;

        int index = 1;

        while (2 * index <= CurrentSize)
        {
            int leftchild = 2 * index;
            int rightchild = 2 * index + 1;
            int largerChild = leftchild;

            if (rightchild <= CurrentSize && Heap[rightchild] > Heap[largerChild])
            {
                largerChild = rightchild;
            }

            if (Heap[index] < Heap[largerChild])
            {
                swap(Heap[index], Heap[largerChild]);
                index = largerChild;
            }
            else
            {
                return;
            }
        }
    }

    void PrintHeap()
    {
        for (int i = 1; i <= CurrentSize; i++)
        {
            cout << Heap[i] << " ";
        }
        cout << endl;
    }
};

class MinHeap
{
public:
    int CurrentSize;
    int MaxSize;
    int *Heap;

    MinHeap(int size)
    {
        MaxSize = size + 1;
        CurrentSize = 0;
        Heap = new int[MaxSize];
    }

    ~MinHeap()
    {
        delete[] Heap;
    }

    void InsertionInHeap(int val)
    {
        if (CurrentSize + 1 >= MaxSize)
        {
            cout << "Function Abort: Heap is Full" << endl;
        }
        else
        {
            CurrentSize++;
            int index = CurrentSize;
            Heap[index] = val;

            while (index > 1)
            {
                int parent = index / 2;

                if (Heap[parent] > Heap[index])
                {
                    swap(Heap[index], Heap[parent]);
                    index = parent;
                }
                else
                {
                    return;
                }
            }
        }
    }

    void DeletionFromHeap()
    {
        if (CurrentSize == 0)
        {
            cout << "Function Abort: Heap is empty!" << endl;
            return;
        }

        if (CurrentSize == 1)
        {
            CurrentSize--;
            return;
        }

        Heap[1] = Heap[CurrentSize];
        CurrentSize--;

        int index = 1;

        while (2 * index <= CurrentSize)
        {
            int leftchild = 2 * index;
            int rightchild = 2 * index + 1;
            int smallerChild = leftchild;

            if (rightchild <= CurrentSize && Heap[smallerChild] > Heap[rightchild])
            {
                smallerChild = rightchild;
            }

            if (Heap[smallerChild] < Heap[index])
            {
                swap(Heap[index], Heap[smallerChild]);
                index = smallerChild;
            }
            else
            {
                return;
            }
        }
    }

    void PrintHeap()
    {
        if (CurrentSize == 0)
        {
            cout << "Function Abort: Heap is Empty" << endl;
            return;
        }

        for (int i = 1; i <= CurrentSize; i++)
        {
            cout << Heap[i] << " ";
        }
        cout << endl;
    }
};

void HeapifyForMaxHeap(vector<int> &Heap, int size, int index)
{
    int largest = index;
    int leftchild = 2 * index + 1;
    int rightchild = 2 * index + 2;

    if (leftchild < size && Heap[leftchild] > Heap[largest])
    {
        largest = leftchild;
    }

    if (rightchild < size && Heap[rightchild] > Heap[largest])
    {
        largest = rightchild;
    }

    if (largest != index)
    {
        swap(Heap[largest], Heap[index]);
        HeapifyForMaxHeap(Heap, size, largest);
    }
}

void HeapifyForMinHeap(vector<int> &Heap, int size, int index)
{
    int smallest = index;
    int leftchild = 2 * index + 1;
    int rightchild = 2 * index + 2;

    if (leftchild < size && Heap[leftchild] < Heap[smallest])
    {
        smallest = leftchild;
    }

    if (rightchild < size && Heap[rightchild] < Heap[smallest])
    {
        smallest = rightchild;
    }

    if (smallest != index)
    {
        swap(Heap[smallest], Heap[index]);
        HeapifyForMinHeap(Heap, size, smallest);
    }
}

void HeapSortUsingMaxHeap(vector<int> &Heap)
{
    int Last = Heap.size() - 1;

    while (Last > 0)
    {
        swap(Heap[0], Heap[Last]);
        Last--;

        HeapifyForMaxHeap(Heap, Last + 1, 0);
    }
}
 
void HeapSortUsingMinHeap(vector<int> &Heap)
{
}

int main()
{
    // Test Case 1:

    // MaxHeap maxHeap(5);
    // MinHeap minHeap(5);

    // maxHeap.InsertionInHeap(3);
    // maxHeap.InsertionInHeap(10);
    // maxHeap.InsertionInHeap(5);
    // maxHeap.InsertionInHeap(7);
    // maxHeap.InsertionInHeap(1);

    // minHeap.InsertionInHeap(3);
    // minHeap.InsertionInHeap(10);
    // minHeap.InsertionInHeap(5);
    // minHeap.InsertionInHeap(7);
    // minHeap.InsertionInHeap(1);

    // cout << "Max Heap after insertion: ";
    // maxHeap.PrintHeap(); // Should be: 10 7 5 3 1

    // cout << "Min Heap after insertion: ";
    // minHeap.PrintHeap(); // Should be: 1 3 5 7 10

    // Test Case 2:

    // MaxHeap maxHeap(5);
    // MinHeap minHeap(5);

    // maxHeap.InsertionInHeap(3);
    // maxHeap.InsertionInHeap(10);
    // maxHeap.InsertionInHeap(5);
    // maxHeap.InsertionInHeap(7);
    // maxHeap.InsertionInHeap(1);

    // minHeap.InsertionInHeap(3);
    // minHeap.InsertionInHeap(10);
    // minHeap.InsertionInHeap(5);
    // minHeap.InsertionInHeap(7);
    // minHeap.InsertionInHeap(1);

    // cout << "Max Heap before deletion: ";
    // maxHeap.PrintHeap();

    // cout << "Min Heap before deletion: ";
    // minHeap.PrintHeap();

    // maxHeap.DeletionFromHeap();
    // minHeap.DeletionFromHeap();

    // cout << "Max Heap after deleting root: ";
    // maxHeap.PrintHeap(); // Should still be a valid max heap

    // cout << "Min Heap after deleting root: ";
    // minHeap.PrintHeap(); // Should still be a valid min heap

    // Test Case 3:

    // MaxHeap maxHeap(5);
    // MinHeap minHeap(5);

    // cout << "Attempting deletion on empty Max Heap:" << endl;
    // maxHeap.DeletionFromHeap(); // Should output "Function Abort: Heap is empty!"

    // cout << "Attempting deletion on empty Min Heap:" << endl;
    // minHeap.DeletionFromHeap(); // Should output "Function Abort: Heap is empty!"

    // Test Case 4:

    // MaxHeap maxHeap(3);
    // MinHeap minHeap(3);

    // maxHeap.InsertionInHeap(10);
    // maxHeap.InsertionInHeap(15);
    // maxHeap.InsertionInHeap(20);
    // maxHeap.InsertionInHeap(25); // Should output "Function abort: Heap is Full."

    // minHeap.InsertionInHeap(10);
    // minHeap.InsertionInHeap(15);
    // minHeap.InsertionInHeap(20);
    // minHeap.InsertionInHeap(25);
    // Should output "Function abort: Heap is Full."

    // cout << "Max Heap after trying to insert into full heap: ";
    // maxHeap.PrintHeap(); // Should only contain 3 elements

    // cout << "Min Heap after trying to insert into full heap: ";
    // minHeap.PrintHeap(); // Should only contain 3 elements

    // Test Case 5:

    // MaxHeap maxHeap(7);
    // MinHeap minHeap(7);

    // maxHeap.InsertionInHeap(40);
    // maxHeap.InsertionInHeap(30);
    // maxHeap.InsertionInHeap(20);
    // maxHeap.InsertionInHeap(10);
    // maxHeap.DeletionFromHeap(); // Delete 40 (root)
    // maxHeap.InsertionInHeap(50);
    // maxHeap.InsertionInHeap(60);
    // maxHeap.PrintHeap(); // Should follow Max Heap rules

    // minHeap.InsertionInHeap(40);
    // minHeap.InsertionInHeap(30);
    // minHeap.InsertionInHeap(20);
    // minHeap.InsertionInHeap(10);
    // minHeap.DeletionFromHeap(); // Delete 10 (root)
    // minHeap.InsertionInHeap(5);
    // minHeap.InsertionInHeap(2);
    // minHeap.PrintHeap(); // Should follow Min Heap rules

    // Test Case 6:

    // MaxHeap maxHeap(5);
    // maxHeap.InsertionInHeap(3);
    // maxHeap.InsertionInHeap(10);
    // maxHeap.InsertionInHeap(5);
    // maxHeap.InsertionInHeap(7);
    // maxHeap.InsertionInHeap(1);
    // maxHeap.PrintHeap(); // Before Deletion

    // maxHeap.DeletionFromHeap();
    // maxHeap.PrintHeap(); // After Deletion

    // Test Case 7:

    // MinHeap minHeap(5);
    // minHeap.InsertionInHeap(3);
    // minHeap.InsertionInHeap(10);
    // minHeap.InsertionInHeap(5);
    // minHeap.InsertionInHeap(7);
    // minHeap.InsertionInHeap(1);

    // minHeap.PrintHeap(); // Expected output (before deletion): 1 3 5 10 7

    // minHeap.DeletionFromHeap();
    // minHeap.PrintHeap(); // Expected output (after deleting root): 3 7 5 10

    // vector<int> Heap = {3, 10, 5, 7, 1};

    // for (int i = Heap.size() / 2 - 1; i >= 0; i--)
    // {
    //     HeapifyForMaxHeap(Heap, Heap.size(), i);
    // }

    // cout << "Max Heaped Array: " << endl;
    // PrintVector(Heap);
    // cout << endl;
    // cout << "Sorted Using HeapSort: " << endl;
    // HeapSortUsingMaxHeap(Heap);
    // PrintVector(Heap);

    // vector<int> Heap2 = {3, 10, 5, 7, 1};

    // for (int i = Heap2.size() / 2 - 1; i >= 0; i--)
    // {
    //     HeapifyForMinHeap(Heap2, Heap2.size(), i);
    // }

    // cout << endl
    //      << "--------------------------" << endl;

    // cout << "Min Heaped Array: " << endl;
    // PrintVector(Heap2);
    // cout << endl;
    // cout << "Sorted Using HeapSort: " << endl;
    // HeapSortUsingMaxHeap(Heap2);
    // PrintVector(Heap2);

    // // Min Heap and Max Heap using standrd template library i.e. Priority Queue:

    // priority_queue<int, vector<int>, greater<int>> MinHeapSTL;
    // priority_queue<int, vector<int>, less<int>> MaxHeapSTL;

    return 0;
}