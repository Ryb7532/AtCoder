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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  cin >> N >> M;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  const int INF = 1e9;
  vector<int> ton(N,INF), from1(N,INF);
  ton[N-1] = 0;
  from1[0] = 0;
  for (int j=N-1; j>0; j--) {
    if (ton[j] == INF)
      continue;
    rep(i,M) {
      if (j-1 < i)
        break;
      if (S[j-1-i][i] == '1')
        ton[j-1-i] = min(ton[j-1-i], ton[j]+1);
    }
  }
  rep(i,N-1) {
    if (from1[i] == INF)
      continue;
    rep(j,M) {
      if (i+1+j >= N)
        break;
      if (S[i][j] == '1')
        from1[i+1+j] = min(from1[i+1+j], from1[i]+1);
    }
  }
  for (int k=1; k<N-1; k++) {
    int res = INF;
    for (int i=max(0,k-M+1); i<k; i++) {
      for (int j=k+1; j<=min(N-1, i+M); j++) {
        if (S[i][j-i-1] == '1')
          res = min(res, from1[i]+ton[j]+1);
      }
    }
    if (res == INF)
      res = -1;
    print(res);
  }
  return 0;
}
