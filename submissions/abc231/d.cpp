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


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> edge(N);
  rep(i,M) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  vector<bool> used(N, false);
  bool flag = true;
  rep(i,N) {
    if (edge[i].size() > 2) {
      flag = false;
    }
  }
  rep(i,N) {
    if (used[i]) {
      continue;
    }
    queue<pair<int,int>> q;
    used[i] = true;
    q.push({i, -1});
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      for (auto e: edge[top.first]) {
        if (e == top.second)
          continue;
        if (used[e]) {
          flag = false;
          break;
        }
        used[e] = true;
        q.push({e, top.first});
      }
    }
  }
  print((flag ? Yes : No));
  return 0;
}
