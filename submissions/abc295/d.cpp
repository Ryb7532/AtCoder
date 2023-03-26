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
  string S;
  cin >> S;
  int N = S.size();
  int s = 0;
  map<int,ll> M;
  M[0]++;
  ll res = 0;
  rep(i,N) {
    int n = S[i]-'0';
    if (s & (1<<n))
      s -= (1<<n);
    else
      s += (1<<n);
    M[s]++;
  }
  for (auto e: M) {
    ll cnt = e.second;
    res += cnt * (cnt-1) / 2;
  }
  print(res);
  return 0;
}
