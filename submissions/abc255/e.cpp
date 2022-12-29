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
  int N,M;
  cin >> N >> M;
  vector<ll> S(N-1);
  vector<ll> X(M);
  rep(i,N-1) {
    cin >> S[i];
  }
  rep(i,M) {
    cin >> X[i];
  }
  vector<ll> Sadd(N);
  Sadd[0] = 0;
  rep(i,N-1) {
    Sadd[i+1] = Sadd[i];
    if (i%2) {
      Sadd[i+1] -= S[i];
    } else {
      Sadd[i+1] += S[i];
    }
  }
  int res = 0;
  map<ll, int> cntA0;
  rep(i,N) {
    rep(j,M) {
      ll A0;
      if (i%2) {
        A0 = Sadd[i] - X[j];
      } else {
        A0 = Sadd[i] + X[j];
      }
      cntA0[A0]++;
      res = max(res, cntA0[A0]);
    }
  }
  print(res);
  return 0;
}
