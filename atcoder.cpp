#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin>>s;
    
    int number = stoi(s.substr(3,3));

    cout<<(number != 316 && number < 350 ? "YES" : "NO");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    // cin.ignore();
    while (TC--) solve();
}