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
  vec<ll> A(N),B(N);
  rep(i,N)
    cin >> A[i];
  rep(i,N)
    cin >> B[i];
  ll p = 0;
  rep(i,N) {
    p += A[i]*B[i];
  }
  print((p == 0 ? Yes : No));
  return 0;
}
