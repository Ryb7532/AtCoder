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
  ll N,M,V,P;
  cin >> N >> M >> V >> P;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  sort(rall(A));
  V -= P;
  vector<ll> C(N+1);
  C[0] = 0;
  rep(i,N) {
    C[i+1] = C[i]+A[i];
  }
  ll l=P-1, r=N;
  while (r-l>1) {
    ll m = (r+l)/2;
    ll v = max((ll)0, V-N+m+1);
    ll sum = C[m]-C[P-1];
    if (A[m]+M < A[P-1] || (A[m]+M)*(m-P+1)<sum+v*M) {
      r = m;
    } else {
      l = m;
    }
  }
  print(l+1);
  return 0;
}
