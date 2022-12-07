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
  string S,T;
  cin >> S >> T;
  int n = S.size();
  int mis = 0;
  rep(i,n) {
    mis += S[i]!=T[i];
  }
  if (mis != 2 && mis != 0) {
    print(No);
    return 0;
  }
  rep(i,n-1) {
    if (S[i]!=T[i]) {
      if (S[i]!=T[i+1] || S[i+1]!=T[i]) {
        print(No);
        return 0;
      }
      i++;
    }
  }
  print(Yes);
  return 0;
}
