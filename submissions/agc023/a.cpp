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
  int N;
  cin >> N;
  vector<ll> C(N+1);
  map<ll,int> cnt;
  C[0] = 0;
  cnt[0] = 1;
  rep(i,N) {
    ll A;
    cin >> A;
    C[i+1] = C[i]+A;
    if (cnt.find(C[i+1]) == cnt.end())
      cnt[C[i+1]] = 0;
    cnt[C[i+1]]++;
  }
  ll res = 0;
  for (auto e: cnt) {
    ll c = e.second;
    res += c*(c-1)/2;
  }
  print(res);
  return 0;
}
