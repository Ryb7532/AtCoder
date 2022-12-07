#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K, w, p;
  cin >> N >> K;
  vector<double> W, P;
  for (int i=0; i<N; i++) {
    cin >> w >> p;
    W.push_back(w);
    P.push_back(p);
  }
  double lb = 0.0, ub = 100.0;
  for (int j=0; j<10000; j++) {
    double m = (ub+lb)/2, s = 0;
    vector<double> a;
    for (int i=0; i<N; i++)
      a.push_back(W[i]*P[i]-W[i]*m);
    sort(a.rbegin(), a.rend());
    for (int i=0; i<K; i++)
      s += a[i];
    if (s >= 0)
      lb = m;
    else
      ub = m;
  }
  printf("%.9lf\n", lb);
  return 0;
}
