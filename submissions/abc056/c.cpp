#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, i;
  cin >> X;
  for (i=1; X>0; i++)
    X -= i;
  cout << i-1 << endl;
  return 0;
}