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
  vector<int> A(N+1);
  ll sum = 0;
  ll res = 0;
  rep(i,N) {
    cin >> A[i];
  }
  A[N] = 0;
  rep(i,N+1) {
    if (A[i] == 0) {
      res += sum/2;
      sum = 0;
    }
    sum += A[i];
  }
  print(res);
  return 0;
}
