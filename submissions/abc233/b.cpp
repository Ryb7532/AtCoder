#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int L,R,N;
  string S;
  cin >> L >> R >> S;
  N = S.size();
  L--; R--;
  rep(i,L) {
    cout << S[i];
  }
  for (int i=R; i>=L; i--) {
    cout << S[i];
  }
  rep(i,N-R-1) {
    cout << S[i+R+1];
  }
  cout << endl;
  return 0;
}
