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
  int P;
  if (N%2) {
    print((N-1)*(N-1)/2);
    P=N;
  } else {
    print(N*(N-2)/2);
    P=N+1;
  }
  for (int i=1; i<=N; i++) {
    for (int j=i+1; j<=N; j++) {
      if (i+j == P)
        continue;
      print(i << ' ' << j);
    }
  }
  return 0;
}
