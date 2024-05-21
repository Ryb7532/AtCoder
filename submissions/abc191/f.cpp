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
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

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
};

// Enumeration of divisors
vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i=1; i*i<=n; i++) {
    if (n%i != 0) {
      continue;
    }
    res.push_back(i);
    if (i*i != n)
      res.push_back(n/i);
  }
  sort(all(res));
  return res;
}

int main() {
  int N;
  cin >> N;
  map<int,int> cand;
  int m = 1e9;
  rep(i,N) {
    int a;
    cin >> a;
    chmin(m,a);
    auto divs = divisor(a);
    fore(d,divs) {
      if (cand.find(d) == cand.end())
        cand[d] = a;
      cand[d] = GCD(cand[d],a).g;
    }
  }
  int res = 0;
  fore(p,cand) {
    if (p.first > m)
      break;
    if (p.first == p.second)
      res++;
  }
  print(res);
  return 0;
}