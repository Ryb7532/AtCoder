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
  int N, Q;
  cin >> N >> Q;
  vector<int> Y(N, 0);
  rep(i,Q) {
    int e, n;
    cin >> e >> n;
    if (e == 1)
      Y[--n] += 1;
    else if (e == 2)
      Y[--n] += 2;
    else
      print((Y[--n]>=2 ? Yes : No));
  }
  return 0;
}
