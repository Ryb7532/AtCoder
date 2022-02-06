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
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<bool> cut(360, false);
  int pos = 0;
  cut[pos] = true;
  rep(i,N) {
    pos += A[i];
    pos %= 360;
    cut[pos] = true;
  }
  int res = 0;
  pos = 0;
  rep(i,360) {
    if (cut[i]) {
      res = max(res, i-pos);
      pos = i;
    }
  }
  res = max(res, 360-pos);
  print(res);
  return 0;
}
