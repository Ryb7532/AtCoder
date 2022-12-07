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
  vec<string> S(3);
  rep(i,3) {
    cin >> S[i];
  }
  string T;
  cin >> T;
  int t = T.size();
  rep(i,t) {
    cout << S[T[i]-'1'];
  }
  cout << endl;
  return 0;
}
