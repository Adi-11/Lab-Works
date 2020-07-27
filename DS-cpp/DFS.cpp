#include <bits/stdc++.h>
#include <iostream>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs_r(int n)
{
    visited[n] = true;
    cout << n << " ";
    for (int i = 0; i < adj[n].size(); i++)
    {
        if (!visited[adj[n][i]])
            dfs_r(adj[n][i]);
    }
}

void dfs_i(const vector<vector<int>> &adj, int n)
{
    stack<int> stk;
    stk.push(n);
    visited[n] = true;
    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();
        cout << curr << " ";
        for (int i = 0; i < adj[curr].size(); i++)
        {
            if (!visited[adj[curr][i]])
            {
                stk.push(adj[curr][i]);
                visited[adj[curr][i]] = true;
            }
        }
    }
}

void solve()
{
    int nodes, edges, x, y;
    cin >> nodes;
    cin >> edges;
    adj = vector<vector<int>>(nodes + 1);
    visited = vector<bool>(nodes + 1);
    cout << adj.size() << " " << visited.size() << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < visited.size(); i++)
        visited[i] = false;
    // dfs_r(1);
    dfs_i(adj, 1);
}
int main()
{
    solve();
    cout << endl;
    return 0;
}