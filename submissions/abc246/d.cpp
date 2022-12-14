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
  long N;
  cin >> N;
  long X = 1e18;
  auto f = [](long a, long b) { return a*a*a+a*a*b+a*b*b+b*b*b; };
  rep(a,1e6+1) {
    long h = 1e6, l = -1;
    while (h-l > 1) {
      long m = (h+l)/2;
      if (f(a, m) >=N)
        h = m;
      else
        l = m;
    }
    X = min(X, f(a, h));
  }
  print(X);
  return 0;
}
