#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  cin >> N;
  vector<pair<int,int>> C(N);
  rep(i,N) {
    cin >> C[i].first >> C[i].second;
  }
  sort(all(C));
  int l = 0, r = 1e9+5;
  while (r-l>1) {
    int m = (r+l)/2;
    int minY = 1e9, maxY = 0;
    int lid = 0, rid = 0;
    bool flag = false;
    while (rid < N && C[rid].first < C[lid].first+m) {
      rid++;
    }
    while (rid < N) {
      while (lid < N && C[lid].first+m <= C[rid].first) {
        minY = min(minY, C[lid].second);
        maxY = max(maxY, C[lid].second);
        lid++;
      }
      if (abs(minY-C[rid].second)>=m || abs(maxY-C[rid].second)>=m) {
        flag = true;
      }
      rid++;
    }
    if (flag) {
      l = m;
    } else {
      r = m;
    }
  }
  print(l);
  return 0;
}
