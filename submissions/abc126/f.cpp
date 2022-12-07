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
  int M;
  ll K;
  cin >> M >> K;
  if (K == 0) {
    rep(i,(1LL<<M)) {
      cout << i << " " << i << " ";
    }
    cout << endl;
    return 0;
  } else if (M == 1) {
    print(-1);
  } else if (K<(1LL<<M)) {
    rep(i,(1LL<<M)) {
      if (i == K)
        continue;
      cout << i << " ";
    }
    cout << K << " ";
    repr(i,(1LL<<M), 0) {
      if (i == K)
        continue;
      cout << i << " ";
    }
    cout << K << endl;
  } else {
    print(-1);
  }
  return 0;
}
