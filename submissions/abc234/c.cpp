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
  ll K;
  cin >> K;
  string res;
  while (K!=0) {
    if (K%2 == 1)
      res.push_back('2');
    else
      res.push_back('0');
    K /= 2;
  }
  reverse(all(res));
  print(res);
  return 0;
}
