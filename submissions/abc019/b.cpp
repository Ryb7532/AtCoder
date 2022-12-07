#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

int main() {
  string S;
  cin >> S;
  char p = S[0];
  int cnt = 1, n = S.size();
  rep1(i, n-1) {
    if (S[i] != p) {
      cout << p << cnt;
      p = S[i];
      cnt = 0;
    }
    cnt++;
  }
  cout << p << cnt << endl;
  return 0;
}
