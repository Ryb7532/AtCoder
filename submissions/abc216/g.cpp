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


// Task: Subset Sum Problem
// Binary Indexed Tree (Point Update and Range Query)
template<typename T>
struct BIT {
  int n;
  vector<T> dat;
  BIT(int n) : n(n), dat(n+1,0){}
  void add(int i,T x) {
    for (++i; i<=n; i+=(i&-i)) dat[i] += x;
  }
  T sum(int i) {
    T res = 0;
    for (++i; i>0; i-=(i&-i))
      res += dat[i];
    return res;
  }
  T range_sum(int l,int r) { // [l,r)
    return sum(r-1)-sum(l-1);
  }
}; // 0-indexed

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> L(M), X(M);
  vector<pair<int,int>> R(M);
  rep(i,M) {
    int r;
    cin >> L[i] >> r >> X[i];
    R[i] = {r, i};
  }
  sort(all(R));
  BIT<int> sum(N);
  vector<int> res(N);
  vector<int> zero;
  int top = 0;
  rep(i,M) {
    int id = R[i].second;
    int l = L[id], r = R[i].first, x = X[id] - sum.range_sum(--l, r);
    for (; top<r; top++)
      zero.push_back(top);
    for (; x>0; x--) {
      int last = zero.back();
      zero.pop_back();
      res[last] = 1;
      sum.add(last, 1);
    }
  }
  rep(i,N) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
