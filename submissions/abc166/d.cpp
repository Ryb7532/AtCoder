#include <bits/stdc++.h>
using namespace std;

int main() {
  long X;
  cin >> X;
  long A, B;
  for (A=0; A<=120; A++) {
    long A5 = A*A*A*A*A;
    for (B=-80; B<A; B++) {
      if (A5-B*B*B*B*B == X) {
        cout << A << ' ' << B << endl;
        return 0;
      }
    }
  }
  return 0;
}
