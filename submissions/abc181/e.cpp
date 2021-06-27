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
  vec<ll> H(N), W(M);
  rep(i,N)
    cin >> H[i];
  rep(i,M)
    cin >> W[i];
  sort(all(H));
  sort(all(W));
  vec<ll> A(N+1,0), B(N+1,0);
  ll res = 1e15;
  for (int i=1; i<N+1; i++) {
    if (i%2) {
      A[i] = A[i-1]-H[i-1];
      B[N-i] = B[N-i+1]+H[N-i];
    } else {
      A[i] = A[i-1]+H[i-1];
      B[N-i] = B[N-i+1]-H[N-i];
    }
  }
  int i=0, j=0;
  while (j<M) {
    while (i<N && W[j]>H[i]) {
      i++;
    }
    ll v = A[i] + B[i] + (i%2 ? W[j] : -W[j]);
    res = min(res, v);
    j++;
  }
  print(res);
  return 0;
}
