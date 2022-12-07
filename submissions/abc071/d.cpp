#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  char s[2][n+5];
  cin >> s[0] >> s[1];
  long ans;
  int i;
  bool one;
  if (s[0][0] == s[1][0]) {
    ans = 3;
    one = true;
    i = 1;
  }
  else {
    ans = 6;
    one = false;
    i = 2;
  }
  for (; i<n; i++) {
    if (one) {
      if (s[0][i] == s[1][i]) {
        ans *= 2;
        ans %= MOD;
        one = true;
      } else {
        ans *= 2;
        ans %= MOD;
        one = false;
        i++;
      }
    } else {
      if (s[0][i] == s[1][i])
        one = true;
      else {
        ans *= 3;
        ans %= MOD;
        one = false;
        i++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}