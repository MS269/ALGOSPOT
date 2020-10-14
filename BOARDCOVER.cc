#include <bits/stdc++.h>

using namespace std;

const vector<vector<pair<int, int>>> kBlockType = {
  {{0, 0}, {1, 0}, {0, 1}},
  {{0, 0}, {0, 1}, {1, 1}},
  {{0, 0}, {1, 0}, {1, 1}},
  {{0, 0}, {1, 0}, {1, -1}}
};

int h, w;
vector<string> board;

pair<int, int> GetFirstBlank() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (board[i][j] == '.') {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

void Set(const pair<int, int> blank, const int type, const bool set) {
  for (int j = 0; j < 3; ++j) {
    const int ny = blank.first + kBlockType[type][j].first;
    const int nx = blank.second + kBlockType[type][j].second;
    board[ny][nx] = set ? '#' : '.';
  }
}

int CountCover() {
  auto first_blank = GetFirstBlank();
  if (first_blank == make_pair(-1, -1)) return 1;
  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    bool can_set = true;
    for (int j = 0; j < 3; ++j) {
      const int ny = first_blank.first + kBlockType[i][j].first;
      const int nx = first_blank.second + kBlockType[i][j].second;
      if (ny < 0 || ny >= h || nx < 0 || nx >= w || board[ny][nx] == '#') {
        can_set = false;
        break;
      }
    }
    if (can_set) {
      Set(first_blank, i, true);
      ret += CountCover();
      Set(first_blank, i, false);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    cin >> h >> w;
    board.resize(h);
    for (auto& i : board) cin >> i;
    cout << CountCover() << '\n';
  }
  return 0;
}
