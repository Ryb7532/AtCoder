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
  int A,B;
  cin >> A >> B;
  int sa=0,sb=0;
  rep(i,3) {
    sa += A%10;
    sb += B%10;
    A/=10; B/=10;
  }
  print(max(sa,sb));
  return 0;
}
