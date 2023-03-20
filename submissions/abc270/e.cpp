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
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i,N) {
    ll a;
    cin >> a;
    A[i] = a;
    B[i] = a;
  }
  sort(all(B));
  int i = 0;
  ll eat = 0;
  while (K > 0) {
    if ((B[i]-eat) * (N-i) <= K) {
      K -= (B[i]-eat) * (N-i);
      eat = B[i];
      while (i < N && eat == B[i]) {
        i++;
      }
    } else {
      eat += K / (N-i);
      K %= N-i;
      i = 0;
      while (i < N && K > 0) {
        if (A[i] > eat) {
          A[i]--;
          K--;
        }
        i++;
      }
    }
  }
  rep(i,N) {
    cout << max(A[i]-eat,(ll)0) << " ";
  }
  cout << endl;
  return 0;
}
