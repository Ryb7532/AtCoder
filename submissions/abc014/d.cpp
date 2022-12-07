#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
int N;
vector<int> edge[100000],depth(100000,-1);
vector<vector<int>> ancestor(100000,vector<int>(20,-1));

void dfs(int v, int c) {
  depth[v] = c;
  for (auto &e: edge[v]) {
    if (depth[e] != -1)
      continue;
    dfs(e,c+1);
    ancestor[e][0] = v;
  }
  return ;
}

int main() {
  cin >> N;
  rep(i,N-1) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(0,0);
  rep1(i,20) {
    rep(j,N) {
      if (ancestor[j][i-1] == -1)
        continue;
      if (ancestor[ancestor[j][i-1]][i-1] == -1)
        continue;
      ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
    }
  }
  int Q;
  cin >> Q;
  rep(i,Q) {
    int a,b,ap,bp;
    cin >> a >> b;
    a--; b--;
    ap = a; bp = b;
    if (depth[ap]>depth[bp]) {
      int d = depth[ap]-depth[bp];
      int l = 0;
      while (d != 0) {
        while ((d&(1<<l)) == 0) {
          l++;
        }
        ap = ancestor[ap][l];
        d -= (1<<l);
      }
    } else if (depth[ap]<depth[bp]) {
      int d = depth[bp]-depth[ap];
      int l = 0;
      while (d != 0) {
        while ((d&(1<<l)) == 0) {
          l++;
        }
        bp = ancestor[bp][l];
        d -= (1<<l);
      }
    }
    while (1) {
      if (ap == bp)
        break;
      int l = 0;
      while (ancestor[ap][l+1] != ancestor[bp][l+1]) {
        l++;
      }
      ap = ancestor[ap][l];
      bp = ancestor[bp][l];
    }
    int res = depth[a]-depth[ap]+depth[b]-depth[bp]+1;
    print(res);
  }
  return 0;
}
