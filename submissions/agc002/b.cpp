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


int main() {
  int N,M;
  cin >> N >> M;
  vector<bool> possible(N,false);
  vector<int> cnt(N,1);
  possible[0] = true;
  rep(_,M) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    if (possible[x])
      possible[y] = true;
    cnt[x]--;
    cnt[y]++;
    if (cnt[x] == 0)
      possible[x] = false;
  }
  int res = 0;
  rep(i,N) {
    if (possible[i] && cnt[i]>0)
      res++;
  }
  print(res);
  return 0;
}
