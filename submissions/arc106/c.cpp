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
  int N,M;
  cin >> N >> M;
  if (M==N || M<0 || (N>=2 && M==N-1)) {
    print(-1);
    return 0;
  }
  print(1 << " " << 2*N);
  rep(i,M) {
    print(2*i+2 << " " << 2*i+3);
  }
  rep(i,N-M-1) {
    print(2*M+2+i << " " << 2*N-1-i);
  }
  return 0;
}
