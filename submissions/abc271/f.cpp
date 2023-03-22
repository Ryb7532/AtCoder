#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int N;
vector<vector<int>> A(20, vector<int>(20));
vector<map<pair<int,int>,int>> M(2);
void dfs(int x, int y, int a, int p) {
  a ^= A[x][y];
  if (x+y == N-1) {
    if (M[p].find({x, a}) == M[p].end())
      M[p][{x, a}] = 0;
    M[p][{x, a}]++;
    return;
  }
  dfs(x+1,y,a,p);
  dfs(x,y+1,a,p);
}


int main() {
  cin >> N;
  rep(i,N) {
    rep(j,N) {
      cin >> A[i][j];
    }
  }
  dfs(0,0,0,0);
  rep(i,N) {
    rep(j,N-1-i) {
      A[i][j] = A[N-1-j][N-1-i];
    }
    A[i][N-1-i] = 0;
  }
  dfs(0,0,0,1);
  ll res = 0;
  for (auto e: M[0]) {
    if (M[1].find(e.first) != M[1].end())
      res += (ll)e.second * M[1][e.first];
  }
  print(res);
  return 0;
}
