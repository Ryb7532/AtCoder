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
  vec<int> A(N), B(N), C(N);
  vec<int> cnt(N+1,0);
  rep(i,N)
    cin >> A[i];
  rep(i,N)
    cin >> B[i];
  rep(i,N) {
    cin >> C[i];
    cnt[B[--C[i]]]++;
  }
  ll res = 0;
  for (int e: A) {
    res += cnt[e];
  }
  print(res);
  return 0;
}
