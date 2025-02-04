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

int maxAscendingSum(vector<int> nums)
{
    int res = 0;
    int sum = 0;
    int max_elemen = *max_element(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            sum += nums[i];

            if (i == nums.size() - 2)
            {
                sum += nums[i + 1];
            }
        }
        else
        {
            res = max(res, sum);
            sum = 0;
        }
    }

    res = max(res, sum);

    return max(res, max_elemen);
}

int Solve(vector<int> nums)
{
    unordered_map<int, int> mp;

    for (int c : nums)
        mp[c]++;

    int operations = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto x : mp)
        pq.push(x.second);

    while (!pq.empty())
    {
        int Top = pq.top();
        pq.pop();

        if (Top == 1)
            return -1;

        if (Top % 3 == 0)
        {
            operations += 1;
            Top -= 3;
        }
        else if (Top % 2 == 0)
        {
            operations += 1;
            Top -= 2;
        }
        else
        {
            operations += 1;
            Top -= 3;
        }

        if (Top > 0)
        {
            pq.push(Top);
        }
    }

    return operations;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    // cout << maxAscendingSum(vector<int>{10, 20, 30, 5, 10, 50}) << endl;
    // cout << maxAscendingSum(vector<int>{10, 20, 30, 40, 50}) << endl;
    // cout << maxAscendingSum(vector<int>{12, 17, 15, 13, 10, 11, 12}) << endl;
    // cout << maxAscendingSum(vector<int>{6,10,6}) << endl;

    cout << Solve(vector<int>{2, 3, 3, 2, 2, 4, 2, 3, 4}) << endl;
    cout << Solve(vector<int>{2, 3, 3, 2, 2, 4, 2, 3, 4}) << endl;
    cout << Solve(vector<int>{2, 3, 3, 2, 2, 4, 2, 3, 4}) << endl;
    cout << Solve(vector<int>{2, 1, 2, 2, 3, 3}) << endl;
    cout << Solve(vector<int>{14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12}) << endl;

    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}