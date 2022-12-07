#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  if ((A-1)/K == B/K)
    cout << "NG\n";
  else
    cout << "OK\n";
  return 0;
}
