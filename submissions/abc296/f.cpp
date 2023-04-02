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
  int N;
  cin >> N;
  vector<int> A(N), B(N), cntA(N+1,0), cntB(N+1,0);
  rep(i,N) {
    cin >> A[i];
    cntA[A[i]]++;
  }
  rep(i,N) {
    cin >> B[i];
    cntB[B[i]]++;
  }
  int cntMax = 0;
  rep(i,N+1) {
    if (cntA[i] != cntB[i]) {
      printyesno(false);
      return 0;
    }
    cntMax = max(cntMax, cntA[i]);
  }
  if (cntMax > 1) {
    printyesno(true);
    return 0;
  }
  BIT<int> invA(N+1), invB(N+1);
  int inv = 0;
  rep(i,N) {
    inv += invA.range_sum(A[i], N+1);
    inv += invB.range_sum(B[i], N+1);
    invA.add(A[i], 1);
    invB.add(B[i], 1);
  }
  printyesno(inv%2 == 0);
  return 0;
}
