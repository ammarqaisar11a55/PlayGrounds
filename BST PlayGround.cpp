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

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void Build_Binary_Search_Tree(TreeNode *&root, int data)
{
    if (root == nullptr)
    {
        root = new TreeNode(data);
        return;
    }

    if (root->val < data)
    {
        Build_Binary_Search_Tree(root->right, data);
    }
    else
        Build_Binary_Search_Tree(root->left, data);

    // Time Complexity : O(Log N)
    // Space Complexity : O(Log N)
}

void Search_In_Binary_Search_Tree(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        cout << x << " Not Found in Binary Search Tree" << endl;
        return;
    }

    TreeNode *temp = root;

    while (temp != nullptr)
    {
        if (temp->val == x)
        {
            cout << x << " Found in Binary Search Tree" << endl;
            return;
        }

        if (temp->val < x)
        {
            temp = temp->right;
        }
        else
            temp = temp->left;
    }

    cout << x << " Not Found in Binary Search Tree" << endl;
}

void PreOrder_Traversal_Recursively(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";

    PreOrder_Traversal_Recursively(root->left);
    PreOrder_Traversal_Recursively(root->right);
}

void InOrder_Traversal_Recursively(TreeNode *root)
{
    if (root == nullptr)
        return;

    InOrder_Traversal_Recursively(root->left);
    cout << root->val << " ";
    InOrder_Traversal_Recursively(root->right);
}

void PostOrder_Traversal_Recursively(TreeNode *root)
{
    if (root == nullptr)
        return;

    PostOrder_Traversal_Recursively(root->left);
    PostOrder_Traversal_Recursively(root->right);
    cout << root->val << " ";
}

void Level_Order_Traversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> Nodes;
    Nodes.push(root);
    Nodes.push(nullptr);

    while (!Nodes.empty())
    {
        TreeNode *temp = Nodes.front();
        Nodes.pop();

        if (temp == nullptr)
        {
            cout << endl;

            if (!Nodes.empty())
                Nodes.push(nullptr);
        }
        else
        {
            cout << temp->val << " ";

            if (temp->left != nullptr)
                Nodes.push(temp->left);

            if (temp->right != nullptr)
                Nodes.push(temp->right);
        }
    }
}

void Paths_of_Binary_Search_Tree(TreeNode *root, string path)
{
    if (root == nullptr)
        return;

    path += to_string(root->val);

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << path << endl;
    }
    else
    {
        path += "->";
    }

    Paths_of_Binary_Search_Tree(root->left, path);
    Paths_of_Binary_Search_Tree(root->right, path);
}

void MinimumAndMaximumNode(TreeNode *root)
{
    TreeNode *temp = root;

    while (temp->left != nullptr)
    {
        temp = temp->left;
    }

    cout << "Minimum Node: " << temp->val << endl;

    temp = root;

    while (temp->right != nullptr)
    {
        temp = temp->right;
    }

    cout << "Maximum Node: " << temp->val << endl;
}

int Minimumval(TreeNode *root)
{
    TreeNode *temp = root;

    while (temp->left != nullptr)
    {
        temp = temp->left;
    }

    return temp->val;
}

