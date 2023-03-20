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
  int A=0,B=0,C=0,D=0;
  rep(i,10) {
    string S;
    cin >> S;
    rep(j,10) {
      if (S[j] == '.')
        continue;
      if (C == 0)
        C = j+1;
      D = j+1;
      if (A == 0)
        A = i+1;
      B = i+1;
    }
  }
  print(A << ' ' << B);
  print(C << ' ' << D);
  return 0;
}
