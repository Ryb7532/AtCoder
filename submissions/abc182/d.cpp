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
  vec<ll> A(N), sum(N+1,0), M(N+1,0);
  ll res=0, p=0;
  rep(i,N) {
    cin >> A[i];
    sum[i+1] += sum[i] + A[i];
    M[i+1] = max(M[i], sum[i+1]);
  }
  rep(i,N) {
    res = max(res, p+M[i+1]);
    p += sum[i+1];
  }
  print(res);
  return 0;
}