TreeNode *Delete_Node_Of_Binary_Search_Tree(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->val == x)
    {
        // If This node has no child:
        if (root->left == nullptr && root->left == nullptr)
        {
            delete root;
            return nullptr;
        }

        // If This node has one child:
        // if it is right:

        if (root->left == nullptr && root->right != nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        // If This node has one child:
        // if it is left:

        if (root->left != nullptr && root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // If child has two childs:
        if (root->left != nullptr && root->right != nullptr)
        {
            // Either Take minimum value from right or maximum value from left and then delete that node from that side
            int mini = Minimumval(root->right);
            root->val = mini;
            root->right = Delete_Node_Of_Binary_Search_Tree(root->right, mini);
            return root;
        }
    }

    if (root->val > x)
    {
        root->left = Delete_Node_Of_Binary_Search_Tree(root->left, x);
        return root;
    }
    else
    {
        root->right = Delete_Node_Of_Binary_Search_Tree(root->right, x);
        return root;
    }
}

void Reverse_Level_Order_Traversal(TreeNode *Root)
{
    queue<TreeNode *> Nodes;
    stack<TreeNode *> ReverseNodes;

    Nodes.push(Root);
    Nodes.push(NULL);

    while (!Nodes.empty())
    {
        TreeNode *Temp = Nodes.front();
        Nodes.pop();

        if (Temp == NULL)
        {
            ReverseNodes.push(NULL);
            if (!Nodes.empty())
                Nodes.push(NULL);
        }
        else
        {
            ReverseNodes.push(Temp);

            if (Temp->right)
                Nodes.push(Temp->right);

            if (Temp->left)
                Nodes.push(Temp->left);
        }
    }

    while (!ReverseNodes.empty())
    {
        if (ReverseNodes.top() == NULL)
        {
            cout << endl;
        }
        else
            cout << ReverseNodes.top()->val << " ";

        ReverseNodes.pop();
    }
}

void InOrder_Traversal_Iteratively(TreeNode *root)
{
    stack<TreeNode *> Nodes;
    TreeNode *Current = root;

    while (Current != NULL || !Nodes.empty())
    {
        while (Current != NULL)
        {
            Nodes.push(Current);
            Current = Current->left;
        }

        cout << Nodes.top()->val << " ";
        Current = Nodes.top();
        Nodes.pop();

        Current = Current->right;
    }
}

void PreOrder_Traversal_Iteratively(TreeNode *root)
{
    stack<TreeNode *> Nodes;
    Nodes.push(root);

    while (!Nodes.empty())
    {
        TreeNode *Temp = Nodes.top();
        Nodes.pop();

        cout << Temp->val << " ";

        if (Temp->right != NULL)
            Nodes.push(Temp->right);

        if (Temp->left != NULL)
            Nodes.push(Temp->left);
    }
}

void PostOrder_Traversal_Iteratively(TreeNode *root)
{
    stack<TreeNode *> N1, N2;

    N1.push(root);

    while (!N1.empty())
    {
        TreeNode *temp = N1.top();
        N1.pop();
        N2.push(temp);

        if (temp->left)
            N1.push(temp->left);

        if (temp->right)
            N1.push(temp->right);
    }

    while (!N2.empty())
    {
        cout << N2.top()->val << " ";
        N2.pop();
    }
}

void Morris_InOrder_Traversal(TreeNode *root)
{
    if (root == NULL)
        return;

    TreeNode *Current = root;

    while (Current != NULL)
    {
        if (Current->left == NULL)
        {
            cout << Current->val << " ";
            Current = Current->right;
        }
        else
        {
            TreeNode *Pre = Current->left;
            while (Pre->right != NULL && Pre->right != Current)
            {
                Pre = Pre->right;
            }

            if (Pre->right == NULL)
            {
                Pre->right = Current;
                Current = Current->left;
            }
            else
            {
                Pre->right = NULL;
                cout << Current->val << " ";
                Current = Current->right;
            }
        }
    }
}

void Morris_PreOrder_Traversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    TreeNode *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->val << " ";
            current = current->right;
        }
        else
        {
            TreeNode *Pre = current->left;

            while (Pre->right != NULL && Pre->right != current)
            {
                Pre = Pre->right;
            }

            if (Pre->right == NULL)
            {
                cout << current->val << " ";
                Pre->right = current;
                current = current->left;
            }
            else
            {
                Pre->right = NULL;
                current = current->right;
            }
        }
    }
}

void Morris_PostOrder_Traversal(TreeNode *root)
{
    if (root == NULL)
        return;

    vector<int> Nodes;

    TreeNode *Current = root;

    while (Current != NULL)
    {
        if (Current->right == NULL)
        {
            Nodes.push_back(Current->val);
            Current = Current->left;
        }
        else
        {
            TreeNode *pre = Current->right;

            while (pre->left != NULL && pre->left != Current)
            {
                pre = pre->left;
            }

            if (pre->left == NULL)
            {
                Nodes.push_back(Current->val);
                pre->left = Current;
                Current = Current->right;
            }
            else
            {
                pre->left = NULL;
                Current = Current->left;
            }
        }
    }

    reverse(Nodes.begin(), Nodes.end());

    for (auto x : Nodes)
    {
        cout << x << " ";
    }
}

//******************************************************************************************************/

//******************************************************************************************************/

int main()
{
    TreeNode *root = nullptr;

    cout << "Enter Binary Search Tree Data(-1 to exit): ";
    while (true)
    {
        int data;
        cin >> data;

        if (data == -1)
            break;

        Build_Binary_Search_Tree(root, data);
    }

    // 40 30 50 25 35 45 60 -1

    cout << endl;
    cout << "PreOrder Traversal Recursively: " << endl;
    PreOrder_Traversal_Recursively(root);
    cout << endl;

    cout << "PreOrder Traversal Iteratively: " << endl;
    PreOrder_Traversal_Iteratively(root);
    cout << endl;

    cout << "InOrder Traversal Recursively: " << endl;
    InOrder_Traversal_Recursively(root);
    cout << endl;

    cout << "InOrder Traversal Iteratively: " << endl;
    InOrder_Traversal_Iteratively(root);
    cout << endl;

    cout << "PostOrder Traversal Recursively: " << endl;
    PostOrder_Traversal_Recursively(root);
    cout << endl;

    cout << "PostOrder Traversal Iteratively: " << endl;
    PostOrder_Traversal_Iteratively(root);
    cout << endl;

    cout << "Level Order Traversal: " << endl;
    Level_Order_Traversal(root);
    cout << endl;

    cout << "Paths of Binary Search Tree: " << endl;
    Paths_of_Binary_Search_Tree(root, "");

    // int Value_To_Be_Searched;
    // cout<<"Enter value to be Searched In Binary Search Tree: "<<endl;
    // cin>>Value_To_Be_Searched;
    // Search_In_Binary_Search_Tree(root,Value_To_Be_Searched);

    cout << endl;
    MinimumAndMaximumNode(root);

    cout << endl;
    cout << "Reverse Level Order Traversal: " << endl;
    Reverse_Level_Order_Traversal(root);

    cout << endl;
    cout << "Morris Inorder Order Traversal: " << endl;
    Morris_InOrder_Traversal(root);

    cout << endl;
    cout << "Morris PreOrder Order Traversal: " << endl;
    Morris_PreOrder_Traversal(root);

    cout << endl;
    cout << "Morris PostOrder Traversal: " << endl;
    Morris_PostOrder_Traversal(root);

    return 0;
}