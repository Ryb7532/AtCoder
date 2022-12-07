#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  if ((A-1)/D<(C-1)/B)
    cout << "No\n";
  else
    cout << "Yes\n";
  return 0;
}
