#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

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
    T res = T(0);
    for (++i; i>0; i-=(i&-i))
      res += dat[i];
    return res;
  }
  T range_sum(int l,int r) { // [l,r)
    return sum(r-1)-sum(l-1);
  }
}; // 0-indexed

struct cntsum {
  ll sum;
  int cnt;

  cntsum(ll a=0): sum(a), cnt(0) {}
  cntsum(ll a, int b) : sum(a), cnt(b) {}

  cntsum &operator+=(const cntsum &a) {
    sum += a.sum;
    cnt += a.cnt;
    return *this;
  }

  cntsum operator-(const cntsum &a) const {
    cntsum res(*this);
    res.sum -= a.sum;
    res.cnt -= a.cnt;
    return res;
  }
};


int main() {
  int N;
  cin >> N;
  vector<vector<pair<ll,ll>>> P(2);
  rep(N) {
    ll X,Y;
    cin >> X >> Y;
    P[(X+Y)%2].push_back({X-Y,X+Y});
  }
  ll res = 0;
  fore(v,P) {
    int n = v.size();
    vector<ll> T(n);
    rep(i,n) {
      T[i] = v[i].second;
    }
    sort(all(T));
    T.erase(unique(all(T)), T.end());
    int m = T.size();
    sort(all(v));
    map<ll,int> id;
    rep(i,m) {
      id[T[i]] = i;
    }
    BIT<cntsum> bit(m);
    ll ssum = 0;
    rep(i,n) {
      auto [s,t] = v[i];
      res += s*i;
      res -= ssum;
      cntsum l = bit.sum(id[t]), r = bit.range_sum(id[t], m);
      res += t*l.cnt;
      res -= l.sum;
      res -= t*r.cnt;
      res += r.sum;
      bit.add(id[t], cntsum(t, 1));
      ssum += s;
    }
  }
  print(res/2);
  return 0;
}