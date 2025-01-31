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

void DFS(vector<vector<int>> Grid, int i, int j, int Count_Ones, int &Res, bool Changed_Zero_To_One)
{
    if (i < 0 || j < 0 || i >= Grid.size() || j >= Grid[0].size())
        return;

    if (Grid[i][j] == 0 && Changed_Zero_To_One == true)
        return;

    int temp = Grid[i][j];
    Grid[i][j] = 0;

    if (temp == 0)
    {
        Changed_Zero_To_One = true;
    }

    Res = max(Res, Count_Ones);

    DFS(Grid, i + 1, j, Count_Ones + 1, Res, Changed_Zero_To_One);
    DFS(Grid, i - 1, j, Count_Ones + 1, Res, Changed_Zero_To_One);
    DFS(Grid, i, j + 1, Count_Ones + 1, Res, Changed_Zero_To_One);
    DFS(Grid, i, j - 1, Count_Ones + 1, Res, Changed_Zero_To_One);

    Grid[i][j] = temp;
    Changed_Zero_To_One = false;
}

int largestIsland(vector<vector<int>> grid)
{
    int res = 0;
    int Count_Zeros = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                DFS(grid, i, j, 1, res, false);
            }
            else
                Count_Zeros++;
        }
    }

    if (Count_Zeros == 0)
    {
        return grid.size() * grid.size();
    }

    return res == 0 ? res + 1 : res;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    cout << largestIsland(vector<vector<int>>{{1, 0}, {0, 1}}) << endl;
    cout << largestIsland(vector<vector<int>>{{1, 1}, {1, 0}}) << endl;
    cout << largestIsland(vector<vector<int>>{{1, 1}, {1, 1}}) << endl;
    cout << largestIsland(vector<vector<int>>{{0, 0}, {0, 1}}) << endl;
    cout << largestIsland(vector<vector<int>>{{0, 0}, {0, 0}}) << endl;

    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0}};

    cout << largestIsland(grid) << endl;

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