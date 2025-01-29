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

bool UnionSet(int U, int V, vector<int> &Parents, vector<int> &Ranks)
{
    int U_Parent = FindingParents(Parents, U);
    int V_Parent = FindingParents(Parents, V);

    if (U_Parent == V_Parent)
        return false;

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
    return true;
}

vector<int> Kruskals_Algorithm(vector<vector<int>> &Edges)
{
    vector<int> Parents(Edges.size() + 1);
    vector<int> Ranks(Edges.size() + 1, 0);

    for (int i = 1; i < Parents.size(); i++)
    {
        Parents[i] = i;
    }

    for (int i = 0; i < Edges.size(); i++)
    {

        if(!UnionSet(Edges[i][0], Edges[i][1], Parents, Ranks))
        {
            return {Edges[i][0],Edges[i][1]};
        }
    }

    return {};
}

vector<int> findRedundantConnection(vector<vector<int>> edges)
{
    return Kruskals_Algorithm(edges);
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    PrintVector(findRedundantConnection(vector<vector<int>>{{1, 2}, {1, 3}, {2, 3}}));
    PrintVector(findRedundantConnection(vector<vector<int>>{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}));

    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}