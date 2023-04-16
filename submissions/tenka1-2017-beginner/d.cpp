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
  int N,K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
  ll res = 0;
  for (int i=29; i>=0; i--) {
    if (K & (1<<i)) {
      ll point = 0;
      rep(j,N) {
        if (A[j] < (1<<i))
          point += B[j];
      }
      res = max(res, point);
      rep(j,N) {
        if (A[j]&(1<<i))
          A[j] -= (1<<i);
      }
    }
  }
  ll point = 0;
  rep(i,N) {
    if (A[i] == 0)
      point += B[i];
  }
  res = max(res, point);
  print(res);
  return 0;
}
