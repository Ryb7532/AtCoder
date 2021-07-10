#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

int N;
vec<ll> A(20);
ll res = 1LL<<30;

void dfs(int n, ll a, ll b) {
  if (n == N) {
    res = min(res, a^b);
    return;
  }
  b |= A[n];
  dfs(n+1, a^b, 0);
  dfs(n+1, a, b);
  return;
}

int main() {
  cin >> N;
  rep(i,N)
    cin >> A[i];
  dfs(0,0,0);
  print(res);
  return 0;
}
