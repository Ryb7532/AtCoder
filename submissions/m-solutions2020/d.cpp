#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N;
  cin >> N;
  vector<ll> A(N+1);
  rep(i,N) {
    cin >> A[i];
  }
  A[N] = 0;
  ll ans = 1000, m = 0, cnt = 0;
  rep(i,N) {
    if (cnt != 0) {
      if (A[i]>A[i+1]) {
        ans += (A[i]-m)*cnt;
        cnt = 0;
      }
    } else {
      if (A[i]<A[i+1]) {
        cnt = ans/A[i];
        m = A[i];
      }
    }
  }
  print(ans);
  return 0;
}
