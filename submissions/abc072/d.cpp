#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int p[n];
  for (int i=0; i<n; i++)
    cin >> p[i];
  int ans = 0;
  bool lc = true;
  for (int i=0; i<n-1; i++) {
    if (p[i] == i+1) {
      ans++;
      if (i == n-2)
        lc = false;
      i++;
    }
  }
  if (lc && p[n-1] == n)
    ans++;
  cout << ans << '\n';
  return 0;
}