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
  int N, C;
  cin >> N >> C;
  vector<pair<int,int>> O(N);
  rep(i,N) {
    cin >> O[i].first >> O[i].second;
  }
  vector<int> R(2);
  R[0] = 0;
  R[1] = (1<<30) - 1;
  rep(i,N) {
    int t = O[i].first;
    int a = O[i].second;
    if (t == 1) {
      R[0] &= a;
      R[1] &= a;
    } else if (t == 2) {
      R[0] |= a;
      R[1] |= a;
    } else {
      R[0] ^= a;
      R[1] ^= a;
    }
    int tmp = 0;
    rep(j,30) {
      int k = (C & (1<<j)) ? 1 : 0;
      tmp += R[k] & (1<<j);
    }
    C = tmp;
    print(C);
  }
  return 0;
}
