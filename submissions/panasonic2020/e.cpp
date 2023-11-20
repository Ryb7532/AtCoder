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

const int M = 2000;

bool match(char a, char b) {
  return (a == '?' || b == '?' || a == b);
}

int main() {
  string a,b,c;
  cin >> a >> b >> c;
  int A = a.size(), B = b.size(), C = c.size();
  vector<bool> ab(20000, true), ac(20000, true), bc(20000, true);
  rep(i,A) rep(j,B) if (!match(a[i], b[j])) ab[i-j+10000] = false;
  rep(i,A) rep(j,C) if (!match(a[i], c[j])) ac[i-j+10000] = false;
  rep(i,B) rep(j,C) if (!match(b[i], c[j])) bc[i-j+10000] = false;
  int res = A+B+C;
  rep(i,-2*M,2*M+1) {
    rep(j,-2*M,2*M+1) {
      if (ab[i+10000] && ac[j+10000] && bc[j-i+10000]) {
        int L = min(min(i,j),0);
        int R = max(max(i+B,j+C),A);
        res = min(res, R-L);
      }
    }
  }
  print(res);
  return 0;
}