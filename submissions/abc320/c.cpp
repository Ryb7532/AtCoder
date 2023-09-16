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
  int M;
  cin >> M;
  vector<string> S(3);
  rep(i,3) {
    cin >> S[i];
  }
  const int INF = 500;
  map<pair<int,int>,int> time;
  rep(i,10) {
    rep(j,8) {
      time[{i,j}] = INF;
    }
    time[{i,0}] = -1;
  }
  int res = INF;
  rep(t,3*M+5) {
    rep(j,8) {
      rep(k,3) {
        int i = S[k][t%M]-'0';
        if (time[{i,j}] == INF)
          continue;
        if (time[{i,j}] == t)
          continue;
        time[{i, j|(1<<k)}] = min(time[{i, j|(1<<k)}], t);
      }
    }
  }
  rep(i,10) {
    res = min(res, time[{i, 7}]);
  }
  if (res == INF)
    res = -1;
  print(res);
  return 0;
}