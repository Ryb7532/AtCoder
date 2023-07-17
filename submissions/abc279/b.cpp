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
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  string S,T;
  cin >> S >> T;
  int N = S.size(), M = T.size();
  bool flag = false;
  rep(i,N-M+1) {
    int match = 0;
    rep(j,M) {
      if (S[i+j] == T[j])
        match++;
    }
    if (match == M)
      flag = true;
  }
  printYorN(flag);
  return 0;
}
