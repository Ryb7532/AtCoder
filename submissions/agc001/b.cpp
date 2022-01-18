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
  ll N,X;
  cin >> N >> X;
  ll res = N;
  ll a=X,b=N-X;
  if (a < b) {
    swap(a,b);
  }
  while (a!=b) {
    ll c = ((a-1)/b)*b;
    res += 2*c;
    a -= c;
    swap(a,b);
  }
  res += a;
  print(res);
  return 0;
}
