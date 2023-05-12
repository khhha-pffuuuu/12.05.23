#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 500;
int n, m;
vector<int> adj[MAXN];
int match[MAXN];
bool visited[MAXN];

bool dfs(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int max_bipartite_matching() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        fill(visited, visited + n, false);
        if (dfs(i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(match, match + n, -1);
    int cnt = max_bipartite_matching();
    cout << cnt << endl;
    return 0;
}