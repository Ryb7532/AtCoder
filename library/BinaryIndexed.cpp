#include <bits/stdc++.h>
using namespace std;

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

