#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  sort(rall(A));
  ll res = 0;
  vector<ll> sum(N+1);
  sum[0] = 0;
  rep(i,N) {
    sum[i+1] = A[i] + sum[i];
  }
  ll l=0, u=2*A[0]+5;
  while (u-l>1) {
    ll m = (u+l)/2;
    ll cnt = 0;
    rep(i,N) {
      int il=-1, ir=N;
      ll v = m-A[i];
      while (ir-il>1) {
        int im = (ir+il)/2;
        if (A[im]>=v)
          il = im;
        else
          ir = im;
      }
      cnt += ir;
    }
    if (cnt>=M)
      l = m;
    else
      u = m;
  }
  rep(i,N) {
    int il=-1, ir=N;
    ll v = u-A[i];
    while (ir-il>1) {
      int im = (ir+il)/2;
      if (A[im]>=v)
        il = im;
      else
        ir = im;
    }
    res += ir*A[i] + sum[ir];
    M -= ir;
  }
  res += M * l;
  print(res);
  return 0;
}
