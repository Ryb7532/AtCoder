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
  vector<int> A(N), B(N), C(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,N) {
    cin >> B[i];
  }
  rep(i,N) {
    cin >> C[i];
  }
  sort(all(A));
  sort(all(B));
  sort(all(C));
  vector<ll> AB(N+1);
  AB[0] = 0;
  int i=0, j=0;
  ll res = 0;
  while (i<N) {
    while (j<N && A[j]<B[i])
      j++;
    AB[i+1] = j + AB[i];
    i++;
  }
  i=0; j=0;
  while (i<N) {
    while (j<N && B[j]<C[i])
      j++;
    res += AB[j];
    i++;
  }
  print(res);
  return 0;
}
