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
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << ((f) ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}

int N,K;
string S;
int res = 0;
set<string> seen;
vector<bool> used;
string T;

void dfs(int n) {
  if (n == N) {
    if (seen.find(T) != seen.end())
      return;
    seen.insert(T);
    bool flag = true;
    rep(i,N-K+1) {
      bool f = true;
      rep(j,K) {
        if (T[i+j] != T[i+K-1-j])
          f = false;
      }
      if (f)
        flag = false;
    }
    if (flag)
      res++;
    return;
  }
  rep(i,N) {
    if (used[i])
      continue;
    used[i] = true;
    T.push_back(S[i]);
    dfs(n+1);
    T.pop_back();
    used[i] = false;
  }
}


int main() {
  cin >> N >> K >> S;
  used.assign(N, false);
  dfs(0);
  print(res);
  return 0;
}