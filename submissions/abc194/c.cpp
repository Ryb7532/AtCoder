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
  vec<ll> A(N);
  rep(i,N)
    cin >> A[i];
  ll res = 0, sum = 0;
  rep(i,N) {
    res += A[i]*A[i];
    sum += A[i];
  }
  print(res*N - sum*sum);
  return 0;
}
