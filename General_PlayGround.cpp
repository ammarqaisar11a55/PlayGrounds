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

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    return 0;
}

void TestCase1()
{
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score = {1, 0, 9, 5, 0, 3, 2, 3, 4, 0, 8, 6, 7, 2, 5, 8, 9, 6, 9, 9, 9, 1, 4, 1, 3, 3};
    cout << "TEST CASE 1: " << maxScoreWords(words, letters, score) << endl;
}

void TestCase2()
{
    vector<string> words = {"xxxz", "ax", "bx", "cx"};
    vector<char> letters = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    vector<int> score = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    cout << "TEST CASE 2: " << maxScoreWords(words, letters, score) << endl;
}

void TestCase3()
{
    vector<string> words = {"leetcode"};
    vector<char> letters = {'l', 'e', 't', 'c', 'o', 'd'};
    vector<int> score = {1, 0, 9, 5, 0, 3, 2, 3, 4, 0, 8, 6, 7, 2, 5, 8, 9, 6, 9, 9, 9, 1, 4, 1, 3, 3};
    cout << "TEST CASE 3: " << maxScoreWords(words, letters, score) << endl;
}

int maxSatisfaction(vector<int> satisfaction)
{
    int res = 0;

    sort(satisfaction.begin(),satisfaction.end());

    

    return res = 0;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    // TestCase1();
    // TestCase2();
    // TestCase3();

    cout<<maxSatisfaction(vector<int>{-1,-8,0,5,-9})<<endl;
    cout<<maxSatisfaction(vector<int>{4,3,2})<<endl;
    cout<<maxSatisfaction(vector<int>{-1,-4,-5})<<endl;

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