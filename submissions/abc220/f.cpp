#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


const int MN = 200000;
int N;
struct Vertex{
  int p;
  ll num_child;
};
vec<int> E[MN];
vec<Vertex> V(MN);
vec<ll> sum_dist(MN,0);

void dfs(int n, int p, int dis) {
  V[n].p = p;
  sum_dist[0] += dis;
  int child=1;
  for (int e:E[n]) {
    if (e == p)
      continue;
    dfs(e, n, dis+1);
    child += V[e].num_child;
  }
  V[n].num_child = child;
  return ;
}


int main() {
  cin >> N;
  rep(_,N-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(0,-1,0);
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    for (int e:E[top]) {
      if (sum_dist[e]>0)
        continue;
      sum_dist[e] = sum_dist[top]-2*V[e].num_child+N;
      q.push(e);
    }
  }
  rep(i,N) {
    print(sum_dist[i]);
  }
  return 0;
}
