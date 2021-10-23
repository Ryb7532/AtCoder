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


int main() {
  int N,M;
  cin >> N >> M;
  vec<vec<int>> pipe(M);
  vec<vec<int>> color_to_pipe(N);
  vec<int> top_idx(M, 0);
  vec<int> size(M);
  set<int> top;
  set<int> next;
  rep(i,M) {
    cin >> size[i];
    rep(_,size[i]) {
      int a;
      cin >> a;
      a--;
      pipe[i].push_back(a);
      color_to_pipe[a].push_back(i);
    }
    int t = pipe[i][0];
    if (top.find(t) != top.end()) {
      top.erase(t);
      next.insert(t);
    } else {
      top.insert(t);
    }
  }
  while (!next.empty()) {
    int f = *next.begin();
    next.erase(f);
    rep(i,2) {
      int p = color_to_pipe[f][i];
      top_idx[p]++;
      if (top_idx[p] == size[p])
        continue;
      int t = pipe[p][top_idx[p]];
      if (top.find(t) != top.end()) {
        top.erase(t);
        next.insert(t);
      } else {
        top.insert(t);
      }
    }
  }
  bool check = true;
  rep(i,M) {
    if (top_idx[i] != size[i])
      check = false;
  }
  print((check ? Yes : No));
  return 0;
}
