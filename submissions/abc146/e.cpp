#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N, K;
  cin >> N >> K;
  int A[N+1]; ll ans = 0;
  A[0] = 0;
  rep1(i,N) {
    cin >> A[i];
    A[i] += A[i-1];
    A[i]--;
    A[i] %= K;
  }
  map<int, int> m;
  rep(i,min(K, N+1)) {
    m[A[i]]++;
  }
  rep(i,N) {
    m[A[i]]--;
    ans += m[A[i]];
    if (i+K<=N)
      m[A[i+K]]++;
  }
  print(ans);
  return 0;
}
