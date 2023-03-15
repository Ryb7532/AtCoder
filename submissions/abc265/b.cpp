#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  int N,M;
  ll T;
  cin >> N >> M >> T;
  vector<int> A(N-1);
  rep(i,N-1) {
    cin >> A[i];
  }
  vector<int> X(M);
  vector<ll> Y(M);
  rep(i,M) {
    cin >> X[i] >> Y[i];
  }
  int x = 0;
  bool flag = true;
  rep(i,N-1) {
    if (x < M && X[x] == i+1)
      T += Y[x++];
    T -= A[i];
    if (T <= 0)
      flag = false;
  }
  print((flag ? Yes : No));
  return 0;
}
