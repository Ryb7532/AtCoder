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
  int a,b,c;
  cin >> a >> b >> c;
  if (a==b) {
    print(c);
  } else if (b==c) {
    print(a);
  } else if (c==a) {
    print(b);
  } else {
    print(0);
  }
  return 0;
}
