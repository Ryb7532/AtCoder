#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

int main() {
  int A[3];
  cin >> A[0] >> A[1] >> A[2];
  rep(i, 3) {
    int ans = 0;
    rep(j, 3) {
      ans += (A[i] <= A[j]);
    }
    print(ans);
  }
  return 0;
}
