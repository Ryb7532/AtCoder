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
  int N;
  cin >> N;
  vec<ll> A(N);
  rep(i,N) {
    cin >> A[i];
    A[i] = A[i]%200;
  }
  int n = min(N,8);
  vec<vec<int>> res(200);
  for (int i=1; i<(1<<n); i++) {
    vec<int> v;
    int sum = 0;
    rep(j,n) {
      if (i&(1<<j)) {
        v.push_back(j+1);
        sum += A[j];
        sum %= 200;
      }
    }
    if (res[sum].size()>0) {
      print(Yes);
      cout << res[sum].size();
      for (auto &e: res[sum]) {
        cout << " " << e;
      }
      cout << endl;
      cout << v.size();
      for (auto &e: v) {
        cout << " " << e;
      }
      cout << endl;
      return 0;
    }
    for (auto &e: v)
      res[sum].push_back(e);
  }
  print(No);
  return 0;
}
