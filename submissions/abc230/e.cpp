#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  ll N;
  cin >> N;
  int sqrtN = (int)sqrtl((ld)(N));
  ll ans = 0;
  for (int i=1; i<sqrtN; i++) {
    ans += N/i;
    ans += i*(N/i-N/(i+1));
  }
  for (int i=sqrtN; i<=N/sqrtN; i++) {
    ans += N/i;
  }
  print(ans);
  return 0;
}
