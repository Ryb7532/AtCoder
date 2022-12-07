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
  vec<ll> A(N), B(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
    B[i] += A[i];
  }
  sort(all(A));
  sort(all(B));
  vec<ll> D(N+1,0);
  int a=0,b=0;
  int player = 0;
  int d = 0;
  while (a!=N || b!=N) {
    if (a==N || B[b] <= A[a]) {
      D[player--] += B[b]-d;
      d = B[b++];
    } else {
      D[player++] += A[a]-d;
      d = A[a++];
    }
  }
  stringstream out;
  for (int i=1; i<=N; i++) {
    out << D[i] << ' ';
  }
  string res = out.str();
  res.pop_back();
  print(res);
  return 0;
}
