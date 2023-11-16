#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  cin >> N;
  ll M = 1;
  rep(i,N)
    M *= 2;
  map<int,ll> cnt;
  rep(i,M) {
    int s;
    cin >> s;
    cnt[-s]++;
  }
  priority_queue<ll> sttop;
  sttop.push(M);
  bool res = true;
  for (auto [_,c]: cnt) {
    if (sttop.size() < c) {
      res = false;
      break;
    }
    vector<ll> tmp;
    rep(i,c) {
      ll stsize = sttop.top();
      sttop.pop();
      tmp.push_back(stsize/2);
    }
    for (ll s: tmp) {
      while (s != 0) {
        sttop.push(s);
        s /= 2;
      }
    }
  }
  printyesno(res);
  return 0;
}