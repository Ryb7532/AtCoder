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
  int N, Mg, Mh;
  scan(N);
  vector<vector<bool>> Eg(N, vector<bool>(N, false)), Eh(N, vector<bool>(N, false));
  vector<vector<ll>> A(N, vector<ll>(N));
  scan(Mg);
  rep(_,Mg) {
    int u,v;
    scan(u,v);
    u--, v--;
    Eg[u][v] = true;
    Eg[v][u] = true;
  }
  scan(Mh);
  rep(_,Mh) {
    int u,v;
    scan(u,v);
    u--, v--;
    Eh[u][v] = true;
    Eh[v][u] = true;
  }
  rep(i,N-1) {
    rep(j,i+1, N) {
      ll a;
      scan(a);
      A[i][j] = a;
      A[j][i] = a;
    }
  }
  ll res = 1e18;
  vector<int> id(N);
  rep(i,N) {
    id[i] = i;
  }
  do {
    ll tmp = 0;
    rep(i,N) {
      rep(j,N) {
        if ((Eg[id[i]][id[j]] && !Eh[i][j]) || (!Eg[id[i]][id[j]] && Eh[i][j]))
          tmp += A[i][j];
      }
    }
    chmin(res, tmp/2);
  } while (next_permutation(all(id)));
  print(res);
  return 0;
}