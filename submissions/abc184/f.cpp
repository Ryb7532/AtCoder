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
  int N,H;
  ll T;
  cin >> N >> T;
  H = N/2;
  vec<ll> A(N);
  vec<ll> sum1, sum2;
  rep(i,N) {
    cin >> A[i];
  }
  for (int i=0; i<(1<<H); i++) {
    ll sum = 0;
    for (int j=0; j<H; j++) {
      if (i&(1<<j))
        sum += A[j];
    }
    if (sum > T)
      continue;
    sum1.push_back(sum);
  }
  for (int i=0; i<(1<<(N-H)); i++) {
    ll sum = 0;
    for (int j=0; j<(N-H); j++) {
      if (i&(1<<j))
        sum += A[H+j];
    }
    if (sum > T)
      continue;
    sum2.push_back(sum);
  }
  sort(all(sum1));
  sort(all(sum2));
  int n1 = sum1.size(), j = sum2.size();
  ll ans = 0;
  j--;
  rep(i,n1) {
    while (sum1[i]+sum2[j] > T) {
      j--;
    }
    ans = max(ans, sum1[i]+sum2[j]);
  }
  print(ans);
  return 0;
}
