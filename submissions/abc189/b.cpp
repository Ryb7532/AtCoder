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
  int N;
  ll X;
  cin >> N >> X;
  X *= 100;
  rep(i,N) {
    ll V,P;
    cin >> V >> P;
    X -= V*P;
    if (X<0) {
      print(i+1);
      return 0;
    }
  }
  print(-1);
  return 0;
}
