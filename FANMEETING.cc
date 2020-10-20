#include <bits/stdc++.h>

using namespace std;

vector<int> Multiply(const vector<int>& a, const vector<int>& b) {
  vector<int> ret(a.size() + b.size() + 1);
  for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < b.size(); ++j)
      ret[i + j] += a[i] * b[j];
  return ret;
}

void AddTo(vector<int>& a, const vector<int>& b, int k) {
  a.resize(max(a.size(), b.size() + k));
  for (int i = 0; i < b.size(); ++i) a[i + k] += b[i];
}

void SubFrom(vector<int>& a, const vector<int>& b) {
  a.resize(max(a.size(), b.size() + 1));
  for (int i = 0; i < b.size(); ++i) a[i] -= b[i];
}

vector<int> Karatsuba(const vector<int>& a, const vector<int>& b) {
  int n = a.size(), m = b.size();
  if (n < m) return Karatsuba(b, a);
  if (n == 0 || m == 0) return vector<int>();
  if (n <= 50) return Multiply(a, b);
  int half = n / 2;
  vector<int> a0(a.begin(), a.begin() + half);
  vector<int> a1(a.begin() + half, a.end());
  vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
  vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
  vector<int> z2 = Karatsuba(a1, b1), z0 = Karatsuba(a0, b0);
  AddTo(a0, a1, 0);
  AddTo(b0, b1, 0);
  vector<int> z1 = Karatsuba(a0, b0);
  SubFrom(z1, z0);
  SubFrom(z1, z2);
  vector<int> ret;
  AddTo(ret, z0, 0);
  AddTo(ret, z1, half);
  AddTo(ret, z2, half + half);
  return ret;
}

int CountHugs(const string& members, const string& fans) {
  int n = members.size(), m = fans.size();
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) a[i] = members[i] == 'M';
  for (int i = 0; i < m; ++i) b[m - i - 1] = fans[i] == 'M';
  vector<int> c = Karatsuba(a, b);
  int ret = 0;
  for (int i = n - 1; i < m; ++i) if (c[i] == 0) ++ret;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    string members, fans;
    cin >> members >> fans;
    cout << CountHugs(members, fans) << '\n';
  }
  return 0;
}
