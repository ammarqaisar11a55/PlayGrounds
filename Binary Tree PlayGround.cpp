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

// Node for Binary Tree:
class TreeNode
{
public:
    int data;
    TreeNode *Left;
    TreeNode *Right;

    TreeNode(int data)
    {
        this->data = data;
        this->Left = NULL;
        this->Right = NULL;
    }
};

TreeNode *BuildBinaryTree(TreeNode *&Root)
{
    int Data;
    cout << "Enter Node Value(-1 for NULL): " << endl;
    cin >> Data;
    Root = new TreeNode(Data);

    if (Data == -1)
    {
        return NULL;
    }

    cout << "Value of Left Node of " << Data << ": ";
    Root->Left = BuildBinaryTree(Root->Left);
    cout << "Value of Right Node of " << Data << ": ";
    Root->Right = BuildBinaryTree(Root->Right);

    return Root;
}

void LevelOrderTraversal(TreeNode *Root)
{
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
            cout << Temp->data << " ";

            if (Temp->Left != NULL)
                Nodes.push(Temp->Left);

            if (Temp->Right != NULL)
                Nodes.push(Temp->Right);
        }
    }
}

void ReverseLevelOrderTraversal(TreeNode *Root)
{
    queue<TreeNode *> Nodes;
    stack<TreeNode *> ReverseOrder;

    Nodes.push(Root);
    Nodes.push(NULL);

    while (!Nodes.empty())
    {
        TreeNode *Temp = Nodes.front();
        Nodes.pop();

        if (Temp == NULL)
        {
            ReverseOrder.push(NULL);

            if (!Nodes.empty())
                Nodes.push(NULL);
        }
        else
        {
            ReverseOrder.push(Temp);

            if (Temp->Right != NULL)
                Nodes.push(Temp->Right);

            if (Temp->Left != NULL)
                Nodes.push(Temp->Left);
        }
    }

    while (!ReverseOrder.empty())
    {
        // TreeNode *Temp = ReverseOrder.top();
        // ReverseOrder.pop();

        if (ReverseOrder.top() == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << ReverseOrder.top()->data << " ";
        }

        ReverseOrder.pop();
    }
}

// Recursively:

void InOrderTraversalRecusively(TreeNode *Root)
{
    // LEFT , ROOT , RIGHT
    if (Root == NULL)
        return;

    InOrderTraversalRecusively(Root->Left);
    cout << Root->data << " ";
    InOrderTraversalRecusively(Root->Right);
}

void PreOrderTraversalRecusively(TreeNode *Root)
{
    // ROOT , LEFT , RIGHT
    if (Root == NULL)
        return;

    cout << Root->data << " ";
    PreOrderTraversalRecusively(Root->Left);
    PreOrderTraversalRecusively(Root->Right);
}

void PostOrderTraversalRecusively(TreeNode *Root)
{
    // LEFT , RIGHT , ROOT
    if (Root == NULL)
        return;

    PostOrderTraversalRecusively(Root->Left);
    PostOrderTraversalRecusively(Root->Right);
    cout << Root->data << " ";
}

// Itieratively:

void InOrderTraversalIteratively(TreeNode *Root)
{
    stack<TreeNode *> Nodes;
    TreeNode *Current = Root;

    while (Current != NULL || !Nodes.empty())
    {
        // Visit The Left Most Node:
        while (Current != NULL)
        {

            Nodes.push(Current);
            Current = Current->Left;
        }

        cout << Nodes.top()->data << " ";
        Current = Nodes.top();
        Nodes.pop();

        // Visit the Right Subtree:

        Current = Current->Right;
    }
}

void PreOrderTraversalIteratively(TreeNode *Root)
{
    if (Root == NULL)
        return;

    stack<TreeNode *> Nodes;
    Nodes.push(Root);

    while (!Nodes.empty())
    {
        TreeNode *Temp = Nodes.top();
        Nodes.pop();

        cout << Temp->data << " ";

        if (Temp->Right != NULL)
            Nodes.push(Temp->Right);

        if (Temp->Left != NULL)
            Nodes.push(Temp->Left);
    }
}

void PostOrderTraversalIteratively(TreeNode *Root)
{
    if (Root == NULL)
        return;

    stack<TreeNode *> N1, N2;

    N1.push(Root);

    while (!N1.empty())
    {
        TreeNode *Temp = N1.top();
        N1.pop();
        N2.push(Temp);

        if (Temp->Left != NULL)
            N1.push(Temp->Left);

        if (Temp->Right != NULL)
            N1.push(Temp->Right);
    }

    while (!N2.empty())
    {
        cout << N2.top()->data << " ";
        N2.pop();
    }
}

void BuildBinaryTreeFromLevelOrderTraversal(TreeNode *&Root)
{
    queue<TreeNode *> Nodes;

    int root_data;
    cout << "Enter Root Data: ";
    cin >> root_data;

    if (root_data == -1)
    {
        return;
    }

    Root = new TreeNode(root_data);

    Nodes.push(Root);

    while (!Nodes.empty())
    {
        TreeNode *Temp = Nodes.front();
        Nodes.pop();

        int Left_data;
        cout << "Enter Data for Left Node of " << Temp->data << " : ";
        cin >> Left_data;

        if (Left_data != -1)
        {
            Temp->Left = new TreeNode(Left_data);
            Nodes.push(Temp->Left);
        }

        int Right_data;
        cout << "Enter Data for Right Node of " << Temp->data << " : ";
        cin >> Right_data;

        if (Right_data != -1)
        {
            Temp->Right = new TreeNode(Right_data);
            Nodes.push(Temp->Right);
        }
    }
}

