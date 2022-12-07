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
  vector<ll> A(N);
  vector<ll> C(N+1);
  C[0] = 0;
  rep(i,N) {
    cin >> A[i];
  }
  sort(all(A));
  rep(i,N) {
    C[i+1] = C[i] + A[i];
  }
  int i;
  for (i=N-1; i>=0; i--) {
    if (2*C[i] < A[i])
      break;
  }
  print(N-i);
  return 0;
}
