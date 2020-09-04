#include <bits/stdc++.h>
#include <iostream>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t; cin >> t; while (t--)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
#define N 100005
bool dp[10001][10001];


void solve()
{
    int n, targetSum;
    cin >> n >> targetSum;
    vector<int>arr(n);

    for (auto &a: arr)
        cin >> a;

    dp[0][0] = true;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= targetSum; i++) {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[n][targetSum]) cout << "YES";
    else cout << "NO";
}

int main()
{
    fastio;
    test
    {
        solve();
    cout << endl;
    }
    return 0;
}