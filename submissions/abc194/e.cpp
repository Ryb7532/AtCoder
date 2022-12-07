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
  vec<int> A(N);
  vec<vec<int>> P(N, vec<int>(1,-1));
  rep(i,N) {
    cin >> A[i];
    P[A[i]].push_back(i);
  }
  rep(i,N) {
    P[i].push_back(N);
  }
  rep(i,N) {
    int len = P[i].size();
    for (int j=1; j<len; j++) {
      if (P[i][j]-P[i][j-1]>M) {
        print(i);
        return 0;
      }
    }
  }
  print(N);
  return 0;
}
