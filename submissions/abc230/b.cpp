#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S;
  cin >> S;
  if (S[0] == 'x') {
    if (S[1] == 'o') {
      S = "x" + S;
    }
    S = "o" + S;
  }
  int n = S.size();
  rep(i,n) {
    if (i%3 == 0 && S[i] != 'o') {
      print(No);
      return 0;
    }
    if (i%3 != 0 && S[i] != 'x') {
      print(No);
      return 0;
    }
  }
  print(Yes);
  return 0;
}
