#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
#define INF 1e18

int main() {
  int N,K;
  cin >> N >> K;
  vi P(N+1);
  vector<ll> C(N+1);
  ll ans = -INF;
  rep1(i,N) cin >> P[i];
  rep1(i,N) cin >> C[i];
  rep1(i,N) {
    ll score = 0;
    int round = 0, p = i;
    vector<ll> S(N+1,-INF);
    vector<bool> used(N+1,false);
    S[i] = 0;
    while (!used[p]) {
      used[p] = true;
      S[P[p]] = S[p] + C[P[p]];
      p = P[p];
      round++;
    }
    if (S[p] > 0) {
      score += S[p]* ((K-1)/round);
      round = (K-1)%round+1;
    }
    p = i;
    while (round>0) {
      round--;
      p = P[p];
      ans = max(ans,score+S[p]);
    }
  }
  print(ans);
  return 0;
}
