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
  int N;
  cin >> N;
  vec<int> a(N);
  rep(i,N) {
    cin >> a[i];
  }
  int gcd = a[0];
  rep(i,N) {
    int b = a[i];
    while(b!=0) {
      gcd %= b;
      swap(gcd, b);
    }
  }
  print(gcd);
  return 0;
}
