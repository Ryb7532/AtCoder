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
  vec<int> A(N);
  rep(i,N)
    cin >> A[i];
  int res, cnt=0;
  for (int i=2; i<=1000; i++) {
    int tmp = 0;
    rep(j,N) {
      tmp += (A[j]%i == 0);
    }
    if (tmp > cnt) {
      res = i;
      cnt = tmp;
    }
  }
  print(res);
  return 0;
}
