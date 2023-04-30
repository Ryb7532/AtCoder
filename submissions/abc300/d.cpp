#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


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
PrimeFact P(1e6);

// Determine if a given number is prime.
bool isPrime(ll n) {
  return P.spf[n] == n;
}

int main() {
  ll N;
  cin >> N;
  ll res = 0;
  for (ll a=2; a*a*a*a*a<=N; a++) {
    if (!isPrime(a))
      continue;
    for (ll b=a+1; a*a*b*b*b<=N; b++) {
      if (!isPrime(b))
        continue;
      for (ll c=b+1; a*a*b*c*c<=N; c++) {
        if (isPrime(c))
          res++;
      }
    }
  }
  print(res);
  return 0;
}
