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


int main() {
  int N,Q;
  cin >> N >> Q;
  vector<vector<int>> A(N);
  rep(i,N) {
    int L;
    cin >> L;
    A[i].resize(L);
    rep(j,L) {
      cin >> A[i][j];
    }
  }
  rep(_,Q) {
    int s,t;
    cin >> s >> t;
    s--; t--;
    print(A[s][t]);
  }
  return 0;
}
