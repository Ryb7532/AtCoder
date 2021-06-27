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


//Bellman_Ford
const int MAX_V = 2500;
const ll INF = 1e9;
using Edge = struct{
  int from;
  int to;
  ll cost;
};

int V, E;
ll d[MAX_V];
vector<Edge> edge;
bool c1[MAX_V], c2[MAX_V], c3[MAX_V];

void init1(int n) {
  if (c1[n])
    return;
  c1[n] = true;
  rep(i,E) {
    Edge e = edge[i];
    if (e.from == n)
      init1(e.to);
  }
}

void init2(int n) {
  if (c2[n])
    return;
  c2[n] = true;
  rep(i,E) {
    Edge e = edge[i];
    if (e.to == n)
      init2(e.from);
  }
}

void init() {
  init1(0);
  init2(V-1);
  rep(i,V) {
    c3[i] = c1[i] && c2[i];
  }
}

bool Bellman_Ford(int s) {
  fill(d, d+V, INF);
  d[s] = 0;
  rep(i,V) {
    rep(j,E) {
      Edge e = edge[j];
      if (d[e.to] > d[e.from]+e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i == V-1) {
          if (c3[e.to] && c3[e.from])
            return true;
        }
      }
    }
  }
  return false;
}


int main() {
  int P, a, b, c;
  cin >> V >> E >> P;
  rep(i,E) {
    cin >> a >> b >> c;
    a--; b--; c = P-c;
    edge.push_back({a, b, c});
  }
  init();
  bool mcycle = Bellman_Ford(0);
  if (mcycle) {
    print(-1);
  } else {
    ll ans = -d[V-1];
    ans = max(ans, (ll)0);
    print(ans);
  }
  return 0;
}
