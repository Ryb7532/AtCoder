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
  int A,B,W;
  cin >> A >> B >> W;
  W *= 1000;
  int a,b,ra,rb;
  a = W/A;
  ra = W-A*a;
  b = (W+B-1)/B;
  rb = B*b-W;
  if (ra>(B-A)*a || rb>(B-A)*b) {
    print("UNSATISFIABLE");
    return 0;
  }
  print(b << " " << a);
  return 0;
}
