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


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  rep(_,M) {
    int a,b;
    cin >> a >> b;
    E[--a].push_back(--b);
    E[b].push_back(a);
  }
  int Q;
  cin >> Q;
  rep(_,Q) {
    int x,k;
    cin >> x >> k;
    x--;
    int res = 0;
    set<int> within;
    queue<pair<int,int>> q;
    q.push({x,0});
    while (!q.empty()) {
      int n = q.front().first;
      int d = q.front().second;
      q.pop();
      within.insert(n);
      if (d == k) continue;
      for (int e: E[n]) {
        q.push({e, d+1});
      }
    }
    for (int k: within)
      res += k+1;
    print(res);
  }
  return 0;
}
