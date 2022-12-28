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
#define YES "YES"
#define No "No"
#define NO "NO"


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


typedef struct query {
  int t;
  int l;
  int r;
  int x;
} query;


int main() {
  int N,M,Q;
  cin >> N >> M >> Q;
  vector<query> querys(Q);
  vector<int> substitute_query(N+1, -1);
  map<int,vector<int>> need_record;
  map<int, int> output2substitute;
  map<pair<int,int>, ll> added;
  rep(i,Q) {
    int t,l,r,x=0;
    cin >> t >> l >> r;
    if (t == 1) cin >> x;
    if (t == 2) substitute_query[l] = i;
    if (t == 3) need_record[substitute_query[l]].push_back(r), output2substitute[i] = substitute_query[l];
    querys[i] = {t, l, r, x};
  }
  BIT_RUPQ<ll> bit(M+1);
  rep(i,Q) {
    if (need_record.find(i) != need_record.end()) {
      for (int c : need_record[i]) {
        added[{i,c}] = bit.point_query(c);
      }
    }
    auto q = querys[i];
    if (q.t == 1) {
      bit.range_add(q.l, q.r+1, q.x);
    } else if (q.t == 3) {
      int subq = output2substitute[i];
      ll res = bit.point_query(q.r);
      if (subq < 0) {
        print(res);
      } else {
        res -= added[{subq, q.r}];
        print(res + querys[subq].r);
      }
    }
  }
  return 0;
}
