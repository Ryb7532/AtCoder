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
  vector<int> P(N), C(N);
  vector<vector<int>> F(N);
  rep(i,N) {
    cin >> P[i] >> C[i];
    F[i].resize(C[i]);
    rep(j,C[i]) {
      cin >> F[i][j];
    }
  }
  bool res = false;
  rep(i,N) {
    rep(j,N) {
      if (i == j)
        continue;
      if (P[i] < P[j])
        continue;
      bool f = true;
      int s = 0;
      rep(k,C[i]) {
        while (s < C[j] && F[j][s] < F[i][k])
          s++;
        if (s < C[j] && F[j][s] == F[i][k])
          continue;
        f = false;
        break;
      }
      if (!f)
        continue;
      if (P[i] > P[j] || C[j] > C[i])
        res = true;
    }
  }
  printyesno(res);
  return 0;
}
