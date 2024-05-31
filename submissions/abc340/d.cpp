#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), X(N);
  rep(i,N-1) {
    cin >> A[i] >> B[i] >> X[i];
    X[i]--;
  }
  vector<ll> dp(N, 1e18);
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
  dp[0] = 0;
  q.push({0,0});
  while (!q.empty()) {
    auto top = q.top();
    q.pop();
    auto [c, n] = top;
    if (n == N-1)
      break;
    if (dp[n] < c)
      continue;
    if (dp[n+1] > c+A[n]) {
      dp[n+1] = c+A[n];
      q.push({dp[n+1], n+1});
    }
    if (dp[X[n]] > c+B[n]) {
      dp[X[n]] = c+B[n];
      q.push({dp[X[n]], X[n]});
    }
  }
  print(dp[N-1]);
  return 0;
}