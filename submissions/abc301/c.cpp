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
  string S,T;
  cin >> S >> T;
  map<char,int> cntS, cntT;
  for (auto c: S) {
    cntS[c]++;
  }
  for (auto c: T) {
    cntT[c]++;
  }
  string atcoder = "atcoder";
  int Sat = cntS['@'], Tat = cntT['@'];
  bool flag = true;
  rep(i,26) {
    char c = 'a' + i;
    int diff = cntS[c] - cntT[c];
    if (diff != 0) {
      if (atcoder.find(c) == atcoder.npos) {
        flag = false;
      } else {
        if (diff > 0) {
          Tat -= diff;
        } else {
          Sat += diff;
        }
      }
    }
  }
  if (Tat < 0 || Sat < 0)
    flag = false;
  printyesno(flag);
  return 0;
}
