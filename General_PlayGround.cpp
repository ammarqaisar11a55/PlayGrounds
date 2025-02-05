#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <functional>
#include <cmath>
#include <set>
#include <chrono>
#include <map>
#include <list>
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

void PrintVector(vector<string> a)
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

void PrintVector(vector<char> a)
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

void PrintVector(vector<int> a)
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

void PrintVector(vector<bool> a)
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

void PrintMatrixVector(vector<vector<char>> Grid)
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

void PrintMatrixVector(vector<vector<int>> Grid)
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

void PrintMatrixVector(vector<vector<string>> Grid)
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

/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/

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

void Creation(TreeNode *&Root, int Val, unordered_map<int, int> &Left_Childs, unordered_map<int, int> &Right_Childs)
{
    if (Root == nullptr)
    {
        Root = new TreeNode(Val);   
    }

    if(Left_Childs.find(Root->val)!=Left_Childs.end())
    {
        Creation(Root->left,Left_Childs[Root->val],Left_Childs,Right_Childs);    
    }

    if(Right_Childs.find(Root->val)!=Right_Childs.end())
    {
        Creation(Root->right,Right_Childs[Root->val],Left_Childs,Right_Childs);    
    }
}

TreeNode *createBinaryTree(vector<vector<int>> descriptions)
{
    int Root_Node_Val = -1;
    unordered_map<int, bool> Childs;

    for (vector<int> Single_Node : descriptions)
    {
        Childs[Single_Node[1]] = Single_Node[2];
    }

    for (vector<int> Single_Node : descriptions)
    {
        if (Childs.find(Single_Node[0]) == Childs.end())
        {
            Root_Node_Val = Single_Node[0];
            break;
        }
    }

    TreeNode *Root_Node = new TreeNode(Root_Node_Val);

    unordered_map<int, int> Left_Childs;
    unordered_map<int, int> Right_Childs;

    for (int i = 0; i < descriptions.size(); i++)
    {
        if (descriptions[i][2] == 1)
        {
            Left_Childs[descriptions[i][0]] = descriptions[i][1];
        }
        else
        {
            Right_Childs[descriptions[i][0]] = descriptions[i][1];
        }
    }

    // cout << "Left: " << endl;

    // for (auto x : Left_Childs)
    // {
    //     cout << x.first << " -> " << x.second << endl;
    // }

    // cout << "Right: " << endl;

    // for (auto x : Right_Childs)
    // {
    //     cout << x.first << " -> " << x.second << endl;
    // }


    Creation(Root_Node,Root_Node_Val,Left_Childs,Right_Childs);

    return Root_Node;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/
    Level_Order_Traversal(createBinaryTree(vector<vector<int>>{{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}}));
    Level_Order_Traversal(createBinaryTree(vector<vector<int>>{{1, 2, 1}, {2, 3, 0}, {3, 4, 1}}));
    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}