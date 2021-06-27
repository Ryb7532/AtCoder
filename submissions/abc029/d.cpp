#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  ll N, tmp, ans = 0;
  cin >> N;
  tmp = 1e8;
  while (tmp != 0) {
    if (N%(10*tmp)/tmp == 1)
      ans += N%tmp+1 + tmp * (N/(10*tmp));
    else if (N%(10*tmp)/tmp != 0)
      ans += tmp * (N/(10*tmp)+1);
    else
      ans += tmp * (N/(10*tmp));
    tmp /= 10;
  }
  print(ans);
  return 0;
}
