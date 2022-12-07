#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  string S, T;
  cin >> S >> T;
  int n = S.size();
  bool ans = true;
  rep(i, n) {
    if (S[i] == '@') {
      if (T[i] == 'a' || T[i] == 't' || T[i] == 'c' || T[i] == 'o' || T[i] == 'd' || T[i] == 'e' || T[i] == 'r' || T[i] == '@')
        continue;
      else
        ans = false;
    } else if (T[i] == '@') {
      if (S[i] == 'a' || S[i] == 't' || S[i] == 'c' || S[i] == 'o' || S[i] == 'd' || S[i] == 'e' || S[i] == 'r' || S[i] == '@')
        continue;
      else
        ans = false;
    } else {
      if (S[i] != T[i])
        ans = false;
    }
  }
  print((ans)?"You can win":"You will lose");
  return 0;
}
