#include <bits/stdc++.h>
using namespace std;


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


template <typename T>
bool isPrime(T n) {
  if (n == 1) return false;
  for (int i=2; i<sqrt((double)n)+0.1; i++) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}
