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


vector<pair<int,int>> candidate = {{1,1}, {2,0}, {3,1}, {3,3}, {4,0}, {4,2}};

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x2 -= x1;
  y2 -= y1;
  if (x2 < 0)
    x2 = -x2;
  if (y2 < 0)
    y2 = -y2;
  if (x2 < y2)
    swap(x2, y2);
  bool flag = false;
  rep(i,6) {
    if (candidate[i].first == x2 && candidate[i].second == y2)
      flag = true;
  }
  print((flag ? Yes : No));
  return 0;
}
