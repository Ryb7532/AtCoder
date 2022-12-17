#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vector<long> A(N);
  long M = 0, res = 0;
  map<long, long> cnt;
  rep(i,N) {
    cin >> A[i];
    M = max(M, A[i]);
    cnt[A[i]]++;
  }
  for (long j=1; j<=M; j++) {
    for (long k=1; k<=M/j; k++) {
      res += cnt[j]*cnt[k]*cnt[j*k];
    }
  }
  print(res);
  return 0;
}
