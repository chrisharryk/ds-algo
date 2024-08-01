#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

void dfs(int start, vector<bool> &vis, vector<int> &ans, vector<int> adj[]) {
    vis[start] = 1;
    ans.push_back(start);
    for (int nbour : adj[start]) {
        if (!vis[nbour]) {
            dfs(nbour, vis, ans, adj);
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
    vector<bool> vis(V+1, 0);
    vector<int> ans;
    int start = 1;
    dfs(start, vis, ans, adj);
    for (int x : ans) cout << x << " ";
}