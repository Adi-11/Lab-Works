#include <bits/stdc++.h>
#include <iostream>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void BFS(int n)
{
    queue<int> que;
    que.push(n);
    visited[n] = true;
    while (!que.empty())
    {
        int top = que.front();
        que.pop();
        cout << top << " ";
        for (int i = 0; i < adj[top].size(); i++)
        {
            if (!visited[adj[top][i]])
            {
                que.push(adj[top][i]);
                visited[adj[top][i]] = true;
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
    BFS(1);
}
int main()
{
    solve();
    cout << endl;
    return 0;
}