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
  string S,T;
  cin >> N >> S >> T;
  int res, i;
  for (i=0; i<=N; i++) {
    bool flag = true;
    for (int j=0; j<N-i; j++) {
      if (S[i+j] != T[j])
        flag = false;
    }
    if (flag) {
      res = i+N;
      break;
    }
  }
  print(res);
  return 0;
}
