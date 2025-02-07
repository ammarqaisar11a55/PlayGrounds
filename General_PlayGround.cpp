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

vector<vector<char>> rotateTheBox(vector<vector<char>> box)
{
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/
    vector<vector<char>> box1 = {
        {'#', '.', '#'}};
    auto result1 = solution.rotateTheBox(box1);
    for (const auto &row : result1)
    {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }
    cout << "----------" << endl;

    // Test Case 2
    vector<vector<char>> box2 = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}};
    auto result2 = solution.rotateTheBox(box2);
    for (const auto &row : result2)
    {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }
    cout << "----------" << endl;

    // Test Case 3
    vector<vector<char>> box3 = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}};
    auto result3 = solution.rotateTheBox(box3);
    for (const auto &row : result3)
    {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }
    cout << "----------" << endl;
    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}