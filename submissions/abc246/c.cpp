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
  long N,K,X;
  cin >> N >> K >> X;
  vector<long> A(N);
  rep(i,N) {
    long a;
    cin >> a;
    int div = a/X;
    if (div > K) {
      a -= X*K;
      K = 0;
    } else {
      K -= div;
      a %= X;
    }
    A[i] = a;
  }
  sort(all(A));
  long sum = 0;
  rep(i,N-K) {
    sum += A[i];
  }
  print(sum);
  return 0;
}
