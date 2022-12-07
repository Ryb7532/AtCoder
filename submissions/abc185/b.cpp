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
  ll N,M,T,R,t=0;
  cin >> N >> M >> T;
  R = N;
  ll A,B;
  rep(i,M) {
    cin >> A >> B;
    R -= A-t;
    if (R<=0) {
      print(No);
      return 0;
    }
    R += B-A;
    R = min(R,N);
    t = B;
  }
  if (R-(T-t) <= 0) {
    print(No);
    return 0;
  }
  print(Yes);
  return 0;
}
