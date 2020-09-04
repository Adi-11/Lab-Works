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
int dp[10001][10001];

void solve()
{
    int n, diff;
    cin >> n >> diff;
    vector<int> arr(n);
    for(auto &a: arr)
        cin >> a;
    
    int sum = accumulate(arr.begin(), arr.end(), 0);
    /*
    When we observe the steps to solve the questions
    then :
    sum(s1) - sum(s2) = diff
    sum(s1) + sum(s2) = sum of array;
    and the final result(treated as target) is simply: diff + sum of array / 2;
    and this question simply becomes subset-Sum-count
    */
    int target = (sum + diff) / 2;    
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= target; i++)
        dp[0][i] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else 
                dp[i][j] = dp[i - 1][j];

        }
    }
    cout << dp[n][target];

}
int main()
{
    fastio;
    solve();
    cout << endl;
    return 0;
}