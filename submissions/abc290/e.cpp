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
  int N;
  cin >> N;
  vector<vector<ll>> P(N);
  rep(i,N) {
    int A;
    cin >> A;
    A--;
    P[A].push_back(min(i+1, N-i));
  }
  ll res = 0;
  rep(i,N) {
    ll l = min(i+1, N-i);
    res += (N-i-l+1)*l;
    res += l*(l-1)/2;
  }
  rep(i,N) {
    sort(all(P[i]));
    int s = P[i].size();
    rep(j,s) {
      res -= P[i][j]*(s-j);
    }
  }
  print(res);
  return 0;
}
