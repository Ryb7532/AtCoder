#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
const int N = 200000;

template<typename T>
struct BinaryIndexed {
  int n;
  vector<T> dat;
  BinaryIndexed(int n) : n(n), dat(n+1, 0) {}
  void add(int i, T x) {
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
  int Q;
  cin >> Q;
  BinaryIndexed<int> bit(N+1);
  rep(i,Q) {
    int T,X;
    cin >> T >> X;
    if (T==1) {
      bit.add(X,1);
    } else {
      int l=0,r=N;
      while (r-l>1) {
        int mid = (r+l)/2;
        if (bit.sum(mid)<X)
          l = mid;
        else
          r = mid;
      }
      print(r);
      bit.add(r,-1);
    }
  }
  return 0;
}
