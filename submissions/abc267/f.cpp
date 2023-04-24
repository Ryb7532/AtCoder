#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int N;
vector<vector<int>> Edge;
vector<vector<pair<int,int>>> Querys;
vector<int> path;
vector<int> res;

void dfs(int n, int p) {
  int ps = path.size();
  path.push_back(n+1);
  for (auto [k,id]: Querys[n]) {
    if (k <= ps) {
      res[id] = path[ps-k];
    }
  }
  for (int d: Edge[n]) {
    if (d == p)
      continue;
    dfs(d,n);
  }
  path.pop_back();
}

int main() {
  cin >> N;
  Edge.resize(N);
  Querys.resize(N);
  rep(_,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Edge[a].push_back(b);
    Edge[b].push_back(a);
  }
  int Q;
  cin >> Q;
  res.resize(Q);
  rep(i,Q) {
    int u,k;
    cin >> u >> k;
    u--;
    Querys[u].push_back({k,i});
  }
  int L=0,R=0;
  vector<bool> used(N, false);
  queue<int> q;
  q.push(0);
  used[0] = true;
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int d: Edge[n]) {
      if (used[d])
        continue;
      q.push(d);
      used[d] = true;
    }
    L = n;
  }
  used.assign(N, false);
  q.push(L);
  used[L] = true;
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int d: Edge[n]) {
      if (used[d])
        continue;
      q.push(d);
      used[d] = true;
    }
    R = n;
  }
  res.assign(Q,-1);
  dfs(L,-1);
  dfs(R,-1);
  rep(i,Q) {
    print(res[i]);
  }
  return 0;
}
