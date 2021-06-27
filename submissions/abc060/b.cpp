#include <bits/stdc++.h>
using namespace std;

//GCD
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int g = gcd(A, B);
  if (C%g == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
