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
  vector<int> A(N),B(N),C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];
  int a=0,b=0,c=0;
  int res = 0;
  sort(all(A));
  sort(all(B));
  sort(all(C));
  while (a<N && b<N && c<N) {
    while (b<N && A[a]>=B[b]) {
      b++;
    }
    while (c<N && B[b]>=C[c]) {
      c++;
    }
    if (b<N && c<N) {
      res++;
      a++;
      b++;
      c++;
    }
  }
  print(res);
  return 0;
}
