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
  int N,M,A,B;
  cin >> N >> M >> A >> B;
  vec<int> c(M);
  rep(i,M) {
    cin >> c[i];
  }
  rep(i,M) {
    if (N<=A)
      N += B;
    N -= c[i];
    if (N<0) {
      print(i+1);
      return 0;
    }
  }
  print("complete");
  return 0;
}
