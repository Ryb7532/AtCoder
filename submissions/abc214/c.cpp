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
  cin >> N;
  vec<int> S(N), T(N);
  rep(i,N) {
    cin >> S[i];
  }
  rep(i,N) {
    cin >> T[i];
  }
  rep(i,N*2) {
    T[(i+1)%N] = min(T[(i+1)%N], T[i%N] + S[i%N]);
  }
  rep(i,N) {
    print(T[i]);
  }
  return 0;
}
