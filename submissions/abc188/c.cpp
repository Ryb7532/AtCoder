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
  vec<ll> A(1<<N);
  ll M = 0;
  int argM = 0;
  rep(i,(1<<N)) {
    cin >> A[i];
    if (A[i] > M) {
      M = A[i];
      argM = i;
    }
  }
  int s=0;
  if (argM < (1<<(N-1))) {
    s = (1<<(N-1));
  }
  M = 0;
  argM = 0;
  rep(i,(1<<(N-1))) {
    if (A[i+s] > M) {
      M = A[i+s];
      argM = i+s;
    }
  }
  print(argM+1);
  return 0;
}
