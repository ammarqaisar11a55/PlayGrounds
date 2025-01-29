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

int FindingParents(vector<int> &Parents, int Node)
{
    if (Parents[Node] == Node)
    {
        return Node;
    }

    return Parents[Node] = FindingParents(Parents, Parents[Node]);
}

void UnionSet(int U, int V, vector<int> &Parents, vector<int> &Ranks)
{
    int U_Parent = FindingParents(Parents, U);
    int V_Parent = FindingParents(Parents, V);

    if (U_Parent != V_Parent)
    {
        if (Ranks[U_Parent] < Ranks[V_Parent])
        {
            Parents[U_Parent] = V_Parent;
        }
        else if (Ranks[U_Parent] > Ranks[V_Parent])
        {
            Parents[V_Parent] = U_Parent;
        }
        else
        {
            Parents[U_Parent] = V_Parent;
            Ranks[V_Parent]++;
        }
    }
}

void Kruskals_Algorithm(vector<vector<int>> Edges, int Total_Nodes)
{
    vector<int> Parents(Total_Nodes);
    vector<int> Ranks(Total_Nodes, 0);

    for (int i = 0; i < Total_Nodes; i++)
    {
        Parents[i] = i;
    }

    sort(Edges.begin(), Edges.end(), [](vector<int> A, vector<int> B)
         { return A[2] < B[2]; });

    int Total_Minimum_Weight = 0;

    for (int i = 0; i < Edges.size(); i++)
    {
        int Parent_of_U = FindingParents(Parents, Edges[i][0]);
        int Parent_of_V = FindingParents(Parents, Edges[i][1]);
        int Weight = Edges[i][2];

        if (Parent_of_U != Parent_of_V)
        {
            Total_Minimum_Weight += Weight;
            UnionSet(Edges[i][0], Edges[i][1], Parents, Ranks);
        }
    }

    cout << Total_Minimum_Weight << endl;

    // Test Cases:

    // vector<vector<int>> Edges;

    // Edges.push_back({0, 1, 10});
    // Edges.push_back({0, 2, 6});
    // Edges.push_back({0, 3, 5});
    // Edges.push_back({1, 3, 15});
    // Edges.push_back({2, 3, 4});

    // Kruskals_Algorithm(Edges, 4);
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}