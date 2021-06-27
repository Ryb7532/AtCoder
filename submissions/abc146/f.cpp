#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  int mvcnt[n+1], to = n, nextto = n;
  mvcnt[n] = 0;
  for (int i=0; i<n; i++)
    mvcnt[i] = -1;
  for (int i=n-1; i>=0; i--) {
    if (to-i > m) {
      if (to == nextto) {
        cout << -1 << endl;
        return 0;
      }
      to = nextto;
    }
    if (s[i] == '1')
      continue;
    nextto = i;
    mvcnt[i] = mvcnt[to]+1;
  }
  int cnt = mvcnt[0]-1, grid = 0;
  for (int i=1; i<=n; i++) {
    if (mvcnt[i] == cnt) {
      cout << i-grid << ' ';
      grid = i;
      cnt--;
    }
  }
  cout << endl;
  return 0;
}
