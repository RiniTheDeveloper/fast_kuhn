#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n, m;
array<vector<int>, N> g;
array<int, N> mt;
array<bool, N> used;

bool dfs(int v, int iter) {
  if (used[v] == iter) {
    return false;
  }
  used[v] = iter;
  
  for (auto u : g[v]) {
    if (mt[u] == -1) {
      mt[u] = v;
      return true;
    }
  }
  for (auto u : g[v]) {
    if (dfs(u, iter)) {
      mt[u] = v; 
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> m;
  
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(mt.begin(), mt.end() + 1, -1);

  int cnt = 0, it = 0;
  for (bool run = true; run; ++it) {
    run = false;
    
    for (int i = 0; i < n; ++i) {
      if (mt[i] == -1 && dfs(i, it)) {
        run = true;
        ++cnt;
      }
    }
  }
  cout << cnt;
}
