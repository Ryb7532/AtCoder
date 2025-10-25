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
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

int main() {
  int N, M;
  scan(N, M);
  vector<int> u(M), v(M);
  vector<ll> w(M);
  vector<vector<int>> edges(N);
  rep(i, M) {
    scan(u[i], v[i], w[i]);
    u[i]--; v[i]--;
    edges[u[i]].push_back(i);
    edges[v[i]].push_back(i);
  }
  vector<ll> res(N);
  vector<bool> decided(N, false);
  rep(i,N) {
    if (decided[i]) continue;
    res[i] = 0;
    decided[i] = true;
    queue<int> queue;
    queue.push(i);
    while (!queue.empty()) {
      int cur = queue.front();
      queue.pop();
      fore(ei, edges[cur]) {
        int from = u[ei], to = v[ei];
        ll weight = w[ei];
        if (to == cur) {
          to = from;
          weight = -weight;
        }
        if (decided[to]) continue;
        res[to] = res[cur] + weight;
        decided[to] = true;
        queue.push(to);
      }
    }
  }
  printall(res);
  return 0;
}