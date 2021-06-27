#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  ld lb = 0.0, ub = 201;
  while (ub-lb>0.00000000001) {
    ld m = (ub+lb)/2;
    ld tmp = A*m + B*sinl(C*m*M_PI);
    if (tmp>100)
      ub = m;
    else
      lb = m;
  }
  printf("%.10Lf\n", lb);
  return 0;
}
