#include <bits/stdc++.h>

using namespace std;

vector<int> fences;

int GetMaxRectangle(const int left, const int right) {
  if (left == right) return fences[left];
  int mid = (left + right) / 2;
  int ret = max(GetMaxRectangle(left, mid), GetMaxRectangle(mid + 1, right));
  int l = mid, h = mid + 1, height = min(fences[l], fences[h]);
  ret = max(ret, height * 2);
  while (left < l || h < right) {
    if (h < right && (l == left || fences[l - 1] < fences[h + 1])) {
      ++h;
      height = min(height, fences[h]);
    } else {
      --l;
      height = min(height, fences[l]);
    }
    ret = max(ret, height * (h - l + 1));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    fences.resize(n);
    for (auto& i : fences) cin >> i;
    cout << GetMaxRectangle(0, n - 1) << '\n';
  }
  return 0;
}
