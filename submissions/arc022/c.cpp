#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
const int MN = 100000;
vi edge[MN];
int md,res;

void dfs(int n, int p, int dis) {
  if (md<dis) {
    res = n;
    md = dis;
  }
  for (auto &e : edge[n]) {
    if (e == p)
      continue;
    dfs(e,n,dis+1);
  }
  return ;
}

int main() {
  int N;
  cin >> N;
  rep(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(0,-1,0);
  cout << res+1 << " ";
  md = 0;
  dfs(res,-1,0);
  print(res+1);
  return 0;
}
