#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N, D, K;
  cin >> N >> D >> K;
  int L[D], R[D], S[K], T[K], ans[K];
  rep(i, D)
    cin >> L[i] >> R[i];
  rep(i, K)
    cin >> S[i] >> T[i];
  fill(ans, ans+K, 1e5);
  rep(i, D) {
    int l = L[i], r = R[i];
    rep(j, K) {
      if (S[j] == T[j])
        continue;
      if (l<=S[j] && S[j]<=r) {
        if (T[j]<l)
          S[j] = l;
        else if (T[j]>r)
          S[j] = r;
        else {
          S[j] = T[j];
          ans[j] = i+1;
        }
      }
    }
  }
  rep(i, K) {
    print(ans[i]);
  }
  return 0;
}
