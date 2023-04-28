#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,s,e) for (int i=s; i<(int)(e); i++)
#define repn(i,n) rep(i,0,n)
#define rrep(i,s,e) for (int i=s-1; i>=e; i--)
#define rrepn(i,n) rrep(i,n,0)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  string S;
  int w;
  cin >> S >> w;
  int i = 0;
  int N = S.size();
  while (i < N) {
    cout << S[i];
    i += w;
  }
  cout << endl;
  return 0;
}
