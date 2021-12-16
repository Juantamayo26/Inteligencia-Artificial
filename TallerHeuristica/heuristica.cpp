#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

const int N = 1e3;
int dp[N];
int edges[N];
vector<vector<ii>> g(N);

int dfs(int u, int jugador) {
  dp[u] = INT_MIN;
  edges[u] = -1;
  if (!jugador) {
    pair<int, int> maxBlack = {-1, -1};
    for (auto i : g[u]) {
      if (i.second > maxBlack.second) {
        maxBlack.first = i.first;
        maxBlack.second = i.second;
      }
    }
    dp[u] = -1 * maxBlack.second - dfs(maxBlack.first, jugador ^ 1);
    edges[u] = maxBlack.first;
  } else {
    for (auto i : g[u]) {
      int cost = dfs(i.first, jugador ^ 1) + i.second;
      if (dp[u] < cost) {
        dp[u] = cost;
        edges[u] = i.first;
      }
    }
  }
  return (edges[u] == -1) ? 0 : dp[u];
}

int main() {
  int m;
  cin >> m;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  dfs(1, 1);
  int curr = 1;
  cout << "El puntaje es: " << endl;
  cout << dp[1] << endl;
  cout << "La posible jugada es: " << endl;
  cout << 1;
  while (edges[curr] != -1) {
    cout << " " << edges[curr];
    curr = edges[curr];
  }
  cout << endl;
}
