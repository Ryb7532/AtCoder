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
  int N;
  cin >> N;
  vector<ll> H(N), S(N);
  ll maxH = 0;
  rep(i,N) {
    cin >> H[i] >> S[i];
    maxH = max(maxH, H[i]);
  }
  ll l=maxH-1,u=1e15+5;
  while (u-l>1) {
    ll m = (u+l)/2;
    vector<ll> within(N);
    rep(i,N) {
      within[i] = (m-H[i])/S[i];
    }
    sort(all(within));
    bool flag = true;
    rep(i,N) {
      if (within[i]<i) {
        flag = false;
        break;
      }
    }
    if (flag)
      u = m;
    else
      l = m;
  }
  print(u);
  return 0;
}
