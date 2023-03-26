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
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  bool flag = true;
  string first = "HDCS", second = "A23456789TJQK";
  rep(i,N) {
    bool f1 = false, f2 = false;
    for (char c: first) {
      if (S[i][0] == c)
        f1 = true;
    }
    for (char c: second) {
      if (S[i][1] == c)
        f2 = true;
    }
    if (!f1 || !f2)
      flag = false;
    rep(j,N) {
      if (i == j)
        continue;
      if (S[i] == S[j])
        flag = false;
    }
  }
  print((flag ? Yes : No));
  return 0;
}
