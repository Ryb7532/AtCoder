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
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<ll> sumM(N-M+1);
  ll sum = 0;
  rep(i,M-1) {
    sum += A[i];
  }
  rep(i,N-M+1) {
    sum += A[M-1+i];
    sumM[i] = sum;
    sum -= A[i];
  }
  ll res = -1e18;
  sum = 0;
  rep(i,M-1) {
    sum += (i+1)*A[i];
  }
  rep(i,N-M+1) {
    sum += M*A[M-1+i];
    res = max(res, sum);
    sum -= sumM[i];
  }
  print(res);
  return 0;
}
