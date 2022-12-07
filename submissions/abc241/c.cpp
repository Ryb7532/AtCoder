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
  rep(i,N) {
    cin >> S[i];
  }
  bool flag = false;
  rep(i,N-5) {
    rep(j,N) {
      int white = 0;
      rep(k,6) {
        if (S[i+k][j] == '.')
          white++;
      }
      if (white <= 2)
        flag = true;
      white = 0;
      rep(k,6) {
        if (S[j][i+k] == '.')
          white++;
      }
      if (white <= 2)
        flag = true;
    }
  }
  rep(i,N-5) {
    rep(j,N-5) {
      int white = 0;
      rep(k,6) {
        if (S[i+k][j+k] == '.')
          white++;
      }
      if (white <= 2)
        flag = true;
      white = 0;
      rep(k,6) {
        if (S[i+5-k][j+k] == '.')
          white++;
      }
      if (white <= 2)
        flag = true;
    }
  }
  print((flag ? Yes : No));
  return 0;
}
