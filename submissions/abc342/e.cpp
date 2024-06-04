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
  int N,M;
  cin >> N >> M;
  vector<ll> dp(N, -1);
  vector<ll> L(M), D(M), K(M), C(M), A(M), B(M);
  vector<vector<int>> E(N);
  rep(i,M) {
    ll a,b;
    cin >> L[i] >> D[i] >> K[i] >> C[i] >> a >> b;
    a--; b--;
    A[i] = a;
    B[i] = b;
    E[b].push_back(i);
  }
  priority_queue<pair<ll,ll>> q;
  q.push({2e18, N-1});
  while(!q.empty()) {
    auto [t, n] = q.top();
    q.pop();
    if (dp[n] > t)
      continue;
    fore(i, E[n]) {
      ll l=L[i], d=D[i], k=K[i], c=C[i], a=A[i];
      if (t-c-l < 0)
        continue;
      ll f = l+min(k-1, (t-c-l)/d)*d;
      if (dp[a] < f) {
        dp[a] = f;
        q.push({f,a});
      }
    }
  }
  rep(i,N-1) {
    if (dp[i] == -1)
      print("Unreachable");
    else
      print(dp[i]);
  }
  return 0;
}