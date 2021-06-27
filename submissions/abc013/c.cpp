#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  ll N, H;
  cin >> N >> H;
  ll A, B, C, D, E, ans = 1000000000000;
  cin >> A >> B >> C >> D >> E;
  rep(i, N+1) {
    ll a = H+B*i-(N-i)*E, d;
    if (a > 0)
      d = 0;
    else
      d = (D+E-a)/(D+E);
    if (d < 0 || d+i > N)
      continue;
    ans = min(ans, A*i+C*d);
  }
  print(ans);
  return 0;
}
