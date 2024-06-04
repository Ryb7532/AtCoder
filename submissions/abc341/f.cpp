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
  vector<int> U(M), V(M);
  vector<ll> W(N), A(N);
  rep(i,M) {
    cin >> U[i] >> V[i];
    U[i]--; V[i]--;
  }
  rep(i,N) {
    cin >> W[i];
  }
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<int>> E(N);
  vector<int> odgr(N,0);
  rep(i,M) {
    int u = U[i], v = V[i];
    E[u].push_back(v);
    E[v].push_back(u);
    if (W[u] > W[v]) {
      odgr[u]++;
    }
    if (W[v] > W[u]) {
      odgr[v]++;
    }
  }
  vector<vector<ll>> dp(N,vector<ll>(5001,1));
  queue<int> q;
  rep(i,N) {
    if (odgr[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    ll w = W[n];
    fore(m, E[n]) {
      if (w < W[m]) {
        odgr[m]--;
        if (odgr[m] == 0)
          q.push(m);
      }
      ll c = dp[m][W[m]];
      rrep(i,w-W[m]) {
        chmax(dp[n][i+W[m]],dp[n][i]+c);
      }
    }
    rep(i,W[n])
      chmax(dp[n][i+1],dp[n][i]);
  }
  ll res = 0;
  rep(i,N) {
    res += dp[i][W[i]] * A[i];
  }
  print(res);
  return 0;
}