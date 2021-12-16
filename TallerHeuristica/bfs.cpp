#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  char a, b;
  cin >> n;
  vector<char> vis(1e6);
  vector<vector<char>> g(1e6);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    g[a].push_back(b);
  }
  queue<char> q;
  vis['A'] = 1;
  q.push('A');
  while (q.size() > 0) {
    auto u = q.front();
    vis[u] = 1;
    cout << u << endl;
    q.pop();
    for (auto i : g[u]) {
      if (!vis[i]) {
        q.push(i);
      }
    }
  }
  return 0;
}
