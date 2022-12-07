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
  int P;
  cin >> P;
  vec<ll> k(11,1);
  for (int i=1; i<10; i++) {
    k[i] = k[i-1]*(i+1);
  }
  int res = 0;
  int i=9;
  while (P!=0) {
    if (P<k[i])
      i--;
    else {
      P -= k[i];
      res++;
    }
  }
  print(res);
  return 0;
}
