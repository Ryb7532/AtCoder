#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,s,e) assert(s <= e); for (int i=s; i<(int)(e); i++)
#define repn(i,n) rep(i,0,n)
#define rrep(i,s,e) assert(s >= e); for (int i=s-1; i>=e; i--)
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
  cin >> S;
  int N = S.size();
  vector<int> happiness;
  ll res = 0;
  int r = 0;
  int cntP = 0, cntM = 0;
  rrepn(i,N) {
    if (S[i] == '+')
      cntP++;
    else if (S[i] == '-')
      cntM++;
    else
      happiness.push_back(cntP-cntM);
  }
  sort(rall(happiness));
  repn(i,happiness.size()/2) {
    res += happiness[i];
  }
  rep(i,happiness.size()/2,happiness.size()) {
    res -= happiness[i];
  }
  print(res);
  return 0;
}
