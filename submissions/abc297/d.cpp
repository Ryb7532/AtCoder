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
  ll A,B;
  cin >> A >> B;
  ll res = 0;
  if (A < B)
    swap(A,B);
  while (A != B) {
    ll k = (A+B-1)/B-1;
    res += k;
    ll tmp = B;
    B = A-k*B;
    A = tmp;
  }
  print(res);
  return 0;
}
