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
        this->prev = NULL;
        this->next = NULL;
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

class FrontMiddleBackQueue
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int current_size;

    FrontMiddleBackQueue()
    {
        current_size = 0;
    }

    void pushFront(int val)
    {
        ListNode *node_to_insert = new ListNode(val);
        current_size++;

        if (head == nullptr)
        {
            head = tail = node_to_insert;
            PrintList(head);
            return;
        }

        head->prev = node_to_insert;
        node_to_insert->next = head;
        head = node_to_insert;
        PrintList(head);
    }

    void pushMiddle(int val)
    {
        ListNode *node_to_insert = new ListNode(val);

        if (head == nullptr)
        {
            current_size++;
            head = tail = node_to_insert;
            PrintList(head);
            return;
        }

        int position_to_reach;

        if (current_size % 2 == 0)
        {
            position_to_reach = current_size / 2;
        }
        else
        {
            position_to_reach = (current_size + 1) / 2;
        }

        ListNode *cralwer = head;

        for (int i = 1; i < position_to_reach; i++)
        {
            cralwer = cralwer->next;
        }

        node_to_insert->prev = cralwer;
        node_to_insert->next = cralwer->next;

        if (cralwer->next != nullptr)
        {
            node_to_insert->next->prev = node_to_insert;
        }
        else
        {
            tail = node_to_insert;
        }

        PrintList(head);

        cralwer->next = node_to_insert;
        current_size++;
    }

    void pushBack(int val)
    {
        ListNode *node_to_insert = new ListNode(val);
        current_size++;

        if (tail == nullptr)
        {
            head = tail = node_to_insert;
        }

        tail->next = node_to_insert;
        node_to_insert->prev = tail;
        tail = node_to_insert;
        PrintList(head);
    }

    int popFront()
    {
        if (current_size == 0)
        {
            return -1;
        }

        if (current_size == 1)
        {
            current_size--;
            int value_to_return = head->val;
            head = tail = nullptr;
            return value_to_return;
        }

        current_size--;

        ListNode *node_to_delete = head;
        head = head->next;

        head->prev = nullptr;
        node_to_delete->next = nullptr;

        int value_to_return = node_to_delete->val;
        delete node_to_delete;
        return value_to_return;
    }

    int popMiddle()
    {
        if (current_size == 0)
        {
            return -1;
        }

        if (current_size == 1)
        {
            current_size--;
            int value_to_return = head->val;
            head = tail = nullptr;
            return value_to_return;
        }

        int position_to_reach;

        if (current_size % 2 == 0)
        {
            position_to_reach = current_size / 2;
        }
        else
        {
            position_to_reach = (current_size + 1) / 2;
        }

        ListNode *cralwer = head;

        for (int i = 1; i < position_to_reach; i++)
        {
            cralwer = cralwer->next;
        }

        
    }

    int popBack()
    {
        if (current_size == 0)
        {
            return -1;
        }

        if (current_size == 1)
        {
            current_size--;
            int value_to_return = tail->val;
            head = tail = nullptr;
            return value_to_return;
        }

        current_size--;

        ListNode *node_to_delete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        node_to_delete->prev = nullptr;

        int value_to_return = node_to_delete->val;
        delete node_to_delete;
        return value_to_return;
    }
};

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/
    /************************************************************************************/
    FrontMiddleBackQueue q;
    q.pushBack(1);
    // q.pushBack(2);
    // q.pushMiddle(3);
    // q.pushMiddle(4);
    // cout << q.popFront() << endl;
    // cout << q.popMiddle() << endl;
    // cout << q.popMiddle() << endl;
    // cout << q.popBack() << endl;
    // cout << q.popFront() << endl;
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