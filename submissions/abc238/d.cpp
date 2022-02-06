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
  int T;
  cin >> T;
  vector<bool> res(T);
  rep(i,T) {
    ll a,s;
    cin >> a >> s;
    s -= 2*a;
    res[i] = (s>=0 && (s&a)==0);
  }
  rep(i,T) {
    print((res[i] ? Yes : No));
  }
  return 0;
}
