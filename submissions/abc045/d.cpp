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
  ll H, W; int N;
  cin >> H >> W >> N;
  int a, b;
  ll ans[10], sum = 0;
  fill(ans, ans+10, 0);
  map<pii, int> m;
  rep(i, N) {
    cin >> a >> b;
    a--; b--;
    reps(j,-1,2) {
      if (a+j<=0 || a+j>=H-1)
        continue;
      reps(k,-1,2) {
        if (b+k<=0 || b+k>=W-1)
          continue;
        m[make_pair(a+j, b+k)]++;
      }
    }
  }
  for (auto &e: m) {
    ans[e.second]++;
    sum++;
  }
  ans[0] = (H-2)*(W-2) - sum;
  rep(i,10) {
    print(ans[i]);
  }
  return 0;
}