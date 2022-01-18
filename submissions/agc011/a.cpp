#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  int N;
  ll C,K;
  cin >> N >> C >> K;
  vector<ll> T(N+1);
  rep(i,N) {
    cin >> T[i];
  }
  T[N] = 2e9+5;
  sort(all(T));
  int res = -1;
  ll limit = 0;
  int sum = 0;
  rep(i,N+1) {
    if (T[i]>limit || sum == C) {
      res++;
      sum = 0;
      limit = T[i]+K;
    }
    sum++;
  }
  print(res);
  return 0;
}
