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


map<ll,ll> memo;

ll f(ll n) {
  if (memo.find(n) != memo.end())
    return memo[n];
  ll fn = f(n/2) + f(n/3);
  memo[n] = fn;
  return fn;
}

int main() {
  ll N;
  cin >> N;
  memo[0] = 1;
  ll res = f(N);
  print(res);
  return 0;
}
