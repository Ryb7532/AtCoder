#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
  int N,M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,M) {
    cin >> B[i];
  }
  sort(all(A));
  sort(all(B));
  bool flag = true;
  int j = 0;
  rep(i,M) {
    while (j<N && A[j] < B[i])
      j++;
    if (j>=N || A[j]!=B[i])
      flag = false;
    j++;
  }
  print((flag ? Yes : No));
  return 0;
}
