#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N, r;
  cin >> N;
  vector<int> R;
  rep(i, N) {
    cin >> r;
    R.push_back(r);
  }
  sort(all(R));
  reverse(all(R));
  double ans = 0;
  rep(i, N) {
    if (i%2)
      ans -= R[i]*R[i]*M_PI;
    else
      ans += R[i]*R[i]*M_PI;
  }
  printf("%.10lf\n", ans);
  return 0;
}
