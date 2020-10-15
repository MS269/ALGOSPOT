#include <bits/stdc++.h>

using namespace std;

string Reverse(string::iterator& it) {
  char cur = *it;
  ++it;
  if (cur == 'b' || cur == 'w') return string(1, cur);
  string ul = Reverse(it);
  string ur = Reverse(it);
  string ll = Reverse(it);
  string lr = Reverse(it);
  return string("x") + ll + lr + ul + ur;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c;
  cin >> c;
  while (c--) {
    string compressed_quad_tree;
    cin >> compressed_quad_tree;
    auto it = compressed_quad_tree.begin();
    cout << Reverse(it) << '\n';
  }
  return 0;
}
