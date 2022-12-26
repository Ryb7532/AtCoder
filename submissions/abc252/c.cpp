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
  vector<string> S(N);
  rep(i,N)
    cin >> S[i];
  vector<vector<int>> cnt(10, vector<int>(10, 0));
  rep(i,N) {
    rep(j,10) {
      cnt[S[i][j]-'0'][j]++;
    }
  }
  int res = 1e9;
  rep(i,10) {
    int rest = N;
    int t = 0;
    while (rest > 0) {
      if (cnt[i][t%10] == 0) {
        t++;
      } else {
        cnt[i][t%10]--;
        rest--;
        t++;
      }
    }
    res = min(res, t-1);
  }
  print(res);
  return 0;
}
