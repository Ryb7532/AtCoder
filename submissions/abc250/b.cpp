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
  int N,A,B;
  cin >> N >> A >> B;
  rep(i,N) {
    rep(j,A) {
      rep(k,N) {
        rep(l,B) {
          cout << ((i+k)%2 ? '#' : '.');
        }
      }
      cout << endl;
    }
  }
  return 0;
}
