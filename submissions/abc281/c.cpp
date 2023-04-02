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
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  ll T;
  cin >> N >> T;
  vector<ll> A(N);
  ll sum = 0;
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
  }
  T %= sum;
  rep(i,N) {
    if (T < A[i]) {
      print(i+1 << " " << T);
      break;
    }
    T -= A[i];
  }
  return 0;
}
