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
  int N,M;
  cin >> N >> M;
  vector<int> S(N), T(M);
  rep(i,N) {
    cin >> S[i];
  }
  rep(i,M) {
    cin >> T[i];
  }
  int res = 0;
  rep(i,N) {
    rep(j,M) {
      if (S[i] % 1000 == T[j]) {
        res++;
        break;
      }
    }
  }
  print(res);
  return 0;
}
