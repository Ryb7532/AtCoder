#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  for (int i=(int)sqrt((double)N)+1; i>0; i--) {
    if (N%i == 0) {
      long l = N/i;
      int ans = 0;
      while (l != 0) {
        ans++;
        l /= 10;
      }
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
}
