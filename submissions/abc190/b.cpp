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
  int N,S,D;
  cin >> N >> S >> D;
  int X,Y;
  bool can = false;
  rep(i,N) {
    cin >> X >> Y;
    if (X<S && Y>D)
      can = true;
  }
  print((can ? Yes : No));
  return 0;
}
