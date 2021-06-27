#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n], ans[n];
  for (int i=0; i<n; i++)
    cin >> a[i];
  int f = 0, b = n-1;
  for (int i=0; i<n; i++) {
    if (i%2) {
      ans[b] = a[n-i-1];
      b--;
    } else {
      ans[f] = a[n-i-1];
      f++;
    }
  }
  for (int i=0; i<n; i++)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}