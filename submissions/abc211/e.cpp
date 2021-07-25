#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

int N,K;
vec<string> S(8);
set<ull> used;
vec<int> dx={-1,0,1,0},dy={0,-1,0,1};
ll res = 0;

ull string2num() {
  ll num = 0;
  rep(i,N) {
    rep(j,N) {
      num *= 2;
      num += (S[i][j]=='@');
    }
  }
  return num;
}

void dfs(int n) {
  if (n==K) {
    res++;
    return;
  }
  vec<pair<int,int>> candidate;
  rep(i,N) {
    rep(j,N) {
      if (S[i][j]!='.')
        continue;
      bool flag = false;
      rep(k,4) {
        int x=i+dx[k], y=j+dy[k];
        if (x>=0 && x<N && y>=0 && y<N)
          if (S[x][y]=='@')
            flag = true;
      }
      if (flag)
        candidate.push_back({i,j});
    }
  }
  for (auto &e: candidate) {
    S[e.first][e.second] = '@';
    ull num = string2num();
    if (used.find(num)==used.end()) {
      used.insert(num);
      dfs(n+1);
    }
    S[e.first][e.second] = '.';
  }
  return;
}

int main() {
  cin >> N >> K;
  rep(i,N) {
    cin >> S[i];
  }
  rep(i,N) {
    rep(j,N) {
      if (S[i][j]=='#')
        continue;
      S[i][j] = '@';
      ull num = string2num();
      used.insert(num);
      dfs(1);
      S[i][j] = '.';
    }
  }
  print(res);
  return 0;
}
