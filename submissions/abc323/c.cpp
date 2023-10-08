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
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  vector<int> id(M);
  rep(i,M) {
    cin >> A[i];
    id[i] = i;
  }
  sort(all(id), [&](int a, int b) { return A[a] > A[b]; });
  vector<string> S(N);
  vector<int> P(N,0);
  int maxp = 0;
  rep(i,N) {
    cin >> S[i];
    P[i] = i+1;
    rep(j,M) {
      if (S[i][j] == 'o')
        P[i] += A[j];
    }
    maxp = max(maxp, P[i]);
  }
  rep(i,N) {
    int res = 0;
    int point = maxp - P[i];
    for (int j: id) {
      if (point <= 0)
        break;
      if (S[i][j] == 'x') {
        point -= A[j];
        res++;
      }
    }
    print(res);
  }
  return 0;
}