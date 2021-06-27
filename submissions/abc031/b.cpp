#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; (i)<(n); (i)++)
#define reps(i,s,n) for (int i=(s), (i)<(n); (i)++)
#define rep1(i,n) for (int i=1; (i)<=(n); (i)++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  int L, H, N;
  cin >> L >> H >> N;
  int A[N];
  rep(i, N)
    cin >> A[i];
  rep(i, N) {
    if (A[i] > H) {
      print(-1);
    } else {
      print(max(L-A[i], 0));
    }
  }
  return 0;
}
