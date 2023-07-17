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

using pos = pair<int,int>;
const int INF = 1e9;
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

int H,W,T;
vector<string> S;

bool in_box(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y <= W);
}

vector<vector<ll>> cal_dist(pos s) {
  queue<pos> q;
  vector<vector<ll>> res(H, vector<ll>(W,INF));
  q.push(s);
  res[s.first][s.second] = 0;
  while (!q.empty()) {
    auto [x,y] = q.front();
    q.pop();
    rep(i,4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!in_box(nx,ny))
        continue;
      if (res[nx][ny] != INF || S[nx][ny] == '#')
        continue;
      res[nx][ny] = res[x][y]+1;
      q.push({nx,ny});
    }
  }
  return res;
}

int main() {
  cin >> H >> W >> T;
  S.resize(H);
  vector<pos> candy;
  pos start, goal;
  rep(i,H) {
    cin >> S[i];
    rep(j,W) {
      if (S[i][j] == 'o')
        candy.push_back({i,j});
      if (S[i][j] == 'S')
        start = {i,j};
      if (S[i][j] == 'G')
        goal = {i,j};
    }
  }
  int N = candy.size();
  vector<vector<ll>> dist_candy(N, vector<ll>(N, INF));
  vector<ll> dist_from_start(N, INF), dist_to_goal(N, INF);
  ll shortest = cal_dist(start)[goal.first][goal.second];
  rep(i,N) {
    auto dist = cal_dist(candy[i]);
    rep(j,N) {
      dist_candy[i][j] = dist[candy[j].first][candy[j].second];
    }
    dist_from_start[i] = dist[start.first][start.second];
    dist_to_goal[i] = dist[goal.first][goal.second];
  }
  vector<vector<ll>> dp(1ll<<N, vector<ll>(N,INF));
  rep(i,N) {
    dp[1ll<<i][i] = dist_from_start[i];
  }
  int res = 0;
  rep(i,1ll<<N) {
    rep(j,N) {
      if (i&(1ll<<j) == 0)
        continue;
      rep(k,N) {
        if (i&(1ll<<k))
          continue;
        dp[i+(1ll<<k)][k] = min(dp[i+(1ll<<k)][k], dp[i][j]+dist_candy[j][k]);
      }
    }
  }
  rep(i,1ll<<N) {
    int cnt = 0;
    rep(j,N) {
      if (i&(1ll<<j))
        cnt++;
    }
    rep(j,N) {
      if (dp[i][j]+dist_to_goal[j] > T)
        continue;
      res = max(res, cnt);
    }
  }
  if (shortest > T)
    res = -1;
  print(res);
  return 0;
}
