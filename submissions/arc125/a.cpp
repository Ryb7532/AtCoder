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
  int N,M;
  cin >> N >> M;
  vector<int> S(N), T(M);
  bool s0=false, s1=false, t0=false, t1=false;
  rep(i,N) {
    cin >> S[i];
    if (S[i]==0)
      s0 = true;
    else
      s1 = true;
  }
  rep(i,M) {
    cin >> T[i];
    if (T[i]==0)
      t0 = true;
    else
      t1 = true;
  }
  int res = 0;
  if (((!s0) && t0) || ((!s1) && t1)) {
    print(-1);
    return 0;
  }
  int top = 0;
  rep(i,M) {
    if (T[i] == S[top]) {
      res++;
      continue;
    }
    int d = 1;
    while (d<N) {
      if (T[i] == S[(top+d)%N]) {
        top = (top+d)%N;
        res += d;
        break;
      }
      if (T[i] == S[(top-d+N)%N]) {
        top = (top-d+N)%N;
        res += d;
        break;
      }
      d++;
    }
    res++;
  }
  print(res);
  return 0;
}
