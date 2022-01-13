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
  int N;
  cin >> N;
  vector<ll> L(N),R(N);
  ll maxL=0,minR=1e9;
  rep(i,N) {
    cin >> L[i] >> R[i];
  }
  rep(i,N) {
    maxL = max(maxL, L[i]);
    minR = min(minR, R[i]);
    if (maxL <= minR) {
      print(0);
    } else {
      print((maxL-minR-1)/2+1);
    }
  }
  return 0;
}
