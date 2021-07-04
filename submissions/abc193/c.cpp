#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  ll N;
  cin >> N;
  ll cnt = 0;
  map<ll, int> m;
  for (ll a=2; a<=1e5; a++) {
    ll tmp = a;
    tmp *= tmp;
    for (ll b=2; b<34; b++) {
      if (tmp>N)
        break;
      if (m[tmp]==0) {
        cnt++;
        m[tmp]++;
      }
      tmp *= a;
    }
  }
  print(N-cnt);
  return 0;
}
