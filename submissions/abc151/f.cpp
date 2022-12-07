#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  double x[N], y[N];
  for (int i=0; i<N; i++)
    cin >> x[i] >> y[i];
  double inf = 0.0, sup = 1000.0;
  while (sup - inf > 0.000000001) {
    double m = (sup + inf)/2;
    bool check = false;
    for (int i=0; i<N-1; i++) {
      for (int j=i+1; j<N; j++) {
        double xi = x[i], xj = x[j], yi = y[i], yj = y[j];
        double d = (xi-xj)*(xi-xj) + (yi-yj)*(yi-yj);
        d /= 4;
        if (m*m < d)
          break;
        double a = sqrt(m*m - d);
        d = sqrt(d);
        double x1 = (xi+xj)/2 + (yj-yi)/2/d*a, x2 = (xi+xj)/2 - (yj-yi)/2/d*a, y1 = (yi+yj)/2 - (xj-xi)/2/d*a, y2 = (yi+yj)/2 + (xj-xi)/2/d*a;
        bool c = true;
        for (int k=0; k<N; k++) {
          if ((x1-x[k])*(x1-x[k]) + (y1-y[k])*(y1-y[k]) > m*m+0.000001) {
            c = false;
            break;
          }
        }
        if (c)
          check = true;
        c = true;
        for (int k=0; k<N; k++) {
          if ((x2-x[k])*(x2-x[k]) + (y2-y[k])*(y2-y[k]) > m*m+0.000001) {
            c = false;
            break;
          }
        }
        if (c)
          check = true;
      }
    }
    if (check)
      sup = m;
    else
      inf = m;
  }
  printf("%.18lf\n", inf);
  return 0;
}
