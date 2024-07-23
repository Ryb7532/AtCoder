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
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << ((f) ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N), C(1e6+5,0);
  rep(i,N) {
    cin >> A[i];
    C[A[i]]++;
  }
  sort(all(A));
  ll M = A.back();
  C.resize(M+1);
  rep(i,M) {
    C[i+1] += C[i];
  }
  ll res = 0;
  map<int, ll> memo;
  rep(i,N) {
    int m = A[i];
    if (memo.find(m) != memo.end()) {
      memo[m]--;
      res += memo[m];
      continue;
    }
    int l = i+1;
    ll tmp = 0;
    while (l < N) {
      ll k = A[l]/m;
      tmp += k * (C[min((k+1)*m-1,M)] - l);
      l = C[min((k+1)*m-1,M)];
    }
    memo[m] = tmp;
    res += tmp;
  }
  print(res);
  return 0;
}