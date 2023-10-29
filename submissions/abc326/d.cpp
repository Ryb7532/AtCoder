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

int N;
string R,C;
vector<string> res(5);
bool flag = false;
vector<string> S(5);
vector<string> P;

void init() {
  rep(i,N) {
    rep(j,i+1,N) {
      rep(k,i+1,N) {
        if (j==k)
          continue;
        string p;
        rep(l,N)
          p.push_back('.');
        p[i] = 'A';
        p[j] = 'B';
        p[k] = 'C';
        P.push_back(p);
      }
    }
  }
  return ;
}

void dfs(int n) {
  if (n == N) {
    rep(j,N) {
      string col;
      rep(i,N) {
        if (S[i][j] != '.')
          col.push_back(S[i][j]);
      }
      if (col.size() != 3 || col[0] == col[1] || col[1] == col[2] || col[2] == col[0] || col[0] != C[j])
        return ;
    }
    flag = true;
    rep(i,N) {
      res[i] = S[i];
    }
    return ;
  }
  map<char, char> m;
  m['.'] = '.';
  m['A'] = R[n];
  m['B'] = (R[n]-'A'+1)%3 + 'A';
  m['C'] = (R[n]-'A'+2)%3 + 'A';
  for (auto p: P) {
    string s;
    rep(i,N) {
      s.push_back(m[p[i]]);
    }
    S[n] = s;
    dfs(n+1);
  }
}

int main() {
  cin >> N >> R >> C;
  init();
  dfs(0);
  printyesno(flag);
  if (flag) {
    rep(i,N) {
      print(res[i]);
    }
  }
  return 0;
}