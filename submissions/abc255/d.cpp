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
  int N,Q;
  cin >> N >> Q;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  sort(all(A));
  vector<ll> toMax(N+1, 0), toMin(N+1, 0);
  rep(i,N) {
    toMax[i+1] = toMax[i] + A[N-1] - A[i];
    toMin[N-1-i] = toMin[N-i] + A[N-1-i] - A[0];
  }
  rep(_,Q) {
    ll X;
    cin >> X;
    int n0 = lower_bound(all(A), X) - begin(A);
    int n1 = lower_bound(all(A), X+1) - begin(A);
    print(toMax[n0] - (A[N-1] - X) * n0 + toMin[n1] - (X - A[0]) * (N-n1));
  }
  return 0;
}
