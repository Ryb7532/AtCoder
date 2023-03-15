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
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  vector<ll> P(3);
  cin >> N;
  rep(i,3) {
    cin >> P[i];
  }
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<int>> B(3, vector<int>(N+1,-1));
  rep(i,3) {
    int l = 0, r = 0;
    ll sum = 0;
    while (l < N) {
      while (r < N && sum < P[i]) {
        sum += A[r++];
      }
      if (sum == P[i])
        B[i][l] = r;
      sum -= A[l++];
    }
  }
  rep(i,N) {
    if (B[0][i] == -1)
      continue;
    int r1 = B[0][i];
    if (B[1][r1] == -1)
      continue;
    int r2 = B[1][r1];
    if (B[2][r2] == -1)
      continue;
    print(Yes);
    return 0;
  }
  print(No);
  return 0;
}
