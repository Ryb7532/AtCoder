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


int main() {
  ll N;
  cin >> N;
  vector<ll> res(3);
  for (ll h=1; h<=3500; h++) {
    for (ll n=h; n<=3500; n++) {
      if (4*h*n-N*h-N*n == 0)
        continue;
      if (N*h*n % (4*h*n-N*h-N*n) == 0) {
        res[0] = h;
        res[1] = n;
        res[2] = N*h*n / (4*h*n-N*h-N*n);
      }
    }
  }
  rep(i,3) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
