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


void insert(pair<ll,ll> &t, ll e) {
  if (t.first < e) {
    t.second = t.first;
    t.first = e;
  } else if (t.second < e) {
    t.second = e;
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<pair<ll,ll>>> A(N);
  map<ll,pair<ll,ll>> M;
  rep(i,N) {
    int m;
    cin >> m;
    A[i].resize(m);
    rep(j,m) {
      ll p,e;
      cin >> p >> e;
      if (M.find(p) == M.end())
        M[p] = {0,0};
      insert(M[p], e);
      A[i][j] = {p,e};
    }
  }
  for (auto &m: M) {
    if (m.second.first == m.second.second)
      m.second.first++;
  }
  bool uselcm = false;
  ll res = 0;
  rep(i,N) {
    bool flag = false;
    for (auto t: A[i]) {
      if (M[t.first].first == t.second)
        flag = true;
    }
    if (flag) {
      res++;
    } else {
      uselcm = true;
    }
  }
  if (uselcm)
    res++;
  print(res);
  return 0;
}
