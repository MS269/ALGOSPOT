#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n, l;
    cin >> n >> l;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
      cin >> cost[i];
    double min_avg_cost = numeric_limits<double>::max();
    for (int i = l; i <= n; i++) {
      for (int j = 0; j <= n - i; j++) {
        double avg_cost = 0;
        for (int k = j; k < j + i; k++)
          avg_cost += cost[k];
        avg_cost /= i;
        min_avg_cost = min(min_avg_cost, avg_cost);
      }
    }
    cout << fixed << setprecision(10) << min_avg_cost << "\n";
  }

  return 0;
}
