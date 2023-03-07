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
  map<int,vector<int>> same_color;
  vector<int> C(N);
  vector<int> X(N);
  rep(i,N) {
    cin >> C[i];
  }
  rep(i,N) {
    cin >> X[i];
    if (same_color.find(C[i]) == same_color.end())
      same_color[C[i]] = vector<int>();
    same_color[C[i]].push_back(X[i]);
  }
  ll res = 0;
  BIT<int> bit(N+1);
  rep(i,N) {
    res += bit.range_sum(X[i]+1, N+1);
    bit.add(X[i], 1);
  }
  rep(i,N) {
    bit.add(X[i], -1);
  }
  for (auto e: same_color) {
    auto v = e.second;
    int size = v.size();
    if (size <= 1)
      continue;
    for (auto x: v) {
      res -= bit.range_sum(x+1, N+1);
      bit.add(x, 1);
    }
    for (auto x: v) {
      bit.add(x, -1);
    }
  }
  print(res);
  return 0;
}
