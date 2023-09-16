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
  ll X,Y;
  cin >> N >> X >> Y;
  vector<int> P(N-1), T(N-1);
  rep(i,N-1) {
    cin >> P[i] >> T[i];
  }
  vector<ll> D(840);
  rep(i,840) {
    ll t = i;
    rep(j,N-1) {
      if (t%P[j]) {
        t += P[j]-t%P[j];
      }
      t += T[j];
    }
    D[i] = t+Y;
  }
  cin >> Q;
  rep(_,Q) {
    ll q;
    cin >> q;
    q += X;
    print(D[q%840] + q/840*840);
  }
  return 0;
}