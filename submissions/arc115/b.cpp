#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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
  vector<vector<ll>> C(N, vector<ll>(N));
  vector<ll> A(N), B(N);
  rep(i,N) {
    rep(j,N) {
      cin >> C[i][j];
    }
  }
  A[0] = C[0][0];
  ll minA = A[0], minB = 0, k;
  rep(j,N) {
    B[j] = C[0][j] - A[0];
    minB = min(minB, B[j]);
  }
  rep(i,N-1) {
    A[i+1] = C[i+1][0];
    minA = min(minA, A[i+1]);
    rep(j,N) {
      if (C[i+1][j] != A[i+1]+B[j]) {
        print(No);
        return 0;
      }
    }
  }
  if (minB < 0 && -minB > minA) {
    print(No);
    return 0;
  }
  k = max((ll)0, -minB);
  print(Yes);
  cout << A[0]-k;
  rep(i,N-1) {
    cout << " " << A[i+1]-k;
  }
  cout << endl;
  cout << B[0]+k;
  rep(i,N-1) {
    cout << " " << B[i+1]+k;
  }
  cout << endl;
  return 0;
}
