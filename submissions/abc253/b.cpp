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
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W;
  cin >> H >> W;
  vector<pair<int,int>> P;
  rep(i,H) {
    string S;
    cin >> S;
    rep(j,W) {
      if (S[j] == 'o')
        P.push_back({i,j});
    }
  }
  print(abs(P[0].first-P[1].first) + abs(P[0].second-P[1].second));
  return 0;
}
