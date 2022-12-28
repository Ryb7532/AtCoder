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


int main() {
  int N;
  ll L;
  cin >> N >> L;
  priority_queue<ll, vector<ll>, greater<ll>> A;
  ll res = 0;
  rep(i,N) {
    ll a;
    cin >> a;
    L -= a;
    A.push(a);
  }
  if (L == 0) {
    N--;
  } else {
    A.push(L);
  }
  while (N > 0) {
    ll a0,a1;
    a0 = A.top();
    A.pop();
    a1 = A.top();
    A.pop();
    res += a0+a1;
    A.push(a0+a1);
    N--;
  }
  print(res);
  return 0;
}
