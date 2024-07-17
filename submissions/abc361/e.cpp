#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

int N;
using edge = pair<int,ll>;
vector<vector<edge>> E;
pair<int,ll> longest(int s, int p=-1, ll cost=0) {
  int u = s;
  ll mc = cost;
  fore(e, E[s]) {
    if (e.first == p)
      continue;
    auto [v,c] = longest(e.first, s, cost+e.second);
    if (mc < c) {
      mc = c;
      u = v;
    }
  }
  return {u,mc};
}

int main() {
  cin >> N;
  E.resize(N);
  ll sum = 0;
  rep(N-1) {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    E[a].push_back(edge(b,c));
    E[b].push_back(edge(a,c));
    sum += c;
  }
  auto [u,_] = longest(0);
  auto [v,d] = longest(u);
  print(2*sum-d);
  return 0;
}