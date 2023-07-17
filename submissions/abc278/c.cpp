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
  set<pair<int,int>> follow;
  rep(_,Q) {
    int t,a,b;
    cin >> t >> a >> b;
    if (t == 1) {
      follow.insert({a,b});
    } else if (t == 2) {
      follow.erase({a,b});
    } else {
      if (follow.find({a,b}) != follow.end() && follow.find({b,a}) != follow.end())
        print(Yes);
      else
        print(No);
    }
  }
  return 0;
}
