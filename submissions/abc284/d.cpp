#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  int T;
  cin >> T;
  rep(_,T) {
    ll N;
    cin >> N;
    ll p=0,q=0;
    for (int i=2; i*i*i<=N; i++) {
      int cnt = 0;
      while (N%i == 0) {
        cnt++;
        N /= i;
      }
      if (cnt == 0)
        continue;
      if (cnt == 2)
        p = i;
      else
        q = i;
      break;
    }
    if (p != 0)
      q = N;
    else
      p = sqrt(N);
    print(p << " " << q);
  }
  return 0;
}
