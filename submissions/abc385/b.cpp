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
  int H,W,X,Y;
  scan(H,W,X,Y);
  X--; Y--;
  vector<string> S(H);
  string T;
  fore(s,S) scan(s);
  scan(T);
  int res = 0;
  fore(t,T) {
    if (t == 'U' && S[X-1][Y] != '#')
      X--;
    else if (t == 'D' && S[X+1][Y] != '#')
      X++;
    else if (t == 'L' && S[X][Y-1] != '#')
      Y--;
    else if (t == 'R' && S[X][Y+1] != '#')
      Y++;
    if (S[X][Y] == '@') {
      res++;
      S[X][Y] = '.';
    }
  }
  print(X+1, Y+1, res);
  return 0;
}