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
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  bool fx, fy;
  vector<bool> dpx(1e4+1, false), dpy(1e4+1, false);
  int sx = A[0], sy = 0;
  dpx[A[0]] = true;
  dpy[0] = true;
  for (int i=1; i<N; i++) {
    if (i%2) {
      for (int j=1e4; j>=0; j--) {
        if (dpy[j])
          dpy[j+A[i]] = true;
      }
      sy += A[i];
    } else {
      for (int j=1e4; j>=0; j--) {
        if (dpx[j])
          dpx[j+A[i]] = true;
      }
      sx += A[i];
    }
  }
  if (sx+X < 0 || (sx+X)%2)
    fx = false;
  else
    fx = dpx[(sx+X)/2];
  if (sy+Y < 0 || (sy+Y)%2)
    fy = false;
  else
    fy = dpy[(sy+Y)/2];
  print((fx && fy ? Yes : No));
  return 0;
}
