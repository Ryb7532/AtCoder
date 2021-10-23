#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N, M;
  cin >> N >> M;
  map<int, int> lcm;
  rep(i,N) {
    int A;
    cin >> A;
    for (int p=2; p<=sqrtl((double)A)+1e-5; p++) {
      if (A % p)
        continue;
      int c=0;
      while (A%p == 0) {
        c++;
        A /= p;
      }
      lcm[p] = max(lcm[p], c);
    }
    if (A != 1)
      lcm[A] = max(lcm[A], 1);
  }
  vec<bool> coprime(M+1, true);
  for (auto e: lcm) {
    for (int i=e.first; i<=M; i+=e.first) {
      coprime[i] = false;
    }
  }
  vec<int> res;
  for (int i=1; i<=M; i++) {
    if (coprime[i])
      res.push_back(i);
  }
  print(res.size());
  for (int e: res) {
    print(e);
  }
  return 0;
}
