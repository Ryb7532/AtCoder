#include <iostream>
using namespace std;

//GCD
long gcd(long a, long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  long t[n];
  for (int i=0; i<n; i++)
    cin >> t[i];
  long ans = t[0];
  for (int i=1; i<n; i++) {
    long g = gcd(ans, t[i]);
    ans = ans/g * t[i];
  }
  cout << ans;
  return 0;
}
