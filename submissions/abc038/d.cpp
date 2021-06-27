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
const int INF = 1e9;

int main() {
  int N;
  cin >> N;
  vector<pii> b(N);
  rep(i,N) {
    int h;
    cin >> b[i].first >> h;
    b[i].second = -h;
  }
  sort(all(b));
  vector<int> dpw(N,INF);
  int ans = 0;
  rep(i,N) {
    auto it = lower_bound(all(dpw),-b[i].second);
    int id = it-dpw.begin();
    if (id > 0 && dpw[id-1] == -b[i].second)
      continue;
    dpw[id] = -b[i].second;
    ans = max(ans,id+1);
  }
  print(ans);
  return 0;
}
