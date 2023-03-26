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
  ll N,M;
  cin >> N >> M;
  ll sum = 0;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
  }
  sort(all(A));
  int p = -2;
  vector<int> start;
  rep(i,N) {
    if (A[i] != p && A[i] != p+1)
      start.push_back(i);
    p = A[i];
  }
  ll res = sum;
  for (int s: start) {
    int i = s;
    ll subsum = A[i];
    while (A[(i+1)%N] == A[i] || A[(i+1)%N] == (A[i]+1)%M) {
      i++;
      i %= N;
      if (i == s)
        break;
      subsum += A[i];
    }
    res = min(res, sum-subsum);
  }
  print(res);
  return 0;
}
