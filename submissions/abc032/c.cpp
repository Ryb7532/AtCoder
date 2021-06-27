#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i<n; i++)
#define reps(i,s,n) for (int i=s, i<n; i++)
#define rep1(i,n) for (int i=1; i<=n; i++)
#define print(a) cout << a << endl;

int main() {
  int N, K;
  cin >> N >> K;
  ll s[N], pro = 1;
  int l = 0, r = 0, ans = 0;
  rep(i, N) {
    cin >> s[i];
    if (s[i] == 0) {
      print(N);
      return 0;
    }
  }
  while (l != N) {
    while (r != N && pro * s[r] <= K) {
      pro *= s[r];
      r++;
    }
    ans = max(r-l, ans);
    if (r == l) {
      pro *= s[r];
      r++;
    }
    pro /= s[l];
    l++;
  }
  print(ans);
  return 0;
}
