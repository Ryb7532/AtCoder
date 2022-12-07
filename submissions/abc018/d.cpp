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
  int N, M, P, Q, R;
  cin >> N >> M >> P >> Q >> R;
  int x[R],y[R],z[R];
  rep(i,R) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--; y[i]--;
  }
  int ans = 0;
  rep(i,(1LL<<M)) {
    int cnt = 0;
    rep(j,M) {
      cnt += (i>>j&1);
    }
    if (cnt!=Q)
      continue;
    vector<pii> w;
    rep(j,N) {
      w.push_back({0,j});
    }
    rep(r,R) {
      if (i>>y[r]&1) {
        w[x[r]].first += z[r];
      }
    }
    rsort(w);
    int sum = 0;
    rep(j,P) {
      sum += w[j].first;
    }
    ans = max(ans,sum);
  }
  print(ans);
  return 0;
}
