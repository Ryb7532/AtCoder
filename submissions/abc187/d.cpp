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
  ll sub = 0,A,B;
  vec<ll> sum(N);
  rep(i,N) {
    cin >> A >> B;
    sub += A;
    sum[i] = B+2*A;
  }
  sort(rall(sum));
  int i=0;
  while (sub>=0) {
    sub -= sum[i];
    i++;
  }
  print(i);
  return 0;
}
