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
  int k = 1e9;
  vec<int> A(M+2);
  A[0] = 0;
  A[M+1] = N+1;
  for (int i=1; i<=M; i++)
    cin >> A[i];
  sort(all(A));
  for (int i=0; i<M+1; i++) {
    if (A[i+1]-A[i]-1 != 0)
      k = min(k, A[i+1]-A[i]-1);
  }
  int cnt = 0;
  for (int i=0; i<M+1; i++) {
    cnt += (A[i+1]-A[i]+k-2)/k;
  }
  print(cnt);
  return 0;
}
