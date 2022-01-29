#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
  int T;
  cin >> T;
  rep(_,T) {
    int N;
    cin >> N;
    vector<bool> pattern(4,false);
    rep(i,3) {
      string S;
      cin >> S;
      int p = 0;
      if (S[0]=='1')
        p += 2;
      if (S[2*N-1]==S[0])
        p++;
      pattern[p] = true;
    }
    rep(i,4) {
      if (pattern[i])
        continue;
      int n = i/2;
      rep(j,N) {
        cout << n;
      }
      if (i%2) {
        cout << 1-n;
      } else {
        n = 1-n;
      }
      rep(j,N) {
        cout << n;
      }
      if (i%2==0) {
        cout << 1-n;
      }
      cout << endl;
      break;
    }
  }
  return 0;
}
