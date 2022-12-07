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

const int MAX_V = 2000;
const ll INF = 1e9;
typedef struct{
  int to;
  ll cost;
} Edge;
typedef pair<ll, int> P; //first:dis second:num

ll d[MAX_V];
vec<vec<Edge>> G(MAX_V);

void dijkstra(int s) {
  fill(d, d+MAX_V, INF);
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
}


int main() {
  int N,M;
  cin >> N >> M;
  rep(_,M) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    G[A].push_back({B,1});
  }
  int res = 0;
  rep(i,N) {
    dijkstra(i);
    rep(j,N) {
      if (d[j]!=INF)
        res++;
    }
  }
  print(res);
  return 0;
}
