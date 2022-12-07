#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
vector<vector<int>> A(16, vector<int>(16));
vector<bool> used(16,false);
int res = 0;

void dfs(int n, int point) {
  if (n == N) {
    res = max(res,point);
    return ;
  }
  int a=0;
  for (; a<2*N; a++) {
    if (!used[a])
      break;
  }
  used[a] = true;
  for (int b=a+1; b<2*N; b++) {
    if (!used[b]) {
      used[b] = true;
      dfs(n+1,point^A[a][b]);
      used[b] = false;
    }
  }
  used[a] = false;
}

int main() {
  cin >> N;
  rep(i,2*N-1) {
    rep(j,2*N-i-1) {
      int a;
      cin >> a;
      A[i][i+1+j] = a;
      A[i+1+j][i] = a;
    }
  }
  dfs(0,0);
  print(res);
  return 0;
}
