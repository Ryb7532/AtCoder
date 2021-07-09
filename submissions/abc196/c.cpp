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
  string N;
  cin >> N;
  int n = N.size();
  if (n%2) {
    n--;
    n /= 2;
    ll res = 1;
    while (n!=0) {
      res *= 10;
      n--;
    }
    print(res-1);
  } else {
    n /= 2;
    ll l=0,r=0;
    rep(i,n) {
      l*=10;
      r*=10;
      l+=N[i]-'0';
      r+=N[n+i]-'0';
    }
    if (l>r)
      print(l-1);
    else
      print(l);
  }
  return 0;
}
