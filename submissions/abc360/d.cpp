#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}

int main() {
  ll N,T;
  cin >> N >> T;
  string S;
  cin >> S;
  vector<ll> R, L;
  rep(i,N) {
    ll X;
    cin >> X;
    if (S[i] == '1')
      R.push_back(X);
    else
      L.push_back(X);
  }
  sort(all(R));
  sort(all(L));
  int ln = L.size(), rn = R.size();
  ll res = 0;
  int ir = 0, il = 0;
  rep(i,rn) {
    ll r = R[i];
    while (ir < ln && L[ir] <= r + 2*T) {
      ir++;
    }
    while (il < ln && L[il] < r) {
      il++;
    }
    res += ir-il;
  }
  print(res);
  return 0;
}