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
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

// Prime Factorization
template <typename T>
struct PrimeFact {
  vector<T> spf;
  PrimeFact(T N) { init(N); }

  // preprocess
  void init(T N) {
    spf.assign(N + 1, 0);
    for (T i = 0; i <= N; i++)
      spf[i] = i;
    for (T i = 2; i * i <= N; i++)
      if (spf[i] == i)
        for (T j = i * i; j <= N; j += i)
          if (spf[j] == j)
            spf[j] = i;
  }

  // calc prime factorization
  map<T, T> get(T n) {
    map<T, T> m;
    while (n != 1) {
      m[spf[n]]++;
      n /= spf[n];
    }
    return m;
  }

  // calc number of divisor
  T cntDivisor(T n) {
    T p = 0, cnt = 0, res = 1;
    while (n != 1) {
      if (p == spf[n])
        cnt++;
      else {
        res *= cnt+1;
        p = spf[n];
        cnt = 1;
      }
      n /= spf[n];
    }
    res *= cnt+1;
    return res;
  }
};


int main() {
  int N;
  cin >> N;
  PrimeFact<int> prime(2e5+5);
  vector<vector<int>> A;
  ll zero = 0;
  rep(i,N) {
    int a;
    cin >> a;
    if (a == 0) {
      zero++;
      continue;
    }
    auto fact = prime.get(a);
    vector<int> F;
    for (auto p: fact) {
      auto [n, m] = p;
      if (m%2)
        F.push_back(n);
    }
    A.push_back(F);
  }
  sort(all(A));
  A.push_back(vector<int>(1,0));
  ll res = zero*(zero-1)/2;
  ll c = 1;
  rep(i,A.size()-1) {
    if (A[i] != A[i+1]) {
      res += c*(c-1)/2;
      res += zero * c;
      c = 0;
    }
    c++;
  }
  print(res);
  return 0;
}