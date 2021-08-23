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

int N;
vec<vec<int>> E(400000);
vec<bool> seen(400000,false);
bool isTree = true;
int node = 0;

void dfs(int n, int p) {
  node++;
  for (int e: E[n]) {
    if (e == p)
      continue;
    if (seen[e]) {
      isTree = false;
    } else {
      seen[e] = true;
      dfs(e,n);
    }
  }
}

int main() {
  cin >> N;
  set<int> color;
  rep(i,N) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
    color.insert(a);
    color.insert(b);
  }
  int res = 0;
  for (int c: color) {
    if (seen[c])
      continue;
    seen[c] = true;
    isTree = true;
    node = 0;
    dfs(c,-1);
    res += node;
    if (isTree)
      res--;
  }
  print(res);
  return 0;
}
