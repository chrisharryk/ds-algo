#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

void bfs(int V, vector<int> &ans, vector<int> adj[]) {
    vector<bool> vis(V+1, 0);
    int start = 1;
    queue<int> q;
    q.push(1);
    vis[start] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int nbour : adj[node]) {
            if (!vis[nbour]) {
                q.push(nbour);
                vis[nbour] = 1;
            }
        }
    }
}

int main() {
    vector<int> adj[] {
        {},
        {2, 3},
        {1, 3},
        {1, 2, 4},
        {3}
    };
    int V = 4;
    vector<int> ans;
    bfs(V, ans, adj);
    for (int x : ans) cout << x << " ";
}