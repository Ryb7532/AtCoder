#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


// Task: Single Source Shortest Path Problem
// Dijkstra (no minus cost path)
const int MAX_V = 200005;
const ll INF = 1LL << 50;
typedef struct{
  int to;
  ll cost;
  int id;
} Edge;
typedef pair<ll, int> P; // first:dis second:num

vector<ll> d(MAX_V, INF);
vector<vector<Edge>> G(MAX_V);
vector<int> use(MAX_V, -1);

void dijkstra(int s) {
  d[s] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
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
        use[e.to] = e.id;
      }
    }
  }
}

int main() {
  int N,M;
  cin >> N >> M;
  rep(i,M) {
    int A,B,C;
    cin >> A >> B >> C;
    A--; B--;
    G[A].push_back({B, C, i+1});
    G[B].push_back({A, C, i+1});
  }
  dijkstra(0);
  stringstream ss;
  rep(i,N-1) {
    ss << use[i+1] << " ";
  }
  string ans = ss.str();
  ans.pop_back();
  print(ans);
  return 0;
}
