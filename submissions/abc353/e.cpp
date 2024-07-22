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
template<typename... Args> void print(const Args... args) {(cout << ... << (cout << ' ', args)) << endl;}

struct prefixtree {
  int id;
  vector<vector<int>> edge;
  vector<int> cnt;

  prefixtree(vector<string> &v) {
    edge.push_back(vector<int>(26,-1));
    cnt.push_back(0);
    id = 1;
    fore(s,v) {
      add(s);
    }
  }

  void add(const string s) {
    int u = 0;
    cnt[0]++;
    fore(c,s) {
      int v = edge[u][c-'a'];
      if (v == -1) {
        v = id;
        edge[u][c-'a'] = id++;
        edge.push_back(vector<int>(26,-1));
        cnt.push_back(0);
      }
      cnt[v]++;
      u = v;
    }
  }
};

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  prefixtree pt(S);
  ll res = 0;
  int M = pt.id;
  rep(i,1,M) {
    ll c = pt.cnt[i];
    res += c*(c-1)/2;
  }
  print(res);
  return 0;
}