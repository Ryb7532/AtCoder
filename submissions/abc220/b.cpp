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
  int K;
  string A, B;
  cin >> K >> A >> B;
  int sa = A.size(), sb = B.size();
  ll a=0,b=0;
  rep(i,sa) {
    a *= K;
    a += A[i]-'0';
  }
  rep(i,sb) {
    b *= K;
    b += B[i]-'0';
  }
  print(a*b);
  return 0;
}
