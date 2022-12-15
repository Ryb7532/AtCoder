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
  int Q;
  cin >> Q;
  queue<pair<long,long>> q;
  rep(_,Q) {
    int t;
    cin >> t;
    if (t == 1) {
      long x, c;
      cin >> x >> c;
      q.push({x, c});
    } else {
      long c, sum = 0;
      cin >> c;
      while (c > 0) {
        auto top = q.front();
        if (top.second > c) {
          q.front().second -= c;
          sum += top.first * c;
          c = 0;
        } else {
          q.pop();
          sum += top.first * top.second;
          c -= top.second;
        }
      }
      print(sum);
    }
  }
  return 0;
}
