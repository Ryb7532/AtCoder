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
  ll N,K;
  cin >> N >> K;
  rep(i,K) {
    vec<int> A,B;
    ll tmp = N;
    while (tmp != 0) {
      A.push_back(tmp%10);
      B.push_back(tmp%10);
      tmp /= 10;
    }
    sort(rall(A));
    sort(all(B));
    ll C = 0;
    rep(j,A.size()) {
      C *= 10;
      C += A[j]-B[j];
    }
    N = C;
  }
  print(N);
  return 0;
}
