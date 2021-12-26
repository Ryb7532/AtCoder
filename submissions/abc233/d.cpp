#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  map<ll, ll> C;
  ll sum = 0, res = 0;
  C[0] = 1;
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
    try {
      C.at(sum);
    } catch(out_of_range&) {
      C[sum] = 0;
    }
    C[sum]++;
  }
  sum = 0;
  rep(i,N) {
    C[sum]--;
    try {
      res += C.at(sum + K);
    } catch(out_of_range&) {
    }
    sum += A[i];
  }
  print(res);
  return 0;
}
