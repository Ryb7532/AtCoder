#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N,K,P;
  cin >> N >> K >> P;
  vector<vector<int>> A(N, vector<int>(K));
  vector<ll> C(N);
  rep(i,N) {
    cin >> C[i];
    rep(j,K) {
      cin >> A[i][j];
    }
  }
  map<vector<int>,ll> cost;
  cost[vector<int>(K,0)] = 0;
  rep(i,N) {
    map<vector<int>,ll> new_c;
    for (auto [p,c]: cost) {
      vector<int> new_p(K);
      rep(j,K)
        new_p[j] = min(p[j] + A[i][j], P);
      if (new_c.find(new_p) != new_c.end())
        new_c[new_p] = min(new_c[new_p],c+C[i]);
      else
        new_c[new_p] = c+C[i];
    }
    for (auto [p,c]: new_c) {
      if (cost.find(p) != cost.end())
        cost[p] = min(cost[p], c);
      else
        cost[p] = c;
    }
  }
  ll res = -1;
  if (cost.find(vector<int>(K,P)) != cost.end())
    res = cost[vector<int>(K,P)];
  print(res);
  return 0;
}