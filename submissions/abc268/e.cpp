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


// Binary Indexed Tree (Range Update and Point Query)
template<typename T>
struct BIT_RUPQ {
  int n;
  vector<T> dat;
  BIT_RUPQ(int n) : n(n), dat(n+1,0){}
  void add(int i,T x) {
    for (++i; i<=n; i+=(i&-i)) dat[i] += x;
  }
  // add x to elements in [a,b)
  void range_add(int a, int b, T x) {
    add(a, x);
    add(b, -x);
  }
  T point_query(int i) {
    T res = 0;
    for (++i; i>0; i-=(i&-i))
      res += dat[i];
    return res;
  }
}; // 0-indexed


int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  BIT_RUPQ<int> bit(N);
  ll f = 0;
  rep(i,N) {
    cin >> P[i];
    int r1 = (P[i]-i+N)%N, r2 = (i-P[i]+N)%N;
    int rmin;
    if (r1 < r2) {
      f += r1;
      rmin = r1;
    } else {
      f += r2;
      rmin = (N-r2)%N;
    }
    bit.range_add(rmin, min(rmin+N/2, N), 1);
    bit.range_add(max(rmin-N/2, 0), rmin, -1);
    if (rmin < N/2)
      bit.range_add((rmin-N/2+N)%N, N, -1);
    if (rmin > N/2)
      bit.range_add(0, (rmin+N/2)%N, 1);
  }
  ll res = f;
  rep(i,N) {
    f += bit.point_query(i);
    res = min(res, f);
  }
  print(res);
  return 0;
}
