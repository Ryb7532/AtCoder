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
  int N,M;
  cin >> N >> M;
  using P = struct{ int to; ll x; ll y; };
  vector<vector<P>> E(N);
  rep(i,M) {
    int A,B,X,Y;
    cin >> A >> B >> X >> Y;
    A--; B--;
    E[A].emplace_back(P{B, X, Y});
    E[B].emplace_back(P{A,-X,-Y});
  }
  vector<bool> seen(N, false);
  vector<ll> resX(N), resY(N);
  resX[0] = resY[0] = 0;
  queue<int> q;
  q.push(0);
  seen[0] = true;
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    for (auto [ne, x, y]: E[n]) {
      if (seen[ne])
        continue;
      q.push(ne);
      resX[ne] = resX[n] + x;
      resY[ne] = resY[n] + y;
      seen[ne] = true;
    }
  }
  rep(i,N) {
    if (seen[i]) {
      print(resX[i] << ' ' << resY[i]);
    } else
      print("undecidable");
  }
  return 0;
}