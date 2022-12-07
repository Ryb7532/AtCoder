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
  string S;
  cin >> S;
  vec<int> X(4);
  rep(i,4) {
    X[i] = S[i]-'0';
  }
  bool weak = false;
  bool flag = true;
  rep(i,3) {
    if (X[i] != X[i+1])
      flag = false;
  }
  if (flag)
    weak = true;
  flag = true;
  rep(i,3) {
    if (X[i+1] != (X[i]+1)%10)
      flag = false;
  }
  if (flag)
    weak = true;
  if (weak)
    print("Weak");
  else
    print("Strong");
  return 0;
}
