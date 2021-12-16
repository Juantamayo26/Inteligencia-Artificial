#include <bits/stdc++.h>

using namespace std;

void dfs(char u, vector<vector<char>> &g, vector<char> &vis) {
  vis[u] = 1;
  cout << u << endl;
  for (auto i : g[u]) {
    if (!vis[i]) {
      dfs(i, g, vis);
    }
  }
}

int main() {
  int n;
  char a, b;
  cin >> n;
  vector<vector<char>> g(1e6);
  vector<char> vis(1e6);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    g[a].push_back(b);
  }
  dfs('A', g, vis);
  return 0;
}
