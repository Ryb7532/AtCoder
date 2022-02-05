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
  string S;
  cin >> N >> S;
  int res = -1;
  if (S[0] != S[N-1]) {
    res = 1;
  } else {
    rep(i,N-1) {
      if (S[i] != S[0] && S[i+1] != S[0]) {
        res = 2;
      }
    }
  }
  print(res);
  return 0;
}
