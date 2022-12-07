#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  int n, m;
  cin >> n >> m;
  n %= 12;
  double ans = 0;
  ans += 6*m;
  ans -= 30*n + (double)m/2.0;
  ans = abs(ans);
  printf("%.1lf", min(ans, abs(360-ans)));
  return 0;
}
