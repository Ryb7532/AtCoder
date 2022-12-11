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
  long X;
  string S, simpleS;
  cin >> N >> X >> S;
  int down = 0;
  rep(i,N) {
    if (S[i] != 'U') {
      down++;
      simpleS.push_back(S[i]);
    } else {
      if (down > 0) {
        down--;
        simpleS.pop_back();
      } else {
        simpleS.push_back(S[i]);
      }
    }
  }
  for (char c : simpleS) {
    if (c == 'U') {
      X /= 2;
    } else if (c == 'L') {
      X *= 2;
    } else {
      X *= 2;
      X++;
    }
  }
  print(X);
  return 0;
}
