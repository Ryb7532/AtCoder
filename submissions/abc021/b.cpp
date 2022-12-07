#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N, a, b, K, P;
  cin >> N >> a >> b >> K;
  a--; b--;
  vector<int> cnt(N, 0);
  cnt[a]++; cnt[b]++;
  rep(i, K) {
    cin >> P;
    P--;
    cnt[P]++;
  }
  bool ans = true;
  rep(i, N) {
    if (cnt[i]>1)
      ans = false;
  }
  print(ans?"YES":"NO");
  return 0;
}
