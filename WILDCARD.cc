#include <bits/stdc++.h>

using namespace std;

string wild, file;
vector<vector<int>> cache;

int Match(const int w, const int f) {
  int& ret = cache[w][f];
  if (ret != -1) return ret;
  const int ws = wild.size(), fs = file.size();
  if (w < ws && f < fs && (wild[w] == '?' || wild[w] == file[f]))
    return ret = Match(w + 1, f + 1);
  if (w == ws && f == fs) return ret = 1;
  if (wild[w] == '*')
    if (Match(w + 1, f) || (f < fs && Match(w, f + 1))) return ret = 1;
  return ret = 0;
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif // _DEBUG
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> wild >> n;
    vector<string> files;
    for (int i = 0; i < n; ++i) {
      cin >> file;
      cache.clear();
      cache.resize(wild.size() + 1, vector<int>(file.size() + 1, -1));
      if (Match(0, 0)) files.push_back(file);
    }
    sort(files.begin(), files.end());
    for (auto i : files) cout << i << '\n';
  }
  return 0;
}
