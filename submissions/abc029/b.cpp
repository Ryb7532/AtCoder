#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  string S;
  int ans = 0;
  rep(i, 12) {
    cin >> S;
    int n = S.size();
    rep(j, n) {
      if (S[j] == 'r') {
        ans++;
        break;
      }
    }
  }
  print(ans);
  return 0;
}
