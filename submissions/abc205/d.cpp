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
  int N,Q;
  cin >> N >> Q;
  vec<ll> A(N+1,0);
  vec<ll> cnt(N+1,0);
  rep(i,N) {
    cin >> A[i+1];
    cnt[i+1] = cnt[i]+A[i+1]-A[i]-1;
  }
  rep(_,Q) {
    ll K;
    cin >> K;
    auto it = lower_bound(all(cnt), K);
    if (it == cnt.end()) {
      print(K+N);
    } else {
      print(A[it-cnt.begin()]-*it+K-1);
    }
  }
  return 0;
}
