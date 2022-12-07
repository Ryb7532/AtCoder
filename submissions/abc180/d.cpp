#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  ld x,y,a,b;
  cin >> x >> y >> a >> b;
  ll e = 0;
  ld bound = b/(a-1);
  if (y < bound) {
    while (y/x > a) {
      e++;
      x *= a;
    }
  } else {
    while (x < bound) {
      e++;
      x *= a;
    }
    if (x > y) e--;
    else e += (y-1-x)/b;
  }
  /*
  while (x<y) {

    e++;
  }*/
  print(e);
  return 0;
}
