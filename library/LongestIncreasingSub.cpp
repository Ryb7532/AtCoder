#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

// Task: Longest Increasing Subsequence Problem
class LIS() {
  const ll INF = 1e9;
  int N;
  vector<ll> A,dp;
  vector<int> ans;
  int res;

public:
  LIS(int n) : N(n), A(N), dp(N,INF), ans(N) {}

  LIS(const vector<ll> &v) : N(v.size()), A(N), dp(N,INF), ans(N) {
    rep(i,N)
      A[i] = v[i];
    solve();
  }

  void set(int i, ll a) { A[i] = a; }

  void solve() {
    res = 0;
    rep(i,N) {
      auto it = lower_bound(all(dp),A[i]);
      if (*it == INF)
        res++;
      ans[i] = res;
      *it = A[i];
    }
  }

  int max_len() { return res; }

  vector<ll> &get() { return ans; }

  ll &operator[](const int i) { return ans[i]; }
};
