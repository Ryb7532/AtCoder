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


int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
string D = "RLUD";

int main() {
  int N;
  string S;
  cin >> N >> S;
  set<pair<int,int>> visited;
  int x = 0, y = 0;
  visited.insert({0,0});
  bool flag = false;
  rep(i,N) {
    rep(j,4) {
      if (S[i] == D[j]) {
        x += dx[j];
        y += dy[j];
      }
    }
    if (visited.find({x,y}) != visited.end())
      flag = true;
    visited.insert({x,y});
  }
  printyesno(flag);
  return 0;
}
