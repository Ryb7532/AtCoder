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

int main() {
  int N;
  string T;
  cin >> N >> T;
  int st = T.size();
  ll res = 0;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  vector<int> A(N), B(N);
  rep(i,N) {
    int ss = S[i].size();
    int a = 0, b = 0;
    rep(j,ss) {
      if (a < st && S[i][j] == T[a]) {
        a++;
      }
      if (b < st && S[i][ss-1-j] == T[st-1-b]) {
        b++;
      }
    }
    A[i] = a;
    B[i] = b;
  }
  sort(all(B));
  rep(i,N) {
    int tmp = N - (lower_bound(all(B), st-A[i]) - B.begin());
    res += tmp;
  }
  print(res);
  return 0;
}