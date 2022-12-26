#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Task: Compute a particular solution of a * x + b * y = 1
// Extended Euclidean Algorithm
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if (b==0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b*x;
  return d;
}
