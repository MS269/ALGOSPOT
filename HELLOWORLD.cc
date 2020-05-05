#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int c;
  cin >> c;
  while (c--) {
    string name;
    cin >> name;
    cout << "Hello, " << name << "!\n";
  }

  return 0;
}
