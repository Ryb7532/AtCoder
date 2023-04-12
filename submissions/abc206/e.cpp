#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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


int main() {
  int L,R;
  cin >> L >> R;
  if (L == 1)
    L++;
  PrimeFact<ll> pf(1e6+5);
  vector<bool> notHaveSamePrime(1e6+5, true);
  ll res = 0;
  for (int i=2; i<=R; i++) {
    ll n = i;
    ll p = 0;
    ll pcnt = 0;
    while (n != 1) {
      if (!notHaveSamePrime[n] || p == pf.spf[n]) {
        notHaveSamePrime[i] = false;
        break;
      }
      p = pf.spf[n];
      n /= p;
      pcnt++;
    }
    if (!notHaveSamePrime[i])
      continue;
    ll cnt = R/i - (L-1)/i;
    if (pcnt%2)
      res += cnt*(cnt-1)/2;
    else
      res -= cnt*(cnt-1)/2;
  }
  for (int i=L; i<=R; i++) {
    res -= R/i-1;
  }
  print(res*2);
  return 0;
}
