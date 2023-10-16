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
  string S;
  cin >> N >> S;
  vector<int> cnt(10, 0);
  ll res = 0;
  rep(i,N) {
    cnt[S[i]-'0']++;
  }
  bool zero = true;
  rep(i,1,10) {
    if (cnt[i] != 0)
      zero = false;
  }
  if (zero)
    cnt[0] = 0;
  rep(n,10000000) {
    ll n2 = (ll)n * n;
    vector<int> cnt_(10, 0);
    while (n2 > 0) {
      cnt_[n2%10]++;
      n2 /= 10;
    }
    bool flag = true;
    rep(i,1,10) {
      if (cnt_[i] != cnt[i])
        flag = false;
    }
    if (cnt_[0] > cnt[0])
      flag = false;
    if (flag)
      res++;
  }
  print(res);
  return 0;
}