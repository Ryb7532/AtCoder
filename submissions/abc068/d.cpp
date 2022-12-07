#include <bits/stdc++.h>
using namespace std;

int main() {
  long long K;
  cin >> K;
  long long n = 50, m = K/n, l = K%n, a[n];
  for (int i=0; i<n; i++) {
    a[i] = i+m;
    if (i<l)
      a[i] += n-l+1;
    else
      a[i] -= l;
  }
  cout << n << endl;
  for (int i=0; i<n; i++)
    cout << a[i] << ' ';
  cout << endl;
  return 0;
}