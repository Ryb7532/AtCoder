#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,s,e) for (int i=s; i<(int)(e); i++)
#define repn(i,n) rep(i,0,n)
#define rrep(i,s,e) for (int i=s-1; i>=e; i--)
#define rrepn(i,n) rrep(i,n,0)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M,s,t;
  cin >> N >> M >> s >> t;
  s--; t--;
  using e = struct { int d; ll a,b; };
  vector<vector<e>> Edge(N);
  repn(_,M) {
    int u,v;
    ll a,b;
    cin >> u >> v >> a >> b;
    u--; v--;
    Edge[u].push_back({v,a,b});
    Edge[v].push_back({u,a,b});
  }
  const ll INF = 1e18;
  vector<ll> from_s(N, INF), to_t(N, INF);
  using P = pair<ll,int>;
  priority_queue<P, vector<P>, greater<P>> q;
  from_s[s] = 0;
  q.push({0,s});
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int v = p.second;
    if (from_s[v] < p.first)
      continue;
    for (auto &e: Edge[v]) {
      if (from_s[e.d] > from_s[v] + e.a) {
        from_s[e.d] = from_s[v] + e.a;
        q.push({from_s[e.d], e.d});
      }
    }
  }
  to_t[t] = 0;
  q.push({0,t});
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int v = p.second;
    if (to_t[v] < p.first)
      continue;
    for (auto &e: Edge[v]) {
      if (to_t[e.d] > to_t[v] + e.b) {
        to_t[e.d] = to_t[v] + e.b;
        q.push({to_t[e.d], e.d});
      }
    }
  }
  vector<ll> res(N+1, INF);
  rrepn(i,N) {
    res[i] = min(res[i+1], from_s[i]+to_t[i]);
  }
  repn(i,N) {
    print((ll)1e15 - res[i]);
  }
  return 0;
}