pair<int, int> diameter(TreeNode *Root)
{
    if (Root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> Left = diameter(Root->Left);
    pair<int, int> Right = diameter(Root->Right);

    int diameterofleft = Left.first;
    int diameterofRight = Right.first;
    int height = Left.second + Right.second + 1;

    pair<int, int> Ans;
    Ans.first = max(diameterofRight, max(diameterofleft, height));
    Ans.second = max(Left.second, Right.second) + 1;

    return Ans;
}

void PathsofTree(TreeNode *Root, string path)
{
    if (Root == NULL)
        return;

    path += to_string(Root->data);

    if (Root->Left == NULL && Root->Right == NULL)
    {
        cout << path << endl;
        path.pop_back();
    }
    else
    {
        path += "->";
    }

    PathsofTree(Root->Left, path);
    PathsofTree(Root->Right, path);
}

void Morris_PreOrder_Traversal(TreeNode *Root)
{
    if (Root == NULL)
        return;

    TreeNode *Current = Root;

    while (Current != NULL)
    {
        if (Current->Left == NULL)
        {
            cout << Current->data << " ";
            Current = Current->Right;
        }
        else
        {
            TreeNode *Temp = Current->Left;

            while (Temp->Right != NULL && Temp->Right != Current)
            {
                Temp = Temp->Right;
            }

            if (Temp->Right == NULL)
            {
                cout << Current->data << " ";
                Temp->Right = Current;
                Current = Current->Left;
            }
            else
            {
                Temp->Right = NULL;
                Current = Current->Right;
            }
        }
    }
}

void Morris_InOrder_Traversal(TreeNode *Root)
{
    if (Root == NULL)
        return;

    TreeNode *Current = Root;

    while (Current != NULL)
    {
        if (Current->Left == NULL)
        {
            cout << Current->data << " ";
            Current = Current->Right;
        }
        else
        {
            TreeNode *Temp = Current->Left;

            while (Temp->Right != NULL && Temp->Right != Current)
            {
                Temp = Temp->Right;
            }

            if (Temp->Right == NULL)
            {
                Temp->Right = Current;
                Current = Current->Left;
            }
            else
            {
                Temp->Right = NULL;
                cout << Current->data << " ";
                Current = Current->Right;
            }
        }
    }
}

void Morris_PostOrder_Traversal(TreeNode *root)
{
    vector<int> Result;
    TreeNode *Current = root;

    while (Current != NULL)
    {
        if (Current->Right == NULL)
        {
            Result.push_back(Current->data);
            Current = Current->Left;
        }
        else
        {
            TreeNode *Pre = Current->Right;

            while (Pre->Left != NULL && Pre->Left != Current)
            {
                Pre = Pre->Left;
            }

            if (Pre->Left == NULL)
            {
                Result.push_back(Current->data);
                Pre->Left = Current;
                Current = Current->Right;
            }
            else
            {
                Pre->Left = NULL;
                Current = Current->Left;
            }
        }
    }

    reverse(Result.begin(), Result.end());

    if (Result.empty())
    {
        cout << "Vector is empty ! " << endl;
        return;
    }

    for (int i = 0; i < Result.size(); i++)
        cout << Result[i] << " ";
}

//**************************************************************************************************/
//**************************************************************************************************/

int main()
{
    TreeNode *Root = NULL;

    // Creating Tree:
    Root = BuildBinaryTree(Root);

    // 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 13 -1 -1 7 14 -1 -1 -1
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1

    cout << "Level Order Traversal: " << endl;
    LevelOrderTraversal(Root);

    cout << "Inorder Traversal Recursively: " << endl;
    InOrderTraversalRecusively(Root);
    cout << endl;

    cout << "PreOrder Traversal Recursively: " << endl;
    PreOrderTraversalRecusively(Root);
    cout << endl;

    cout << "PostOrder Traversal Recursively: " << endl;
    PostOrderTraversalRecusively(Root);
    cout << endl;
    cout << endl;

    cout << " Reverse Level Order Traversal: " << endl;
    ReverseLevelOrderTraversal(Root);
    cout << endl;

    cout << "Inorder Traversal Iteratively: " << endl;
    InOrderTraversalIteratively(Root);
    cout << endl;

    cout << "PreOrder Traversal Iteratively: " << endl;
    PreOrderTraversalIteratively(Root);
    cout << endl;

    cout << "PostOrder Traversal Iteratively: " << endl;
    PostOrderTraversalIteratively(Root);
    cout << endl;
    cout << endl;

    cout << "Paths of Tree: " << endl;
    PathsofTree(Root, "");

    cout << endl
         << endl;
    cout << "Morris PreOrder Traversal: " << endl;
    Morris_PreOrder_Traversal(Root);

    cout << endl
         << endl;
    cout << "Morris Inorder Traversal: " << endl;
    Morris_InOrder_Traversal(Root);
    cout << endl;

    cout << "Morris PostOrder Traversal: " << endl;
    Morris_PostOrder_Traversal(Root);
    cout << endl;


    return 0;
}