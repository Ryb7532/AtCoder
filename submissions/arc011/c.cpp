#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

//Dijkstra (no minus cost path)
const int MAX_V = 1002;
const ll INF = 1e9;
typedef struct{
  int to;
  ll cost;
} Edge;
typedef pair<ll, ll> P; //first:dis second:num

vec<ll> d(MAX_V,INF);
vector<Edge> G[MAX_V];

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
      }
    }
  }
}

vec<string> s(1002);
vec<string> ans;
void dfs(int a) {
  ans.push_back(s[a]);
  if (a==0)
    return ;
  for (auto &e: G[a]) {
    if (d[e.to]<d[a]) {
      dfs(e.to);
      break;
    }
  }
}


int main() {
  string f,l;
  cin >> f >> l;
  int N,len = f.size();
  cin >> N;
  s[0] = f;
  s[N+1] = l;
  rep1(i,N) {
    cin >> s[i];
  }
  rep(i,N+1) {
    reps(j,i+1,N+2) {
      int cnt=0;
      rep(l,len) {
        if (s[i][l] != s[j][l])
          cnt++;
      }
      if (cnt != 1)
        continue;
      G[i].push_back({j,1});
      G[j].push_back({i,1});
    }
  }
  if (f == l) {
    print(0);
    print(f);
    print(l);
    return 0;
  }
  dijkstra(0);
  if (d[N+1] == INF) {
    print(-1);
    return 0;
  }
  dfs(N+1);
  print(ans.size()-2);
  while (!ans.empty()) {
    print(ans.back());
    ans.pop_back();
  }
  return 0;
}
