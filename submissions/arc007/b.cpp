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
  int N,M;
  cin >> N >> M;
  vec<int> d(M+1);
  d[0] = 0;
  rep(i,M) {
    cin >> d[i+1];
  }
  vec<int> c(N+1);
  rep(i,N+1) {
    c[i] = i;
  }
  rep(i,M) {
    swap(c[d[i]], c[d[i+1]]);
  }
  vec<int> res(N+1);
  rep(i,N+1) {
    res[c[i]] = i;
  }
  rep(i,N) {
    print(res[i+1]);
  }
  return 0;
}
