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
#define trav(a, x) for (auto &a : x)
#define all(con) con.begin(), con.end()
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
#define N 100005
bool dp[10001][10001];

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &a : arr)
        cin >> a;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    dp[0][0] = true;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> res;
    for(int i = 0; i <= sum/2; i++){
        if(dp[n][i])
            res.pb(i);
    }

    int m = INT_MAX;
    for(int i = 0; i < res.size(); i++)
        m = min(m, (sum - 2 * res[i]));
    cout << m;
}
int main()
{
    fastio;
    solve();
    cout << endl;
    return 0;
}