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

string mapWordWeights(vector<string> words, vector<int> weights)
{

    string res;

    unordered_map<int,char>reversed_mappiing;

    int temp = 0;

    for(char c = 'z'; c>= 'a'; c--)
    {
        reversed_mappiing[temp++] = c;
    }

    for(int i = 0; i < words.size(); i++)
    {
        int weight_of_single = 0;

        for(int j = 0; j < words[i].length(); j++)
        {
            int score_of_letter = weights[words[i][j] - 'a'];
            weight_of_single += score_of_letter;
        }

        res += reversed_mappiing[weight_of_single % 26];
    }

    return res;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/
    cout<<mapWordWeights(vector<string>{"abcd","def","xyz"},vector<int>{5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2})<<endl;
    cout<<mapWordWeights(vector<string>{"a","b","c"},vector<int>{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1})<<endl;
    cout<<mapWordWeights(vector<string>{"abcd"},vector<int>{7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5})<<endl;
    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << '\n';
    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}
