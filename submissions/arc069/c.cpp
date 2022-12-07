#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  set<pair<ll,int>> m;
  rep(i,N) {
    ll a;
    cin >> a;
    m.insert({-a,i});
  }
  m.insert({0,-1});
  vec<ll> ans(N,0);
  int id = N-1;
  ll res = 0,M = 0,cnt = 0;
  for (auto &e: m) {
    if (e.second>id) {
      res -= e.first;
      cnt++;
      continue;
    }
    ans[id] += res + cnt*e.first;
    cnt++;
    M = -e.first;
    id = e.second;
    res = -e.first*cnt;
  }
  rep(i,N) {
    print(ans[i]);
  }
  return 0;
}
