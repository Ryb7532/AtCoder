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

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

int main() {
  int N,M;
  cin >> N >> M;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  int res = 0;
  queue<pair<int,int>> stop;
  vector<vector<pair<bool,bool>>> flag(N, vector<pair<bool,bool>>(M, {false,false}));
  stop.push({1,1});
  flag[1][1] = {true, true};
  while (!stop.empty()) {
    auto [x,y] = stop.front();
    stop.pop();
    rep(i,4) {
      int l = 1;
      while (S[x+l*dx[i]][y+l*dy[i]] == '.') {
        flag[x+l*dx[i]][y+l*dy[i]].first = true;
        l++;
      }
      l--;
      if (flag[x+l*dx[i]][y+l*dy[i]].second)
        continue;
      stop.push({x+l*dx[i],y+l*dy[i]});
      flag[x+l*dx[i]][y+l*dy[i]].second = true;
    }
  }
  rep(i,N) {
    rep(j,M) {
      if (flag[i][j].first)
        res++;
    }
  }
  print(res);
  return 0;
}
