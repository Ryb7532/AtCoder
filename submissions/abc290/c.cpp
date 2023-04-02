#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,K;
  cin >> N >> K;
  vector<bool> exist(K, false);
  rep(i,N) {
    int A;
    cin >> A;
    if (A >= K)
      continue;
    exist[A] = true;
  }
  int res = 0;
  while (res < K) {
    if (!exist[res])
      break;
    res++;
  }
  print(res);
  return 0;
}
