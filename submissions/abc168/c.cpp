#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  double A, B, H, M;
  cin >> A >> B >> H >> M;
  double rad, pi = M_PI, ans;
  rad = M * pi / 30;
  rad -= (60*H + M) * pi / 360;
  ans = A*A + B*B - 2*A*B*cos(rad);
  printf("%.10lf\n", sqrt(ans));
  return 0;
}
