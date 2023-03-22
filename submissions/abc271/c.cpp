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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<bool> B(N+1);
  int l = 0, r = N+1;
  while (r-l > 1) {
    int m = (r+l)/2;
    rep(i,N) {
      B[i+1] = false;
    }
    int cnt = 0;
    rep(i,N) {
      if (A[i] <= m && !B[A[i]]) {
        cnt++;
        B[A[i]] = true;
      }
    }
    if ((N-cnt)/2 + cnt >= m) {
      l = m;
    } else {
      r = m;
    }
  }
  print(l);
  return 0;
}
