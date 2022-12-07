#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W,C,Q;
  cin >> H >> W >> C >> Q;
  vector<int> t(Q),n(Q),c(Q);
  vector<ll> res(C,0);
  set<int> usedR,usedC;
  rep(i,Q) {
    int color;
    cin >> t[i] >> n[i] >> color;
    c[i] = --color;
  }
  for (int i=Q-1; i>=0; i--) {
    if (t[i]==1) {
      if (usedR.find(n[i]) != usedR.end())
        continue;
      usedR.insert(n[i]);
      H--;
      res[c[i]] += W;
    } else {
      if (usedC.find(n[i]) != usedC.end())
        continue;
      usedC.insert(n[i]);
      W--;
      res[c[i]] += H;
    }
  }
  cout << res[0];
  rep(i,C-1) {
    cout << ' ' << res[i+1];
  }
  cout << endl;
  return 0;
}
