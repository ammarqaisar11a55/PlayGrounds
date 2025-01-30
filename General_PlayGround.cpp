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

template <typename T>
void Print(T D)
{
    cout << D << end;
}

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

void DFS(vector<vector<int>> &grid, int i, int j, int ups, int downs, int lefts, int rights, int &Res)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
        return;

    if (grid[i][j] == 2)
    {
        Res += ups > 0 && downs > 0 && lefts > 0 && rights > 0 ? 1 : 0;
        return;
    }

    int temp = grid[i][j];
    grid[i][j] = -1;

    DFS(grid, i + 1, j, ups, downs + 1, lefts, rights, Res);
    DFS(grid, i - 1, j, ups + 1, downs, lefts, rights, Res);
    DFS(grid, i, j - 1, ups, downs, lefts + 1, rights, Res);
    DFS(grid, i, j + 1, ups, downs, lefts, rights + 1, Res);

    grid[i][j] = temp;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    int Res = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                DFS(grid, i, j, 0, 0, 0, 0, Res);
                break;
            }
        }
    }

    return Res;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    vector<vector<int>> test1 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    cout << uniquePathsIII(test1) << endl; // Expected output: 2

    vector<vector<int>> test2 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    cout << uniquePathsIII(test2) << endl; // Expected output: 4

    vector<vector<int>> test3 = {{0, 1}, {2, 0}};
    cout << uniquePathsIII(test3) << endl; // Expected output: 0

    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}

/*Dry Run:*/
// C: 1    RES: 1
// C: 10    RES: 1,10
// C: 11    RES: 1,10,11
// C: 1    RES: 1
// C: 1    RES: 1