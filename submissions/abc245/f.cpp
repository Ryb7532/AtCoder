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

int N, M;
const int maxN = 200000;
vector<vector<int>> E(maxN);
vector<bool> used(maxN);
vector<bool> hasCycle(maxN);
vector<bool> visited(maxN);

bool dfs(int n) {
  bool flag = false;
  for (int next : E[n]) {
    if (used[next]) {
      if (hasCycle[next]) {
        flag = true;
        break;
      }
    } else if (visited[next]) {
      flag = true;
      break;
    } else {
      visited[next] = true;
      hasCycle[next] = dfs(next);
      visited[next] = false;
      used[next] = true;
      if (hasCycle[next])
        flag = true;
    }
  }
  return flag;
}

int main() {
  cin >> N >> M;
  rep(_,M) {
    int U,V;
    cin >> U >> V;
    U--; V--;
    E[U].push_back(V);
  }
  int res = 0;
  rep(i,N) {
    visited[i] = true;
    hasCycle[i] = dfs(i);
    visited[i] = false;
    used[i] = true;
    res += hasCycle[i];
  }
  print(res);
  return 0;
}
