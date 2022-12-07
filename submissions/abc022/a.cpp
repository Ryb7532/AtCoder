#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N, S, T, W, A, ans;
  cin >> N >> S >> T >> W;
  ans = (W>=S && W<=T);
  rep(i, N-1) {
    cin >> A;
    W += A;
    ans += (W>=S && W<=T);
  }
  print(ans);
  return 0;
}
