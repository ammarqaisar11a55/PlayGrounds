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

bool Ans(vector<int> nums)
{
    sort(nums.begin(), nums.end());

    int Prev_diff = nums[1] - nums[0];

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] - nums[i] != Prev_diff)
            return false;
    }

    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int> nums, vector<int> l, vector<int> r)
{
    vector<bool> Res;

    for (int i = 0; i < l.size(); i++)
    {
        vector<int> Sub_Array;

        for (int j = l[i]; j <= r[i]; j++)
        {
            Sub_Array.push_back(nums[j]);
        }

        Res.push_back(Ans(Sub_Array));
    }

    return Res;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    PrintVector(checkArithmeticSubarrays(vector<int>{4, 6, 5, 9, 3, 7}, vector<int>{0, 0, 2}, vector<int>{2, 3, 5}));
    PrintVector(checkArithmeticSubarrays(vector<int>{-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10}, vector<int>{0, 1, 6, 4, 8, 7}, vector<int>{4, 4, 9, 7, 9, 10}));

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