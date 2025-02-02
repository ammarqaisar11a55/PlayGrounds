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

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    int id = 0;
    unordered_map<char, int> Characterd_Ids;
    unordered_map<int, char> Ids_with_Characters_group;

    for (int i = 0; i < s1.length(); i++)
    {
        char s1_character = s1[i];
        char s2_character = s2[i];

        

        
        if(Ids_with_Characters_group.find(id)!=Ids_with_Characters_group.end())
        {
            id++;
        }
    }

    string res;

    for (auto X : Ids_with_Characters_group)
    {
        cout << X.first << ": "<<X.second;

        cout << endl;
    }

    for (int i = 0; i < baseStr.length(); i++)
    {
        if (Characterd_Ids.find(baseStr[i]) != Characterd_Ids.end())
        {
            int Char_ID = Characterd_Ids[baseStr[i]];
            char Character_to_append = Ids_with_Characters_group[Char_ID];
            res.push_back(Character_to_append);
        }
        else
            res.push_back(baseStr[i]);
    }

    return res;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    /************************************** Input Test Cases: **************************/

    cout << smallestEquivalentString("parker", "morris", "parser") << endl;
    cout << smallestEquivalentString("hello", "world", "hold") << endl;
    cout << smallestEquivalentString("leetcode", "programs", "sourcecode") << endl;

    /************************************************************************************/

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}