#include <iostream>
#include <string>

using namespace std;

int main() {
  int c;
  cin >> c;
  while (c--) {
    string name;
    cin >> name;
    cout << "Hello, " << name << "!\n";
  }

  return 0;
}
