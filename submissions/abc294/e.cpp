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
  ll L;
  int N1,N2;
  cin >> L >> N1 >> N2;
  vector<pair<int,ll>> A1(N1), A2(N2);
  rep(i,N1) {
    int v;
    ll l;
    cin >> v >> l;
    A1[i] = {v,l};
  }
  rep(i,N2) {
    int v;
    ll l;
    cin >> v >> l;
    A2[i] = {v,l};
  }
  ll res = 0;
  ll p1 = 0, p2 = 0;
  int i1 = 0, i2 = 0;
  while (i1 < N1 && i2 < N2) {
    ll l1 = A1[i1].second, l2 = A2[i2].second;
    if (A1[i1].first == A2[i2].first) {
      if (p1 < p2) {
        res += max(0LL, min(p1+l1-p2, l2));
      } else {
        res += max(0LL, min(p2+l2-p1, l1));
      }
    }
    if (p1+l1 < p2+l2) {
      p1 += l1;
      i1++;
    } else {
      p2 += l2;
      i2++;
    }
  }
  print(res);
  return 0;
}
