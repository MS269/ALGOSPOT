#include <bits/stdc++.h>

using namespace std;

const int kN = 1e1 + 5;

int n, m;
bool are_friends[kN][kN];
bool is_pair[kN];

int CountPairs() {
  int first_solo = -1;
  for (int i = 0; i < n; ++i) {
    if (!is_pair[i]) {
      first_solo = i;
      break;
    }
  }
  if (first_solo == -1) return 1;
  int ret = 0;
  for (int i = first_solo + 1; i < n; ++i) {
    if (!is_pair[i] && are_friends[first_solo][i]) {
      is_pair[first_solo] = is_pair[i] = true;
      ret += CountPairs();
      is_pair[first_solo] = is_pair[i] = false;
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    cin >> n >> m;
    memset(are_friends, false, sizeof(are_friends));
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      are_friends[a][b] = are_friends[b][a] = true;
    }
    cout << CountPairs() << '\n';
  }
  return 0;
}
