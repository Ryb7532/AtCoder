#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  ll A, K;
  cin >> A >> K;
  ll ans = 0;
  if (K == 0) {
    ans = 2e12 - A;
  } else {
    while (A<2e12) {
      ans++;
      A += 1 + K*A;
    }
  }
  print(ans);
  return 0;
}
