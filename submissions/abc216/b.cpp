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
  vec<string> S(N), T(N);
  rep(i,N) {
    cin >> S[i] >> T[i];
  }
  rep(i,N) {
    rep(j,N) {
      if (i==j)
        continue;
      if (S[i]==S[j] && T[i]==T[j]) {
        print(Yes);
        return 0;
      }
    }
  }
  print(No);
  return 0;
}
