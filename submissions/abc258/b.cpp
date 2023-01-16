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

vector<int> dxs = {0,1,1,1,0,-1,-1,-1}, dys = {1,1,0,-1,-1,-1,0,1};

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  ll res = 0;
  rep(y,N) {
    rep(x,N) {
      rep(d,8) {
        ll num = 0;
        int dx = dxs[d], dy = dys[d];
        rep(i,N) {
          num *= 10;
          num += A[(y+i*dy+N)%N][(x+i*dx+N)%N] - '0';
        }
        res = max(res, num);
      }
    }
  }
  print(res);
  return 0;
}
