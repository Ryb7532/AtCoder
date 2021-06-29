#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
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
  T range_sum(int l,int r) { //[l,r]
    return sum(r)-sum(l-1);
  }
};


int main() {
  int N;
  cin >> N;
  vec<int> A(N);
  BIT<int> bit(N);
  ll res = 0;
  rep(i,N) {
    cin >> A[i];
    res += bit.range_sum(A[i],N-1);
    bit.add(A[i],1);
  }
  rep(k,N) {
    print(res);
    res += N-1-2*A[k];
  }
  return 0;
}
