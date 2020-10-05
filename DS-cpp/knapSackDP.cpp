#include <bits/stdc++.h>
#include <iostream>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
#define N 100005
int dp[10001][10001];

void solve()
{
    int n, max_wt;
    cin >> n >> max_wt;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < max_wt + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][max_wt];
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