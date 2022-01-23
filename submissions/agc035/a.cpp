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
  int N;
  cin >> N;
  vector<int> A(N);
  bool allzero = true;
  rep(i,N) {
    cin >> A[i];
    if (A[i]!=0)
      allzero = false;
  }
  if (allzero) {
    print(Yes);
    return 0;
  }
  if (N%3!=0) {
    print(No);
    return 0;
  }
  sort(all(A));
  int B[3];
  int M = N/3;
  rep(i,3) {
    B[i] = A[i*M];
    rep(j,M) {
      if (A[i*M+j]!=B[i]) {
        print(No);
        return 0;
      }
    }
  }
  print(((B[0]^B[1]^B[2])==0 ? Yes : No));
  return 0;
}
