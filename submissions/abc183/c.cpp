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

int N, res = 0;
ll K;
vec<vec<int>> T(8, vec<int>(8,0));
ll arrived = 0, t = 0;

void dfs(int cnt, int c) {
  if (cnt == N-1) {
    if (K == t+T[c][0]) {
      res++;
      return;
    }
  }
  for (int i=1; i<N; i++) {
    if (i == c)
      continue;
    if ((arrived & (1<<i)) == 0) {
      arrived += (1<<i);
      t += T[c][i];
      dfs(cnt+1, i);
      arrived -= (1<<i);
      t -= T[c][i];
    }
  }
  return;
}

int main() {
  cin >> N >> K;
  rep(i,N) {
    rep(j,N) {
      cin >> T[i][j];
    }
  }
  dfs(0,0);
  print(res);
  return 0;
}
