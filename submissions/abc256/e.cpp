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


int N;
const int MaxN = 2e5+5;
const ll M = 1e9+5;
vector<int> X(MaxN);
vector<ll> C(MaxN);
ll res = 0;
ll minC;
vector<bool> used(MaxN, false), seen(MaxN, false);


void dfs(int n) {
  if (used[n]) {
    if (seen[n])
      res += minC;
    return;
  }
  if (seen[n]) {
    used[n] = true;
    minC = min(minC, C[n]);
    dfs(X[n]);
  } else {
    seen[n] = true;
    dfs(X[n]);
    seen[n] = false;
    used[n] = true;
  }
}

int main() {
  cin >> N;
  rep(i,N) {
    int x;
    cin >> x;
    X[i] = --x;
  }
  rep(i,N) {
    cin >> C[i];
  }
  rep(i,N) {
    minC = M;
    dfs(i);
  }
  print(res);
  return 0;
}
