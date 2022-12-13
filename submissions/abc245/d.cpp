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
  vector<long> A(N+1), B(M+1,0), C(N+M+1);
  rep(i,N+1) {
    cin >> A[i];
  }
  rep(i,N+M+1) {
    cin >> C[i];
  }
  for (int i=M; i>=0; i--) {
    int sum = 0;
    for (int j=i+1; j<=M; j++) {
      if (N+i-j<0 || N+i-j>N)
        continue;
      sum += B[j]*A[N+i-j];
    }
    B[i] = (C[N+i]-sum)/A[N];
  }
  cout << B[0];
  rep(i,M) {
    cout << " " << B[i+1];
  }
  cout << endl;
  return 0;
}
