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


const int INF = 1e5+5;

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> E(N), R(N);
  rep(_,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    E[a].push_back(b);
    R[b].push_back(a);
  }
  ll K = INF;
  vector<int> res;
  rep(i,N) {
    vector<int> cost(N, INF);
    queue<int> q;
    for (int e: E[i]) {
      cost[e] = 1;
      q.push(e);
    }
    while (!q.empty()) {
      int n = q.front();
      q.pop();
      for (int e: E[n]) {
        if (cost[e]==INF) {
          q.push(e);
          cost[e] = cost[n]+1;
        }
      }
    }
    if (cost[i]<K) {
      K = cost[i];
      int n = i;
      res.clear();
      res.push_back(n);
      while (cost[n]!=1) {
        for (int e: R[n]) {
          if (cost[e] < cost[n]) {
            n = e;
            break;
          }
        }
        res.push_back(n);
      }
    }
  }
  if (K == INF) {
    print(-1);
  } else {
    print(K);
    rep(i,K) {
      print(res[i]+1);
    }
  }
  return 0;
}
