#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<pair<int,int>>> Edge(N);
  rep(i,M) {
    int s,t;
    cin >> s >> t;
    s--; t--;
    Edge[s].push_back({t,i});
  }
  const int INF = 1e9;
  int mindist;
  set<int> paths;
  {
    vector<int> dist(N, INF);
    vector<pair<int,int>> path(N, {-1,-1});
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
      int n = q.front();
      int d = dist[n];
      q.pop();
      for (auto e: Edge[n]) {
        int next = e.first;
        int id = e.second;
        if (dist[next] != INF)
          continue;
        dist[next] = d+1;
        path[next] = {n, id};
        q.push(next);
      }
    }
    mindist = dist[N-1];
    int n = N-1;
    while (path[n].second != -1) {
      paths.insert(path[n].second);
      n = path[n].first;
    }
  }
  if (mindist == INF) {
    rep(i,M) {
      print(-1);
    }
    return 0;
  }
  rep(i,M) {
    if (paths.find(i) == paths.end()) {
      print(mindist);
      continue;
    }
    vector<int> dist(N, INF);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()) {
      int n = q.front();
      int d = dist[n];
      q.pop();
      for (auto e: Edge[n]) {
        int next = e.first;
        int id = e.second;
        if (id == i)
          continue;
        if (dist[next] != INF)
          continue;
        dist[next] = d+1;
        q.push(next);
      }
    }
    int res = dist[N-1];
    if (res == INF)
      res = -1;
    print(res);
  }
  return 0;
}
