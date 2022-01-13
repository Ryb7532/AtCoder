#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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


int main() {
  ll N,L,R;
  cin >> N >> L >> R;
  R++;
  vector<int> n;
  vector<ll> two(62);
  two[0] = 1;
  rep(i,61) {
    two[i+1] = two[i]*2;
  }
  while (N != 0) {
    n.push_back(N%2);
    N /= 2;
  }
  int l = n.size();
  ll res = 0;
  rep(i,l) {
    if (n[i] == 0)
      continue;
    res += max(min(R,two[i+1])-max(L,two[i]), (ll)0);
  }
  print(res);
  return 0;
}
