#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

//Dijkstra (no minus cost path)
const int MAX_V = 2000;
const ll INF = 1LL << 50;
typedef struct{
  int to;
  ll cost;
} Edge;
typedef pair<ll, int> P; //first:dis second:num

vec<vec<Edge>> G(MAX_V);
vec<ll> selfLoop(MAX_V, INF);
vec<vec<ll>> shortest(MAX_V, vec<ll>(MAX_V, INF));

void dijkstra(int s) {
  vec<ll> d(MAX_V, INF);
  d[s] = 0;

  priority_queue<P, vec<P>, greater<P>> que;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
      continue;
    for (auto &e: G[v]) {
      if (d[e.to] > d[v]+e.cost) {
        d[e.to] = d[v]+e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  rep(i,MAX_V) {
    shortest[s][i] = d[i];
  }
}

int main() {
  int N,M;
  cin >> N >> M;
  int A,B;
  ll C;
  rep(i,M) {
    cin >> A >> B >> C;
    A--; B--;
    if (A==B) {
      selfLoop[A] = min(selfLoop[A],C);
    } else {
      G[A].push_back({B,C});
    }
  }
  rep(i,N) {
    dijkstra(i);
  }
  rep(i,N) {
    ll res = selfLoop[i];
    rep(j,N) {
      if (i==j)
        continue;
      res = min(res, shortest[i][j]+shortest[j][i]);
    }
    if (res == INF)
      res = -1;
    print(res);
  }
  return 0;
}
