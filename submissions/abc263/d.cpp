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
  ll L,R;
  cin >> N >> L >> R;
  vector<ll> A(N);
  ll sum = 0;
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
  }
  vector<ll> S(N+1, 0);
  vector<ll> P(N+1, 0);
  P[0] = sum;
  rep(i,N) {
    sum -= A[i];
    sum += L;
    P[i+1] = sum;
  }
  rep(i,N) {
    P[i+1] = min(P[i+1], P[i]);
  }
  rep(i,N) {
    S[N-i-1] = A[N-i-1]+S[N-i];
  }
  ll res = 1e16;
  rep(i,N+1) {
    res = min(res, P[i]-S[i]+R*(N-i));
  }
  print(res);
  return 0;
}
