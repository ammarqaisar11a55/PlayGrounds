#include <iostream>
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
using namespace std;

//********************************************************************************* */

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void PrintVector(vector<ListNode *> a)
{
    cout << endl;
    cout << "[";

    for (int i = 0; i < a.size(); i++)
    {
        cout << (a[i])->val;
        if (i != a.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
    cout << endl;
}

void Print(ListNode *Head)
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

void InsertionAtHead(ListNode *&Head, ListNode *&Tail, int data)
{
    if (Head == NULL)
    {
        ListNode *Node = new ListNode(data);
        Head = Node;
    }
    else
    {
        ListNode *Node = new ListNode(data);
        Node->next = Head;
        Head = Node;
    }
}

void InsertionAtTail(ListNode *&Head, ListNode *&Tail, int data)
{
    if (Tail == NULL)
    {
        ListNode *Node = new ListNode(data);
        Tail = Node;
        Head = Node;
    }
    else
    {
        ListNode *Node = new ListNode(data);
        Tail->next = Node;
        Tail = Node;
    }
}
//**********************************************************************************/
void InsertAtTail(ListNode *&Head, ListNode *&Tail, ListNode *NodeToInsert)
{
    if (Tail == NULL)
    {
        Tail = NodeToInsert;
        Head = NodeToInsert;
    }
    else
    {
        Tail->next = NodeToInsert;
        Tail = NodeToInsert;
    }
    Tail->next = NULL;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    vector<ListNode *> Nodes;

    while (head != NULL)
    {
        Nodes.push_back(head);
        head = head->next;
    }

    ListNode *AnsHead = NULL;
    ListNode *AnsTail = NULL;

    for (int i = 0; i < Nodes.size(); i++)
    {
        if (Nodes.size() - 2 != i)
        {
            InsertAtTail(AnsHead, AnsTail, Nodes[i]);
        }
    }
    return AnsHead;
}
//**********************************************************************************/
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right || head == nullptr)
        return head;

    ListNode *Left_Pointer = head;
    ListNode *Right_Pointer = head;

    ListNode *Left_Pointer_Prev = nullptr;
    ListNode *Right_Pointer_Forward = nullptr;

    // while (left - 1 > 0)
    // {
    //     Left_Pointer_Prev = Left_Pointer;

    //     Left_Pointer = Left_Pointer->next;
    //     Right_Pointer = Right_Pointer->next;

    //     left--;
    //     right--;
    // }

    for (int i = 1; i < left; i++)
    {
        Left_Pointer_Prev = Left_Pointer;
        Left_Pointer = Left_Pointer->next;
    }

    // while (right - 1 > 0)
    // {
    //     Right_Pointer = Right_Pointer->next;
    //     Right_Pointer_Forward = Right_Pointer->next;
    //     right--;
    // }

    for (int i = 1; i < right; i++)
    {
        Right_Pointer = Right_Pointer->next;
    }

    Right_Pointer_Forward = Right_Pointer->next;

    if (Left_Pointer_Prev != nullptr)
    {
        Left_Pointer_Prev->next = nullptr;
    }

    Right_Pointer->next = nullptr;

    ListNode *Current = Left_Pointer;
    ListNode *Forward = nullptr;
    ListNode *Previous = nullptr;

    while (Current != nullptr)
    {
        Forward = Current->next;
        Current->next = Previous;
        Previous = Current;
        Current = Forward;
    }

    if (Left_Pointer_Prev != nullptr)
    {
        Left_Pointer_Prev->next = Previous;
    }
    else
    {
        head = Previous;
    }

    Left_Pointer->next = Right_Pointer_Forward;

    // cout << "Left Prev: " << Left_Pointer_Prev->val << endl;
    // cout << "Left: " << Left_Pointer->val << endl;

    // cout << "Right: " << Left_Pointer->val << endl;
    // cout << "Right Forward: " << Right_Pointer_Forward->val << endl;

    return head;
}

int main()
{

    //**************************************Test Case1:**************************************

    cout << "TEST CASE 1: " << endl
         << endl;

    ListNode *Head1 = NULL;
    ListNode *Tail1 = NULL;

    vector<int> List1 = {3, 5};

    for (int i = 0; i < List1.size(); i++)
        InsertionAtTail(Head1, Tail1, List1[i]);

    // Print(Head1);
    Print(reverseBetween(Head1, 1, 2));

    //**************************************Test Case2:**************************************

    // cout << "TEST CASE 2: " << endl;

    // ListNode *Head3 = NULL;
    // ListNode *Tail3 = NULL;

    // ListNode *Head4 = NULL;
    // ListNode *Tail4 = NULL;

    // vector<int> List3 = {9, 9, 9, 9, 9, 9, 9};
    // vector<int> List4 = {9, 9, 9, 9};

    // for (int i = 0; i < List3.size(); i++)
    //     InsertionAtTail(Head3, Tail3, List3[i]);

    // for (int i = 0; i < List4.size(); i++)
    //     InsertionAtTail(Head4, Tail4, List4[i]);

    // Print(Head3);
    // Print(Head4);
    // Print(addTwoNumbers(Head3, Head4));

    // cout << endl
    //      << endl;

    return 0;
}