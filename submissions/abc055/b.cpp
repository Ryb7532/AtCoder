#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  int N;
  cin >> N;
  long ans = 1;
  while (N != 0) {
    ans *= N;
    ans %= MOD;
    N--;
  }
  cout << ans << endl;
  return 0;
}
