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
  T range_sum(int l,int r) { //[l,r)
    return sum(r-1)-sum(l-1);
  }
};


int main() {
  int N;
  cin >> N;
  vector<pair<int,int>> A(N), B(N);
  vector<int> p(N);
  rep(i,N) {
    int a;
    cin >> a;
    A[i] = {a+i, i};
  }
  rep(i,N) {
    int b;
    cin >> b;
    B[i] = {b+i, i};
  }
  sort(all(A));
  sort(all(B));
  rep(i,N) {
    if (A[i].first != B[i].first) {
      print(-1);
      return 0;
    }
    p[A[i].second] = B[i].second;
  }
  BIT<int> bit(N);
  ll res = 0;
  rep(i,N) {
    res += bit.range_sum(p[i],N);
    bit.add(p[i],1);
  }
  print(res);
  return 0;
}
