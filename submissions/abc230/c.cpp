#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  ll N,A,B,P,Q,R,S;
  cin >> N >> A >> B >> P >> Q >> R >> S;
  vector<vector<bool>> grid(Q-P+1, vector<bool>(S-R+1, false));
  ll l,u;
  l = max(1-A,1-B);
  l = max(l,P-A);
  l = max(l,R-B);
  u = min(N-A,N-B);
  u = min(u,Q-A);
  u = min(u,S-B);
  for (ll k=l; k<=u; k++) {
    grid[A+k-P][B+k-R] = true;
  }
  l = max(1-A,B-N);
  l = max(l,P-A);
  l = max(l,B-S);
  u = min(N-A,B-1);
  u = min(u,Q-A);
  u = min(u,B-R);
  for (ll k=l; k<=u; k++) {
    grid[A+k-P][B-k-R] = true;
  }
  rep(i,Q-P+1) {
    rep(j,S-R+1) {
      if (grid[i][j])
        cout << '#';
      else
        cout << '.';
    }
    cout << endl;
  }
  return 0;
}
