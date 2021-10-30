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
  ll X;
  cin >> N;
  vec<ll> A(N);
  ll sum = 0;
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
  }
  cin >> X;
  ll k = X/sum;
  ll res = k*N;
  X = X%sum;
  rep(i,N) {
    X -= A[i];
    res++;
    if (X<0)
      break;
  }
  print(res);
  return 0;
}
