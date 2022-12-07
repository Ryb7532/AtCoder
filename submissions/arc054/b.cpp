#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()
ld P;

ld f(ld x) {
  return x+P*powl(0.5, x/1.5);
}

int main() {
  cin >> P;
  ld b = 0, t = P;
  while (t-b>0.000000001) {
    ld p1 = (t+2*b)/3, p2 = (2*t+b)/3;
    ld f1 = f(p1), f2 = f(p2);
    if (f1<f2) {
      t = p2;
    } else {
      b = p1;
    }
  }
  printf("%.10Lf\n", f((t+b)/2));
  return 0;
}
