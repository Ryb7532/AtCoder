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


int main() {
  ll N;
  cin >> N;
  ll res = 0;
  vector<ll> cnt(N+1, 0);
  for (int i=1; i<N; i++) {
    for (int j=1; j*i<N; j++) {
      cnt[j*i]++;
    }
  }
  for (int i=1; i<N; i++) {
    res += cnt[i] * cnt[N-i];
  }
  print(res);
  return 0;
}
