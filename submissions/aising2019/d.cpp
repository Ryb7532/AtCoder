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
  int N,Q;
  cin >> N >> Q;
  vector<ll> A(N+1);
  vector<ll> B(N+1,0), C(N+1,0);
  rep(i,N) {
    cin >> A[i];
    B[i+1] = B[i]+A[i];
    C[i+1] = C[i];
    if (N%2 != i%2)
      C[i+1] += A[i];
  }
  A[N] = 2e9+5;
  rep(_,Q) {
    ll X;
    cin >> X;
    int l = 0, r = N;
    while (r-l > 1) {
      int m = (r+l)/2;
      if (A[m] < X) {
        l = m;
        continue;
      }
      int lid = lower_bound(all(A), 2*X-A[m])-A.begin();
      if (N-m-1 > m-lid)
        l = m;
      else
        r = m;
    }
    print(C[max(0,2*r-N)]+B[N]-B[r]);
  }
  return 0;
}
