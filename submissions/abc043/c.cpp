#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int a[N], ans = 1e9;
  for (int i=0; i<N; i++)
    cin >> a[i];
  for (int i=-100; i<=100; i++) {
    int c = 0;
    for (int j=0; j<N; j++) {
      c += (a[j]-i)*(a[j]-i);
    }
    ans = min(c, ans);
  }
  cout << ans << endl;
  return 0;
}