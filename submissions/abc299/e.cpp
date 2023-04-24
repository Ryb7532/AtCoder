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


int main() {
  int N,M,K;
  cin >> N >> M;
  const int INF = 1e9;
  vector<vector<int>> Edge(N);
  rep(i,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    Edge[u].push_back(v);
    Edge[v].push_back(u);
  }
  cin >> K;
  vector<int> P(K), D(K);
  vector<vector<int>> Can(K);
  rep(i,K) {
    cin >> P[i] >> D[i];
    P[i]--;
  }
  vector<int> res(N, -1);
  rep(i,K) {
    queue<int> q;
    vector<int> dist(N, INF);
    q.push(P[i]);
    dist[P[i]] = 0;
    while(!q.empty()) {
      int n = q.front();
      int d = dist[n];
      q.pop();
      if (d == D[i]) {
        Can[i].push_back(n);
        continue;
      } else {
        res[n] = 0;
      }
      for (int e: Edge[n]) {
        if (dist[e] != INF)
          continue;
        q.push(e);
        dist[e] = d+1;
      }
    }
  }
  bool flag = true;
  rep(i,K) {
    bool f = false;
    for (int e: Can[i]) {
      if (res[e] == -1) {
        res[e] = 1;
        f = true;
      } else if (res[e] == 1)
        f = true;
    }
    if (!f)
      flag = false;
  }
  printyesno(flag);
  if (flag) {
    rep(i,N) {
      if (res[i] == -1)
        res[i] = 1;
      cout << res[i];
    }
    cout << endl;
  }
  return 0;
}
