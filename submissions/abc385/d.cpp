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
  int N,M;
  ll Sx,Sy;
  scan(N,M,Sx,Sy);
  vector<ll> X(N), Y(N);
  map<ll,set<pair<ll,int>>> Xs, Ys;
  rep(i,N) {
    scan(X[i], Y[i]);
    Xs[X[i]].insert({Y[i], i});
    Ys[Y[i]].insert({X[i], i});
  }
  int res = 0;
  rep(M) {
    char D;
    ll C;
    scan(D,C);
    if (D == 'D') {
      D = 'U';
      C = -C;
    }
    if (D == 'L') {
      D = 'R';
      C = -C;
    }
    if (D == 'R') {
      ll lx = min(Sx, Sx+C), ux = max(Sx, Sx+C);
      ll y = Sy;
      Sx += C;
      if (Ys.find(y) == Ys.end())
        continue;
      vector<int> del;
      auto it = Ys[y].lower_bound({lx,-1});
      while (it != Ys[y].end() && it->first <= ux) {
        del.push_back(it->second);
        res++;
        it++;
      }
      fore(i, del) {
        Ys[y].erase({X[i],i});
        Xs[X[i]].erase({Y[i],i});
      }
    }
    if (D == 'U') {
      ll ly = min(Sy, Sy+C), uy = max(Sy, Sy+C);
      ll x = Sx;
      Sy += C;
      if (Xs.find(x) == Xs.end())
        continue;
      vector<int> del;
      auto it = Xs[x].lower_bound({ly,-1});
      while (it != Xs[x].end() && it->first <= uy) {
        del.push_back(it->second);
        res++;
        it++;
      }
      fore(i, del) {
        Xs[x].erase({Y[i],i});
        Ys[Y[i]].erase({X[i],i});
      }
    }
  }
  print(Sx, Sy, res);
  return 0;
}