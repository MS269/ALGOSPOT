#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> tgl, cache;

int Path(const int y, const int x) {
  if (y == n - 1) return tgl[y][x];
  int& ret = cache[y][x];
  if (ret != -1) return ret;
  return ret = max(Path(y + 1, x), Path(y + 1, x + 1)) + tgl[y][x];
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif // _DEBUG
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    cin >> n;
    tgl.clear();
    tgl.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j <= i; ++j)
        cin >> tgl[i][j];
    cache.clear();
    cache.resize(n, vector<int>(n, -1));
    cout << Path(0, 0) << '\n';
  }
  return 0;
}
