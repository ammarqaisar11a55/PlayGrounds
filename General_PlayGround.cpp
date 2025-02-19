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

void Solve(int Current_Row, int Queens, int N_RS_CLS, vector<string> Board, vector<vector<string>> &Res, unordered_set<int> &Used_Rows, unordered_set<int> &Used_Cols, unordered_set<int> &Used_Di, unordered_set<int> &Used_AntiDi)
{
    if (Queens == 0)
    {
        Res.push_back(Board);
        return;
    }

    for (int i = Current_Row; i < N_RS_CLS; i++)
    {
        for (int j = 0; j < N_RS_CLS; j++)
        {
            if (Used_Rows.find(i) != Used_Rows.end())
                continue;

            if (Used_Cols.find(j) != Used_Cols.end())
                continue;

            if (Used_Di.find(i - j) != Used_Di.end())
                continue;

            if (Used_AntiDi.find(i + j) != Used_AntiDi.end())
                continue;

            Board[i][j] = 'Q';
            Used_Rows.insert(i);
            Used_Cols.insert(j);
            Used_Di.insert(i - j);
            Used_AntiDi.insert(i + j);
            
            Solve(i + 1, Queens - 1, N_RS_CLS, Board, Res, Used_Rows, Used_Cols, Used_Di, Used_AntiDi);
            
            Board[i][j] = '.';
            Used_Rows.erase(i);
            Used_Cols.erase(j);
            Used_Di.erase(i - j);
            Used_AntiDi.erase(i + j);
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> Res;
    unordered_set<int> Used_Rows, Used_Cols, Used_Di, Used_AntiDi;
    vector<string> Board(n, string(n, '.'));
    Solve(0,n,n,Board,Res,Used_Rows,Used_Cols,Used_Di,Used_AntiDi);
    return Res;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    // freopen("Output.txt", "w", stdout);

    PrintMatrixVector(solveNQueens(4));
    PrintMatrixVector(solveNQueens(1));

    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/
    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}