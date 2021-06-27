#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 1;
  while (ans <= N) {
    ans *= 2;
  }
  cout << ans/2 << endl;
  return 0;
}
