#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int S,T,M;
  cin >> S >> T >> M;
  vector<vector<int>> Edge(S+T);
  vector<vector<int>> C(T, vector<int>(T, -1));
  vector<int> res = {-1, -1, -1, -1};
  rep(i,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    Edge[u].push_back(v-S);
  }
  rep(i,S) {
    bool find = false;
    for (int j: Edge[i]) {
      for (int k: Edge[i]) {
        if (j >= k)
          continue;
        if (C[j][k] != -1) {
          res[0] = C[j][k]+1;
          res[1] = i+1;
          res[2] = j+S+1;
          res[3] = k+S+1;
          find = true;
        }
        if (find)
          break;
        C[j][k] = i;
      }
      if (find)
        break;
    }
    if (find)
      break;
  }
  if (res[0] == -1)
    print(-1);
  else {
    rep(i,4)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
