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
  vec<int> A(N),B(M);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,M) {
    cin >> B[i];
  }
  sort(all(A));
  sort(all(B));
  int i=0,j=0,res=1e9;
  while (i<N) {
    while (j<M && B[j]<A[i]) {
      j++;
    }
    if (j<M)
      res = min(res,abs(A[i]-B[j]));
    if (j>0)
      res = min(res,abs(A[i]-B[j-1]));
    i++;
  }
  print(res);
  return 0;
}
