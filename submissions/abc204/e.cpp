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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


using edge = struct {
  int to;
  ll d;
  ll w;
};


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<edge>> Edge(N);
  rep(i,M) {
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    A--; B--;
    Edge[A].push_back({B,C,D});
    Edge[B].push_back({A,C,D});
  }
  const ll INF = 1e18;
  vector<ll> time(N, INF);
  time[0] = 0;
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
  q.push({0,0});
  while (!q.empty()) {
    auto top = q.top();
    q.pop();
    int n = top.second;
    ll t = top.first;
    if (time[n] < t)
      continue;
    for (auto e: Edge[n]) {
      ll C = e.d, D = e.w;
      auto f = [&](ll t) {
        if (t < 0)
          return INF;
        return t + C + D/(t+1);
      };
      ll mt = sqrt(D);
      ll at = f(t);
      if (t <= mt) {
        at = f(mt);
        // at = min(f(mt), f(mt-1));
      }
      if (time[e.to] <= at)
        continue;
      time[e.to] = at;
      q.push({at, e.to});
    }
  }
  if (time[N-1] == INF)
    time[N-1] = -1;
  print(time[N-1]);
  return 0;
}
