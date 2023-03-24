#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  vector<int> A(2*N+2);
  A[1] = 0;
  for (int i=1; i<=N; i++) {
    int a;
    cin >> a;
    int d = A[a]+1;
    A[2*i] = d;
    A[2*i+1] = d;
  }
  rep(i,2*N+1) {
    print(A[i+1]);
  }
  return 0;
}
