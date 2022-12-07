#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int a;
  long sum = 0;
  for (int i=0;i<m; i++) {
    cin >> a;
    sum += a;
  }
  long ans;
  if (sum > n)
    ans = -1;
  else
    ans = n - sum;
  cout << ans << endl;
  return 0;
}
