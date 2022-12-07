#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


double c[1001][1001];

void init(int n) {
  c[0][0] = 1;
  rep1(i,n) {
    c[i][0] = c[i-1][0]/2;
    rep1(j,i) {
      c[i][j] = (c[i-1][j-1]+c[i-1][j])/2;
    }
  }
}

int main() {
  int N, D, X, Y, M;
  cin >> N >> D >> X >> Y;
  double ans = 0.0;
  if (X%D != 0 || Y%D != 0) {
    printf("0.0\n");
    return 0;
  }
  X /= D; Y /= D;
  X = abs(X); Y = abs(Y);
  M = N-X-Y;
  if (M<0 || M%2 == 1) {
    printf("0.0\n");
    return 0;
  }
  M /= 2;
  init(N);
  rep(i,M+1) {
    double tmp = c[N][X+2*i];
    tmp *= c[X+2*i][i];
    tmp *= c[N-X-2*i][M-i];
    ans += tmp;
  }
  printf("%.10lf\n", ans);
  return 0;
}
