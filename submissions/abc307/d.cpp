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
  int N;
  string S;
  cin >> N >> S;
  vector<int> score(N+1, 0);
  vector<int> lbra;
  rep(i,N) {
    if (S[i] == '(')
      lbra.push_back(i);
    if (S[i] == ')' && !lbra.empty()) {
      int l = lbra.back();
      lbra.pop_back();
      score[l]++;
      score[i+1]--;
    }
  }
  string res;
  rep(i,N) {
    if (score[i] == 0)
      res.push_back(S[i]);
    score[i+1] += score[i];
  }
  print(res);
  return 0;
}
