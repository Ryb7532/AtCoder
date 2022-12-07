#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


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
  string S,T;
  cin >> S >> T;
  int slen = S.size(), tlen = T.size();
  BIT<int> s(slen),t(tlen);
  rep(i,slen) {
    s.add(i,(S[i]=='A')?1:2);
  }
  rep(i,tlen) {
    t.add(i,(T[i]=='A')?1:2);
  }
  int Q;
  cin >> Q;
  rep(i,Q) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--;
    c--; d--;
    print(((s.range_sum(a,b)%3==t.range_sum(c,d)%3)?"YES":"NO"));
  }
  return 0;
}
