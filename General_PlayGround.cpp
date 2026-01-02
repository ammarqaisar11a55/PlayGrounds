#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <functional>
#include <cmath>
#include <set>
#include <chrono>
#include <list>
#include <climits>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int d)
    {
        left = nullptr;
        right = nullptr;
        val = d;
    }
};

template <typename V>

void PrintVector(vector<V> a)
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

template <typename M>

void PrintMatrixVector(vector<vector<M>> Grid)
{
    for (int i = 0; i < Grid.size(); i++)
    {
        for (int j = 0; j < Grid[i].size(); j++)
        {
            cout << Grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void Level_Order_Traversal(TreeNode *Root)
{
    if (Root == NULL)
        return;

    queue<TreeNode *> Nodes;

    Nodes.push(Root);
    Nodes.push(NULL);

    while (!Nodes.empty())
    {
        TreeNode *Temp = Nodes.front();
        Nodes.pop();

        if (Temp == NULL)
        {
            cout << endl;

            if (!Nodes.empty())
                Nodes.push(NULL);
        }
        else
        {
            cout << Temp->val << " ";

            if (Temp->left != NULL)
                Nodes.push(Temp->left);

            if (Temp->right != NULL)
                Nodes.push(Temp->right);
        }
    }
}

// Trie Node Definition
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void PrintList(ListNode *Head)
{
    ListNode *Temp = Head;

    cout << "Data: ";

    while (Temp != NULL)
    {
        cout << Temp->val << " ";
        Temp = Temp->next;
    }

    cout << endl;
}

/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/

/*
    g++ General_PlayGround.cpp -o Gp
*/

class MyCircularDeque
{
public:
    ListNode *head = nullptr;
    ListNode *tail;
    int Current_size;
    int Max_size;

    MyCircularDeque(int k)
    {
        Max_size = k;
        Current_size = 0;
    }

    bool insertFront(int value)
    {

        if (Current_size < Max_size)
        {
            ListNode *node_to_insert = new ListNode(value);
            Current_size++;

            if (head == nullptr)
            {
                head = tail = node_to_insert;
            }
            else
            {
                head->prev = node_to_insert;
                node_to_insert->next = head;
                head = node_to_insert;
            }

            return true;
        }

        return false;
    }

    bool insertLast(int value)
    {

        if (Current_size < Max_size)
        {
            ListNode *node_to_insert = new ListNode(value);
            Current_size++;

            if (head == nullptr)
            {
                head = tail = node_to_insert;
            }
            else
            {
                node_to_insert->prev = tail;
                tail->next = node_to_insert;
                tail = node_to_insert;
            }

            return true;
        }

        return false;
    }

    bool deleteFront()
    {
        if (Current_size == 0)
        {
            return false;
        }

        if (Current_size == 1)
        {
            head = tail = nullptr;
            Current_size--;
            return true;
        }

        ListNode *node_to_delete = head;
        head = head->next;
        head->prev = nullptr;
        node_to_delete->next = nullptr;
        delete node_to_delete;
        Current_size--;
        return true;
    }

    bool deleteLast()
    {
        if (Current_size == 0)
        {
            return false;
        }

        if (Current_size == 1)
        {
            head = tail = nullptr;
            Current_size--;
            return true;
        }

        ListNode *node_to_delete = tail;
        tail = tail->prev;
        tail->next = nullptr;

        node_to_delete->prev = nullptr;

        delete node_to_delete;
        Current_size--;
        return true;
    }

    int getFront()
    {
        return head == nullptr ? -1 : head->val;
    }

    int getRear()
    {
        return tail == nullptr ? -1 : tail->val;
    }

    bool isEmpty()
    {
        return head == nullptr ? true : false;
    }

    bool isFull()
    {
        return Current_size == Max_size ? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/
    /************************************************************************************/
    MyCircularDeque t(3);
    cout << t.insertLast(1) << endl;
    cout << t.insertLast(2) << endl;
    cout << t.insertFront(3) << endl;
    cout << t.insertFront(4) << endl;
    cout << t.getRear() << endl;
    cout << t.isFull() << endl;
    cout << t.deleteLast() << endl;
    cout << t.insertFront(4) << endl;
    cout << t.getFront() << endl;
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << '\n';
    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}