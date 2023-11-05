#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  vector<int> A(M);
  rep(i,M)
    cin >> A[i];
  rep(i,M) {
    int a,b;
    cin >> b;
    a = A[i];
    a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  bool flag = true;
  vector<int> color(N, -1);
  rep(i,N) {
    if (color[i] != -1)
      continue;
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      int c = color[u];
      for (int v: E[u]) {
        if (color[v] == -1) {
          color[v] = 1-c;
          q.push(v);
        } else if (color[v] == c) {
          flag = false;
        }
      }
    }
  }
  printyesno(flag);
  return 0;
}