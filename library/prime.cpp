#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()

template <typename T>
struct PrimeFact {
  vector<T> spf;
  PrimeFact(T N) { init(N); }
  void init(T N) { // preprocess
    spf.assign(N + 1, 0);
    for (T i = 0; i <= N; i++)
      spf[i] = i;
    for (T i = 2; i * i <= N; i++)
      if (spf[i] == i)
        for (T j = i * i; j <= N; j += i)
          if (spf[j] == j)
            spf[j] = i;
  }
  map<T, T> get(T n) { // calc prime factorization
    map<T, T> m;
    while (n != 1) {
      m[spf[n]]++;
      n /= spf[n];
    }
    return m;
  }
  T cntDivisor(T n) { // calc number of divisor
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


bool isPrime(ll n) {
  if (n == 1) return false;
  for (ll i=2; i*i<=n; i++) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}

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
}
