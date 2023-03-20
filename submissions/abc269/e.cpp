#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  int H,W;
  int hl=1,hr=N+1,wl=1,wr=N+1;
  while (hr-hl>1) {
    int m = (hl+hr)/2;
    print("? " << m << " " << hr-1 << " " << 1 << " " << N);
    int c;
    cin >> c;
    if (c == -1)
      return 0;
    if (c == hr-m)
      hr = m;
    else
      hl = m;
  }
  H = hl;
  while (wr-wl>1) {
    int m = (wl+wr)/2;
    print("? " << 1 << " " << N << " " << m << " " << wr-1);
    int c;
    cin >> c;
    if (c == -1)
      return 0;
    if (c == wr-m)
      wr = m;
    else
      wl = m;
  }
  W = wl;
  print("! " << H << " " << W);
  return 0;
}
