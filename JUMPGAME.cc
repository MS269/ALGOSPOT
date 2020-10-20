#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> board, cache;

int CanReach(const int y, const int x) {
  if (y >= n || x >= n) return 0;
  if (y == n - 1 && x == n - 1) return 1;
  int& ret = cache[y][x];
  if (ret != -1) return ret;
  return ret = CanReach(y + board[y][x], x) || CanReach(y, x + board[y][x]);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    cin >> n;
    board.clear();
    board.resize(n, vector<int>(n));
    for (auto& i : board) for (auto& j : i) cin >> j;
    cache.clear();
    cache.resize(n, vector<int>(n, -1));
    cout << (CanReach(0, 0) ? "YES" : "NO") << '\n';
  }
  return 0;
}
