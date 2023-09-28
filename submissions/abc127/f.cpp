#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int Q;
  cin >> Q;
  priority_queue<ll> A0;
  priority_queue<ll, vector<ll>, greater<ll>> A1;
  ll sumA0 = 0, sumA1 = 0,B = 0;
  auto f = [&]() {
    ll v = B;
    ll x = A0.top();
    v += x * A0.size() - sumA0;
    v += sumA1 - x * A1.size();
    return make_pair(x, v);
  };
  auto update = [&](ll a) {
    if (A0.size() == A1.size()) {
      A0.push(a);
      sumA0 += a;
    } else {
      A1.push(a);
      sumA1 += a;
    }
    while (!A0.empty() && !A1.empty() && A0.top() > A1.top()) {
      ll a0 = A0.top(), a1 = A1.top();
      A0.pop();
      A0.push(a1);
      A1.pop();
      A1.push(a0);
      sumA0 += a1 - a0;
      sumA1 += a0 - a1;
    }
  };
  rep(_,Q) {
    int t;
    cin >> t;
    if (t == 1) {
      ll a,b;
      cin >> a >> b;
      B += b;
      update(a);
    } else {
      auto [x,v] = f();
      print(x << " " << v);
    }
  }
  return 0;
}