#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N, T;
  cin >> N >> T;
  int A[N], ans = 0, o = 0, c = 0;
  rep(i, N)
    cin >> A[i];
  rep(i, N) {
    if (c < A[i]) {
      ans += c-o;
      o = A[i];
    }
    c = A[i]+T;
  }
  ans += c-o;
  print(ans);
  return 0;
}
