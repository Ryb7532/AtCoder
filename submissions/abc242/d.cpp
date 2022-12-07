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
  string S;
  int Q;
  cin >> S >> Q;
  rep(_, Q) {
    ll t,k;
    cin >> t >> k;
    k--;
    if (t > 60) {
      t += S[0]-'A';
      t %= 3;
      rep(i,60) {
        t += k%2;
        k /= 2;
      }
    } else {
      int n = t;
      rep(i,n) {
        t += k%2;
        k /= 2;
      }
      t += S[k]-'A';
    }
    t %= 3;
    print((char)('A'+t));
  }
  return 0;
}
