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
  ld R,X,Y;
  cin >> R >> X >> Y;
  ld dis = sqrtl(X*X+Y*Y);
  int res = ceill(dis/R);
  if (res==1 && dis!=R)
    res++;
  print(res);
  return 0;
}