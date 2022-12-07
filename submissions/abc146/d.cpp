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


vector<vector<pair<int,int>>> Edge(100000);
vector<int> res(100000,0);

void dfs(int n, int p, int color) {
  int c = 1;
  for (auto e: Edge[n]) {
    if (e.first == p)
      continue;
    if (c == color)
      c++;
    res[e.second] = c;
    dfs(e.first,n,c);
    c++;
  }
}

int main() {
  int N;
  cin >> N;
  rep(i,N-1) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    Edge[A].push_back({B,i});
    Edge[B].push_back({A,i});
  }
  int m = 0;
  rep(i,N) {
    m = max(m, (int)Edge[i].size());
  }
  print(m);
  dfs(0,-1,0);
  rep(i,N-1) {
    print(res[i]);
  }
  return 0;
}
