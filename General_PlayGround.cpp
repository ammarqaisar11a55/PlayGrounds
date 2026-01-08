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

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

void DFS(Node *&head, Node *&parent_node, Node *next_part)
{
    while (head)
    {
        if (head->child)
        {
            Node *current_node_next_part = head->next;
            current_node_next_part->prev = nullptr;
            head->next = head->child;
            DFS(head->child, head, current_node_next_part);
        }

        head = head->next;
    }
}

Node *flatten(Node *head)
{
    return head;
}

int findLeastNumOfUniqueInts(vector<int> arr, int k)
{
    unordered_map<int,int>mp;

    for(int i : arr)
    {
        mp[i]++;
    }

    priority_queue<int,vector<int>,greater<int>>pq;

    for(auto [val,freq] : mp)
    {
        pq.push(freq);
    }

    while(true)
    {
        if(pq.empty() == false)
        {
            if(k - pq.top() >= 0)
            {
                k -= pq.top();
                pq.pop();
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }



    return (int)pq.size();
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/
    /************************************************************************************/
    cout<<findLeastNumOfUniqueInts(vector<int>{5,5,4},1)<<endl;
    cout<<findLeastNumOfUniqueInts(vector<int>{4,3,1,1,3,3,2},3)<<endl;

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