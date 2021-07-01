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
const int MAX_V = 100000;
const ll INF = 1LL << 50;
typedef struct{
  int to;
  ll t;
  ll k;
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
      if (d[e.to] > ((d[v]+e.k-1)/e.k)*e.k+e.t) {
        d[e.to] = ((d[v]+e.k-1)/e.k)*e.k+e.t;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}


int main() {
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;
  X--; Y--;
  int A,B;
  ll T,K;
  rep(i,M) {
    cin >> A >> B >> T >> K;
    A--; B--;
    G[A].push_back({B,T,K});
    G[B].push_back({A,T,K});
  }
  dijkstra(X);
  if (d[Y]==INF)
    print(-1);
  else
    print(d[Y]);
  return 0;
}
