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
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

int main() {
  int N,K;
  scan(N,K);
  vector<ll> A(N);
  fore(a,A) {
    scan(a);
  }
  const int INF = 1e9;
  ll lower = 0, upper = 1e10;
  int cnt;
  vector<int> B(2*N+1,INF), C(N);
  while (upper - lower > 1) {
    ll w = (lower + upper) / 2;
    rep(i,N) {
      C[i] = i;
    }
    int l = 0, r = 0;
    ll sum = 0;
    int c = N;
    while (l < 2*N) {
      while (sum < w && r < 2*N) {
        sum += A[r%N];
        r++;
      }
      if (sum >= w && r <= 2*N)
        B[l] = r;
      else
        B[l] = INF;
      sum -= A[l%N];
      l++;
    }
    int k = K;
    while (k > 0) {
      if (k & 1) {
        rep(i,N) {
          if (C[i] <= 2*N)
            C[i] = B[C[i]];
          else
            C[i] = INF;
        }
      }
      rep(i,2*N) {
        if (B[i] <= 2*N && B[B[i]] <= 2*N)
          B[i] = B[B[i]];
        else
          B[i] = INF;
      }
      k >>= 1;
    }
    bool flag = false;
    rep(i,N) {
      if (C[i] <= N + i) {
        flag = true;
        c--;
      }
    }
    if (flag) {
      lower = w;
      cnt = c;
    } else
      upper = w;
  }
  assert(lower != 0);
  print(lower, cnt);
  return 0;
}