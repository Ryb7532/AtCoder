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
  ll N,M,K;
  string S;
  cin >> N >> M >> K >> S;
  vector<int> Xid;
  rep(i,N) {
    if (S[i] == 'x')
      Xid.push_back(i);
  }
  int X = Xid.size();
  Xid.push_back(N);
  ll res = N*(K/X);
  if (K != M*X)
    res += Xid[K%X];
  rep(i,X) {
    ll tmp = -Xid[i] - 1;
    if (X-i-1 > K) {
      tmp += Xid[i+K+1];
    } else {
      ll k_ = K-(X-i-1);
      if (k_ < (M-1)*X) {
        tmp += N*(k_/X+1);
        k_ %= X;
        tmp += Xid[k_];
      } else {
        tmp += N*M;
      }
    }
    res = max(res, tmp);
  }
  print(res);
  return 0;
}
