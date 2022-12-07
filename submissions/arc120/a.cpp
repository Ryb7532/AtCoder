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
  vector<ll> A(N), M(N), S(N), C(N+1);
  C[0] = 0;
  ll m = 0, sum = 0;
  rep(i,N) {
    cin >> A[i];
    m = max(m, A[i]);
    sum += A[i];
    M[i] = m;
    S[i] = sum;
    C[i+1] = C[i]+S[i];
  }
  rep(i,N) {
    print(S[i]+C[i]+(i+1)*M[i]);
  }
  return 0;
}
