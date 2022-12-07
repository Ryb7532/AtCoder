#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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

int N;
ll X;
vector<int> L(1e5);
vector<vector<ll>> A(1e5);
ll res = 0;

void dfs(int n, ll p) {
  if (n == N) {
    if (p == X)
      res++;
    return;
  }
  ll x = X/p;
  rep(i,L[n]) {
    if (x%A[n][i] == 0) {
      dfs(n+1, p*A[n][i]);
    }
  }
}

int main() {
  cin >> N >> X;
  rep(i,N) {
    cin >> L[i];
    rep(_,L[i]) {
      ll a;
      cin >> a;
      A[i].push_back(a);
    }
  }
  dfs(0,1);
  print(res);
  return 0;
}
