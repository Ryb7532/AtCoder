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
  string S;
  ll K;
  cin >> S >> K;
  string T = S+S;
  int N = S.size();
  ll cnt0=0, cnt1=0, res;
  rep(i,2*N-1) {
    if (T[i] == T[i+1]) {
      T[i+1] = '.';
    }
  }
  rep(i,N) {
    if (T[i]=='.')
      cnt0++;
  }
  for (int i=N; i<2*N; i++) {
    if (T[i]=='.')
      cnt1++;
  }
  if (T[0] == T[2*N-1]) {
    res = cnt0 + cnt1*(K-1);
  } else {
    res = cnt0+cnt1;
    res *= K/2;
    if (K%2)
      res += cnt0;
  }
  print(res);
  return 0;
}
