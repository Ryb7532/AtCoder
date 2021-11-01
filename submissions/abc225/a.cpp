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
  int cnt = 3;
  rep(i,3) {
    if (S[i] == S[(i+1)%3])
      cnt--;
  }
  int res=1;
  if (cnt == 3)
    res = 6;
  else if (cnt == 2)
    res = 3;
  print(res);
  return 0;
}
