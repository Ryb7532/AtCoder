#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int n, X;
  cin >> n >> X;
  int a[n];
  rep(i, n) {
    cin >> a[i];
  }
  int ans = 0;
  rep(i, n) {
    if ((X&(1<<i)))
      ans += a[i];
  }
  print(ans);
  return 0;
}
