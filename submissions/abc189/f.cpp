#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N,K;
  ld M;
  cin >> N >> M >> K;
  vector<int> A(K);
  rep(i,K) {
    cin >> A[i];
  }
  int l = 0, m = 0;
  while (l < K) {
    int r = l+1;
    while (r < K && A[r-1]+1 == A[r])
      r++;
    m = max(m, r-l);
    l = r;
  }
  if (m >= M) {
    print(-1);
    return 0;
  }
  auto solve = [&](ld x) {
    vector<ld> dp(N+M,0.0);
    ld sum = 0.0;
    int k = K-1;
    rrep(i,N) {
      if (k >= 0 && i == A[k]) {
        dp[i] = x;
        k--;
      } else {
        dp[i] = sum/M + 1;
      }
      sum += dp[i]-dp[i+M];
    }
    return dp[0];
  };
  ld b = solve(0), a = solve(1)-b;
  print(fix(10) << b/(1-a));
  return 0;
}