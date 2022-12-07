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


int main() {
  ll N;
  cin >> N;
  string res;
  while (N != 0) {
    if (N%2) {
      res.push_back('A');
      N -= 1;
    } else {
      res.push_back('B');
      N /= 2;
    }
  }
  reverse(all(res));
  print(res);
  return 0;
}
