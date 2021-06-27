#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N;
  cin >> N;
  int cnt = 0, v = 1;
  bool ans[4];
  fill(ans, ans+4, false);
  rep(i, 4) {
    if ((N & (1<<i)) != 0) {
      ans[i] = true;
      cnt++;
    }
  }
  print(cnt);
  rep(i, 4) {
    if (ans[i]) {
      print(v);
    }
    v *= 2;
  }
  return 0;
}
