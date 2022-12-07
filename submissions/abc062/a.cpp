#include <bits/stdc++.h>
using namespace std;

int main() {
  int group[12] = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0}, x, y;
  cin >> x >> y;
  x--;
  y--;
  if (group[x] == group[y])
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
