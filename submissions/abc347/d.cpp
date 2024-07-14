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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

int popcount(ll N) {
  int res = 0;
  while (N) {
    res += N%2;
    N >>= 1;
  }
  return res;
}

int main() {
  int a,b;
  ll C;
  cin >> a >> b >> C;
  int a_ = a, b_ = b;
  int c = popcount(C);
  int k = (a+b-c)/2;
  if (a+b < c || (a+b-c)%2 || min(a,b) < k) {
    print(-1);
    return 0;
  }
  a -= k;
  b -= k;
  ll A=0, B=0;
  rep(i,60) {
    if (C & (1ll<<i)) {
      if (a) {
        A += 1ll<<i;
        a--;
      } else if (b) {
        B += 1ll<<i;
        b--;
      }
    } else if (k) {
      A += 1ll<<i;
      B += 1ll<<i;
      k--;
    }
  }
  if ((A^B) == C && popcount(A) == a_ && popcount(B) == b_)
    print(A,B);
  else
    print(-1);
  return 0;
}