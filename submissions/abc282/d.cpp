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
#define YES "YES"
#define No "No"
#define NO "NO"


int N, M;
const int maxN = 2e5;
vector<vector<int>> E(maxN);
vector<int> group(maxN, -1);
bool bipartite = true;

void bfs(int s, int base) {
  group[s] = base;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int n = q.front(), g = group[n];
    q.pop();
    int next_group = base + (g == base);
    for (int t : E[n]) {
      if (group[t] != -1) {
        if (group[t] != next_group)
          bipartite = false;
      } else {
        group[t] = next_group;
        q.push(t);
      }
    }
  }
  return ;
}

int main() {
  cin >> N >> M;
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  int base = 0;
  rep(i,N) {
    sort(all(E[i]));
    if (group[i] == -1) {
      bfs(i,base);
      base += 2;
    }
  }
  if (!bipartite) {
    print(0);
    return 0;
  }
  vector<set<int>> seen(base);
  vector<int> cnt_group(base, 0);
  rep(i,N) {
    cnt_group[group[i]]++;
  }
  ll res = 0;
  rep(i,N) {
    int g = group[i];
    int e = E[i].end() - lower_bound(all(E[i]), i);
    res += N - i - cnt_group[g] - e;
    cnt_group[g]--;
  }
  print(res);
  return 0;
}
