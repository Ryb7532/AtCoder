#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A == B)
    cout << "Draw\n";
  else if (A < B) {
    if (A == 1)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  } else {
    if (B == 1)
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
  return 0;
}
