#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,A,B,C,D;
  string S;
  cin >> N >> A >> B >> C >> D >> S;
  A--; B--; C--; D--;
  bool flag = true;
  if (D<C) {
    for (int i=A+1; i<=C; i++) {
      if (S[i-1]=='#' && S[i]=='#')
        flag = false;
    }
    bool can_swap = false;
    for (int i=B; i<=D; i++) {
      if (S[i-1]=='.' && S[i]=='.' && S[i+1]=='.')
        can_swap = true;
    }
    if (!can_swap)
      flag = false;
  } else {
    for (int i=B+1; i<D; i++) {
      if (S[i-1]=='#' && S[i]=='#')
        flag = false;
    }
    for (int i=A+1; i<=C; i++) {
      if (S[i-1]=='#' && S[i]=='#')
        flag = false;
    }
  }
  print((flag ? Yes : No));
  return 0;
}
