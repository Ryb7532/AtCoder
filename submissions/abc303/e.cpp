#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N;
  cin >> N;
  vector<vector<int>> Edge(N);
  vector<int> degree(N,0);
  vector<int> res;
  vector<bool> seen(N,false);
  rep(i,N-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    Edge[u].push_back(v);
    Edge[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }
  rep(i,N) {
    if (degree[i] < 3)
      continue;
    res.push_back(degree[i]);
    for (int n: Edge[i]) {
      for (int k: Edge[n]) {
        if (seen[k])
          continue;
        degree[k]--;
      }
      degree[n] = 0;
      seen[n] = true;
    }
    assert(degree[i] == 0);
    seen[i] = true;
  }
  int cnt = 0;
  rep(i,N) {
    if (degree[i] != 0)
      cnt++;
  }
  assert(cnt % 3 == 0);
  cnt /= 3;
  rep(i,cnt) {
    res.push_back(2);
  }
  sort(all(res));
  for (int l: res) {
    cout << l << " ";
  }
  cout << endl;
  return 0;
}
