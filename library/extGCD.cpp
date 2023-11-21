#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Task: Compute GCD(a,b)(=g) and a particular solution of a * x + b * y = g
// Extended Euclidean Algorithm
struct GCD {
  ll x,y,g;

  void solve(ll a, ll b) {
    if (b == 0) {
      x = 1, y = 0;
      g = a;
      return ;
    }
    solve(b, a%b);
    swap(x,y);
    y -= a/b*x;
  }

  GCD(ll a=0, ll b=0) { solve(a,b); }
}
