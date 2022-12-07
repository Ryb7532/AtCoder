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


int main() {
  int N,M;
  cin >> N >> M;
  vec<vec<pair<int,int>>> E(N);
  vec<int> label(N,-1);
  rep(i,M) {
    int u,v,c;
    cin >> u >> v >> c;
    u--; v--;
    E[u].push_back({v, c});
    E[v].push_back({u, c});
  }
  queue<int> q;
  label[0]=1;
  q.push(0);
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int l = label[top];
    for (auto e: E[top]) {
      if (label[e.first] != -1)
        continue;
      if (e.second == l) {
        label[e.first] = l%N+1;
      } else {
        label[e.first] = e.second;
      }
      q.push(e.first);
    }
  }
  rep(i,N) {
    print(label[i]);
  }
  return 0;
}
