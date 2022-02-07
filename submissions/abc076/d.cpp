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
  int N;
  cin >> N;
  vector<int> T(N+1), V(N);
  T[0] = 0;
  rep(i,N) {
    int t;
    cin >> t;
    T[i+1] = T[i]+2*t;
  }
  int times = T[N]+1;
  rep(i,N) {
    int v;
    cin >> v;
    V[i] = 2*v;
  }
  vector<int> speed(times);
  rep(i,times) {
    speed[i] = min(i, times-i-1);
  }
  rep(i,N) {
    int start = T[i], end = T[i+1];
    int v = V[i];
    rep(j,times) {
      if (j<start)
        speed[j] = min(speed[j],start-j+v);
      else if (j<end) {
        speed[j] = min(speed[j], v);
      } else {
        speed[j] = min(speed[j], j-end+v);
      }
    }
  }
  ld res = 0.0;
  rep(i,times-1) {
    res += (speed[i]+speed[i+1])/8.0;
  }
  print(fix(15)<<res);
  return 0;
}
