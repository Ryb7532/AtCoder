#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N;
  string S;
  cin >> N >> S;
  int len = S.size(), m = len/2, ans = -1;
  if (len%2) {
    bool c = true;
    rep(i, m+1) {
      if (i%3 == 0) {
        if (S[m-i] == 'b' && S[m+i] == 'b')
          ans++;
        else
          c = false;
      } else if (i%3 == 1) {
        if (S[m-i] == 'a' && S[m+i] == 'c')
          ans++;
        else
          c = false;
      } else {
        if (S[m-i] == 'c' && S[m+i] == 'a')
          ans++;
        else
          c = false;
      }
    }
    if (c) {
      print(ans);
    } else {
      print(-1);
    }
  } else {
    print(-1);
  }
  return 0;
}
