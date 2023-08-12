#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N,Q;
  string S;
  cin >> N >> S >> Q;
  vector<int> T(Q), X(Q);
  vector<char> C(Q);
  rep(i,Q) {
    cin >> T[i] >> X[i] >> C[i];
    X[i]--;
  }
  int i = Q-1;
  string res;
  rep(i,N) {
    res.push_back('.');
  }
  while (i>=0 && T[i] == 1) {
    if (res[X[i]] == '.') {
      res[X[i]] = C[i];
    }
    i--;
  }
  if (i < 0) {
    rep(i,N)
      if (res[i] == '.')
        res[i] = S[i];
  }
  bool Capital = true;
  if (i>=0)
    Capital = T[i] == 3;
  while (i>=0) {
    if (T[i] == 1 && res[X[i]] == '.') {
      if (Capital)
        res[X[i]] = toupper(C[i]);
      else
        res[X[i]] = tolower(C[i]);
    }
    i--;
  }
  rep(i,N) {
    if (res[i] == '.') {
      if (Capital)
        res[i] = toupper(S[i]);
      else
        res[i] = tolower(S[i]);
    }
  }
  print(res);
  return 0;
}
