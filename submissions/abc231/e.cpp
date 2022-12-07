#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

int N;
ll X;
vector<ll> A(60);
vector<set<ll>> computed(60);
vector<map<ll,ll>> cnt(60);
void solve(int i,ll x) {
  if (i == N-1) {
    computed[i].insert(x);
    cnt[i][x] = x / A[i];
    return;
  }
  ll y = x % A[i+1];
  x -= y;
  if (computed[i+1].find(x) == computed[i+1].end()) {
    solve(i+1, x);
  }
  if (computed[i+1].find(x+A[i+1]) == computed[i+1].end()) {
    solve(i+1, x+A[i+1]);
  }
  ll a,b;
  a = y/A[i] + cnt[i+1][x];
  b = (A[i+1]-y)/A[i] + cnt[i+1][x+A[i+1]];
  computed[i].insert(x+y);
  cnt[i][x+y] = min(a,b);
  return;
}

int main() {
  cin >> N >> X;
  rep(i,N) {
    cin >> A[i];
  }
  solve(0,X);
  print(cnt[0][X]);
  return 0;
}
