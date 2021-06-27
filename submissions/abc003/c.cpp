#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N, K, r;
  cin >> N >> K;
  vector<int> R;
  rep(i, N) {
    cin >> r;
    R.push_back(r);
  }
  sort(all(R));
  double ans = 0.0;
  reps(i, N-K, N) {
    ans = (ans+R[i])/2;
  }
  printf("%.7lf\n", ans);
  return 0;
}
