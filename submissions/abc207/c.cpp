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
  vec<vec<int>> A(N, vec<int>(3));
  int res = 0;
  rep(i,N) {
    rep(j,3) {
      cin >> A[i][j];
    }
  }
  for (int i=0; i<N-1; i++) {
    for (int j=i+1; j<N; j++) {
      if (A[i][1] > A[j][2] || A[j][1] > A[i][2])
        continue;
      if ((A[i][1]<A[j][2] && A[j][1]<A[i][2]) || (A[j][1]<A[i][2] && A[i][1]<A[j][2]))
        res++;
      else if (A[i][1] == A[j][2] && (A[i][0]==1 || A[i][0]==2) && (A[j][0]==1 || A[j][0]==3))
        res++;
      else if (A[i][2] == A[j][1] && (A[i][0]==1 || A[i][0]==3) && (A[j][0]==1 || A[j][0]==2))
        res++;
    }
  }
  print(res);
  return 0;
}
