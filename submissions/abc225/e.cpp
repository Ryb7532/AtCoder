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
  int N;
  cin >> N;
  vector<pair<ld, ld>> I(N);
  int res = 0;
  rep(i,N) {
    ld x,y;
    cin >> x >> y;
    I[i].second = atan2(y-1, x);
    I[i].first = atan2(y, x-1);
  }
  sort(all(I));
  ld last = 0.0;
  rep(i,N) {
    if (I[i].second < last) {
      continue;
    }
    res++;
    last = I[i].first;
  }
  print(res);
  return 0;
}
