#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,K;
  cin >> N >> K;
  map<int, ll> cnt;
  for (int i=1-N; i<N; i++) {
    cnt[i] = min(N, N+i) - max(1, i+1) + 1;
  }
  ll res = 0;
  for (int i=1-N; i<N; i++) {
    res += cnt[i]*cnt[K-i];
  }
  print(res);
  return 0;
}
