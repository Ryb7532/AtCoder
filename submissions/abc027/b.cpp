#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  int N;
  cin >> N;
  int a[N], ans = 0, sum = 0;
  rep(i, N) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum%N != 0) {
    print(-1);
    return 0;
  }

  rep(i, N-1) {
    a[i+1] += a[i];
    if (a[i] == (i+1)*sum/N)
      continue;
    ans++;
  }
  print(ans);
  return 0;
}
