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
  int N,W;
  cin >> N >> W;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<bool> good(W+1);
  rep(i,N) {
    int a = A[i];
    if (a > W)
      continue;
    good[a] = true;
    rep(j,N) {
      if (i==j)
        continue;
      int b = a+A[j];
      if (b > W)
        continue;
      good[b] = true;
      rep(k,N) {
        if (i==k || j==k)
          continue;
        int c = b+A[k];
        if (c > W)
          continue;
        good[c] = true;
      }
    }
  }
  int res = 0;
  rep(i,W+1)
    res += good[i];
  print(res);
  return 0;
}
