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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  ll K;
  cin >> N >> M >> K;
  vector<int> A(N), B(N), C(M), D(M);
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
  rep(i,M) {
    cin >> C[i] >> D[i];
  }
  ld l = 0.0, r = 100.0;
  while (r-l > 1e-9) {
    ll cnt = 0;
    ld m = (r+l)/2;
    vector<ld> CD(M);
    rep(i,M) {
      CD[i] = m * (C[i]+D[i]) - 100 * C[i];
    }
    sort(all(CD));
    rep(i,N) {
      ld AB = 100 * A[i] - m * (A[i]+B[i]);
      int li = -1, ri = M;
      while (ri-li > 1) {
        int mi = (ri+li)/2;
        if (CD[mi]<=AB) {
          li = mi;
        } else {
          ri = mi;
        }
      }
      cnt += ri;
    }
    if (cnt >= K) {
      l = m;
    } else {
      r = m;
    }
  }
  print(fix(10) << l);
  return 0;
}
