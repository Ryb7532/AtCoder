#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, N;
  cin >> A >> B >> N;
  long n = A/B, m = A%B, l = min(N, B-1);
  cout << (m*l)/B + n*l << endl;
  return 0;
}
