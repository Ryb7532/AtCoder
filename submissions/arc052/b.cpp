#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
ld sum[20001];

int main() {
  int N, Q, X, R, H, A, B;
  cin >> N >> Q;
  vector<int> top;
  rep(i,N) {
    cin >> X >> R >> H;
    ld h = H, r = R;
    ld t = r/h;
    ld V1 = M_PI*r*r*h/3.0;
    while (H>0) {
      X++;
      ld h2 = H-1;
      ld r2 = t*h2;
      ld V2 = M_PI*r2*r2*h2/3.0;
      sum[X] += V1-V2;
      H--;
      V1 = V2;
    }
  }
  rep1(i,20000) {
    sum[i] += sum[i-1];
  }
  rep(i,Q) {
    cin >> A >> B;
    printf("%.6Lf\n",sum[B]-sum[A]);
  }
  return 0;
}
