#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

vec<string> contest = {"ABC", "ARC", "AGC", "AHC"};

int main() {
  string S;
  int rest = 6;
  rep(i,3) {
    cin >> S;
    rep(j,4) {
      if (contest[j] == S)
        rest -= j;
    }
  }
  print(contest[rest]);
  return 0;
}
