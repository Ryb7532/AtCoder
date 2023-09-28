#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
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
  ll P;
  cin >> N >> M >> P;
  vector<ll> A(N), B(M), S(N+1,0);
  rep(i,N) {
    cin >> A[i];
  }
  rep(j,M) {
    cin >> B[j];
  }
  sort(all(A));
  rep(i,N) {
    S[i+1] = S[i] + A[i];
  }
  ll res = 0;
  rep(j,M) {
    int i = lower_bound(all(A), P-B[j]) - A.begin();
    res += B[j]*i + S[i];
    res += P*(N-i);
  }
  print(res);
  return 0;
}