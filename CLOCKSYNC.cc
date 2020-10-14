#include <bits/stdc++.h>

using namespace std;

const int kClock = 16, kSwitch = 10, kInf = 1e4 - 1;
const vector<vector<int>> kLinked = {
  {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15},
  {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15},
  {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5},
  {3, 4, 5, 9, 13}
};

vector<int> clocks(kClock);

bool AreSync() {
  for (auto i : clocks) if (i != 12) return false;
  return true;
}

void Push(const int s) {
  for (auto i : kLinked[s]) {
    clocks[i] += 3;
    if (clocks[i] == 15) clocks[i] = 3;
  }
}

int CountSwitches(const int s) {
  if (s == kSwitch) return AreSync() ? 0 : kInf;
  int ret = kInf;
  for (int i = 0; i < 4; ++i) {
    ret = min(ret, i + CountSwitches(s + 1));
    Push(s);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    for (auto& i : clocks) cin >> i;
    const int ans = CountSwitches(0);
    cout << (ans == kInf ? -1 : ans) << '\n';
  }
  return 0;
}
