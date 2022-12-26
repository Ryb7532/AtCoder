#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

const int MN = 2e5; //size
const ll INF = 1e9;

int N;
vector<ll> A(MN);
vector<ll> dp(MN,INF);
vector<int> ans(MN);
int res;

// Task: Longest Increasing Subsequence Problem
void LIS() {
  rep(i,N) {
    auto it = lower_bound(all(dp),A[i]);
    if (*it == INF)
      res++;
    ans[i] = res;
    *it = A[i];
  }
  return ;
}
