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
  int N,Q;
  cin >> N >> Q;
  const int M = 1e6+5;
  vector<int> A(N);
  PrimeFact<int> PF(M);
  rep(i,N) {
    cin >> A[i];
  }
  random_device seed_gen;
  mt19937_64 engine(seed_gen());
  vector<vector<uint64_t>> hs(M, vector<uint64_t>(3));
  for (int i=2; i<M; i++) {
    if (PF.cntDivisor(i) == 2) {
      hs[i][1] = engine();
      hs[i][2] = engine();
      hs[i][0] = hs[i][1] ^ hs[i][2];
    }
  }
  vector<int> cnt(M,0);
  vector<uint64_t> S(N+1);
  S[0] = 0;
  rep(i,N) {
    S[i+1] = S[i];
    for (auto e: PF.get(A[i])) {
      int a = e.first, b = e.second;
      rep(j,b) {
        S[i+1] ^= hs[a][(++cnt[a])%3];
      }
    }
  }
  rep(_,Q) {
    int L,R;
    cin >> L >> R;
    L--;
    printyesno((S[R]^S[L]) == 0);
  }
  return 0;
}
